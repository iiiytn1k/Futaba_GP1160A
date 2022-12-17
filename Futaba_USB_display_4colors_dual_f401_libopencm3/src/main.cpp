/**********************************************************************************************************************************
 * Futaba GP1160AI USB Display Driver                                                                                             *
 * Black pill (STM32F401CxU6) 4-colors Dual Display version                                                                     *
 *                                                                                                                                *
 * MIT License                                                                                                                    *
 *                                                                                                                                *
 * Copyright (c) 2022 iiiytn1k <iiiytn1k@iiiytn1k.ru>                                                                             *
 *                                                                                                                                *
 * Permission is hereby granted, free of charge, to any person obtaining a copy                                                   *
 * of this software and associated documentation files (the "Software"), to deal                                                  *
 * in the Software without restriction, including without limitation the rights                                                   *
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies                                               *
 * of the Software, and to permit persons to whom the Software is furnished to do so,                                             *
 * subject to the following conditions:                                                                                           *
 *                                                                                                                                *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software. *
 *                                                                                                                                *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,                                            *
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.          *
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,                                                    *
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,                                               *
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                          *
 *                                                                                                                                *
 **********************************************************************************************************************************
 *                                                                                                                                *
 * Connection chart:                                                                                                              *
 *                                                                                                                                *
 * PA0   ------>   GCLK                                                                                                           *
 * PA1   ------>   GDATA                                                                                                          *
 * PA2   ------>   GBLK                                                                                                           *
 *                                                                                                                                *
 * PA3   ------>   SBLK1                                                                                                          *
 * PA4   ------>   SBLK2                                                                                                          *
 * PA5   ------>   SCLK                                                                                                           *
 * PA6   ------>   SCS                                                                                                            *
 * PA7   ------>   SDATA                                                                                                          *
 * PA8   ------>   SCS2                                                                                                           *
 *                                                                                                                                *
 **********************************************************************************************************************************/

#include <libopencmsis/core_cm3.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/spi.h>
#include <libopencm3/stm32/dma.h>
#include <libopencm3/stm32/timer.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/usb/usbd.h>
#include <libopencm3/usb/dwc/otg_fs.h>
#include <libopencm3/cm3/scb.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include "./main.h"
#include "./usb_descriptor.h"
#include "./wcid.h"
#include "./splash_screen.h"

#define TNOP1  { __asm__ __volatile__("nop"); }
#define TNOP2  {TNOP1 TNOP1}
#define TNOP4  {TNOP2 TNOP2}
#define DEFAULT_DISPLAY_BRIGHTNESS 250

// USB device instance
static usbd_device *usb_device;

// Buffer for control requests
static uint8_t usbd_control_buffer[256];

volatile uint32_t display_brightness = DEFAULT_DISPLAY_BRIGHTNESS;
volatile uint8_t BKA_toggle_flag = 0;
static const uint8_t offset_seq[3] = {128, 128, 0};
volatile uint8_t buffer_offset = 0;
volatile uint8_t current_grid = 0;
volatile uint8_t offset_index = 0;
volatile uint32_t received_bytes = 0;

void display_grid(uint8_t offset);
static void DMA2_STREAM3_SPI1_TX_setup(void);
static void DMA1_STREAM4_SPI2_TX_setup(void);
static void SPI1_setup(void);
static void SPI2_setup(void);
static void usb_set_config(usbd_device *usbd_dev, uint16_t wValue);
static void usb_data_received(usbd_device *usbd_dev, uint8_t ep);
static enum usbd_request_return_codes host_requests_callback(usbd_device *usbd_dev, struct usb_setup_data *req,
                                                             uint8_t **buf, uint16_t *len, usbd_control_complete_callback *complete);

static void clock_setup(void) {
    rcc_clock_setup_pll(&rcc_hse_25mhz_3v3[RCC_CLOCK_3V3_84MHZ]);
    rcc_periph_clock_enable(RCC_GPIOA);
    rcc_periph_clock_enable(RCC_GPIOB);
    rcc_periph_clock_enable(RCC_OTGFS);
    rcc_periph_clock_enable(RCC_DMA2);
    rcc_periph_clock_enable(RCC_DMA1);
    rcc_periph_clock_enable(RCC_SPI1);
    rcc_periph_clock_enable(RCC_SPI2);
    rcc_periph_clock_enable(RCC_TIM3);
    rcc_periph_clock_enable(RCC_TIM4);
}

static void GPIO_setup(void) {
    // GBLK, GCLK, GDATA, SBLK1, SBLK2
    gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GCLK_PIN | GDATA_PIN | GGLK_PIN | SBLK2_PIN | SBLK1_PIN);

    // USB D-, D+
    gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO11 | GPIO12);
    gpio_set_af(GPIOA, GPIO_AF10, GPIO11 | GPIO12);

    // SPI1 SCK(SCLK), MOSI(SDATA)
    gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO5 | GPIO7);
    gpio_set_af(GPIOA, GPIO_AF5, GPIO5 | GPIO7);

    // SPI2 SCK(SCLK), MOSI(SDATA)
    gpio_mode_setup(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO13 | GPIO15);
    gpio_set_af(GPIOB, GPIO_AF5, GPIO13 | GPIO15);

    // SPI1 CS(SCS)
    gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, SCS_PIN | SCS2_PIN);
}

void usb_init() {
    rcc_periph_reset_pulse(RST_OTGFS);

    // Get unique serial number
    usb_get_serial_number();

    // Create USB device
    usb_device = usbd_init(&otgfs_usb_driver, &usb_device_desc, usb_config_descs,
                           usb_desc_strings, sizeof(usb_desc_strings) / sizeof(usb_desc_strings[0]),
                           usbd_control_buffer, sizeof(usbd_control_buffer));

    // Disable VBUS sensing
    OTG_FS_GCCFG |= OTG_GCCFG_NOVBUSSENS;

    // Set callback for config calls.
    usbd_register_set_config_callback(usb_device, usb_set_config);
    register_wcid_desc(usb_device);

    // Enable USB interrupt
    nvic_set_priority(NVIC_OTG_FS_IRQ, 2<<6);
    nvic_enable_irq(NVIC_OTG_FS_IRQ);
}

// Called when the host connects to the device and selects a configuration
void usb_set_config(usbd_device *usbd_dev, __attribute__((unused)) uint16_t wValue) {
    register_wcid_desc(usbd_dev);
    usbd_ep_setup(usbd_dev, EP_DATA_OUT, USB_ENDPOINT_ATTR_BULK, 64, usb_data_received);
    usbd_register_control_callback(usb_device, USB_REQ_TYPE_VENDOR | USB_REQ_TYPE_INTERFACE, USB_REQ_TYPE_TYPE |
                                               USB_REQ_TYPE_RECIPIENT, host_requests_callback);
}

// Callback for host request (set display brightness; clear screen)
static enum usbd_request_return_codes host_requests_callback(__attribute__((unused)) usbd_device *usbd_dev, struct usb_setup_data *req,
                                                             __attribute__((unused)) uint8_t **buf, __attribute__((unused)) uint16_t *len,
                                                             __attribute__((unused)) usbd_control_complete_callback *complete) {
    // Set display brightness
    if (req->bRequest == 0x44 && req->wIndex == 0) {
        display_brightness = (uint32_t)req->wValue;
        timer_set_period(TIM3, display_brightness);
        return USBD_REQ_HANDLED;
    }

    // Clear display
    if (req->bRequest == 0x50 && req->wIndex == 0) {
        std::fill_n(usb_rx_buffer[0], 8192 * 2, 0);
        received_bytes = 0;
        buffer_offset = 0;
        return USBD_REQ_HANDLED;
    }
    return USBD_REQ_NEXT_CALLBACK;
}

// Called when another packet with bitmap data has been received
void usb_data_received(__attribute__((unused)) usbd_device *usbd_dev, __attribute__((unused)) uint8_t ep) {
    uint8_t packet[64] __attribute__((aligned(4)));
    int len = usbd_ep_read_packet(usb_device, EP_DATA_OUT, packet, sizeof(packet));
    usbd_ep_nak_set(usb_device, EP_DATA_OUT, 1);
    memcpy((uint8_t *)usb_rx_buffer[1>>buffer_offset] + received_bytes, packet, len);
    received_bytes += len;
    if (received_bytes >= 8192) {
        received_bytes = 0;
        buffer_offset ^= 1;
    }
}

// Using TIM3 for control display brightness
static void TIM3_setup(void) {
    nvic_set_priority(NVIC_TIM3_IRQ, 2<<5);
    nvic_enable_irq(NVIC_TIM3_IRQ);
    rcc_periph_reset_pulse(RST_TIM3);
    timer_enable_preload(TIM3);
    timer_set_prescaler(TIM3, 2);
    timer_set_period(TIM3, display_brightness);
    timer_set_oc_value(TIM3, TIM_OC1, 0);

    // Enable TIM3 output compare interrupt.
    timer_enable_irq(TIM3, TIM_DIER_CC1IE);
}

void tim3_isr(void) {
    if (timer_get_flag(TIM3, TIM_SR_CC1IF)) {
        timer_clear_flag(TIM3, TIM_SR_CC1IF);
        timer_disable_counter(TIM3);
        if (display_brightness >= (DEFAULT_DISPLAY_BRIGHTNESS + 125)) {
            SCS_UP;
            SCS2_UP;
        }
        GBLK_UP;
        (BKA_toggle_flag) ? (SBLK2_UP) : (SBLK1_UP);
    }
}

// Using TIM4 for control display refresh rate
static void TIM4_setup(void) {
    nvic_set_priority(NVIC_TIM4_IRQ, 0);
    nvic_enable_irq(NVIC_TIM4_IRQ);
    rcc_periph_reset_pulse(RST_TIM4);
    timer_set_prescaler(TIM4, 0);

    // Timer period = FCLK/(refresh rate)/(128 grids)/(3 color frames) + 1
    // 90Hz refresh rate
    // 84000000/90/128/3 + 1 = 2432
     timer_set_period(TIM4, 2432);

    // Enable TIM4 update interrupt.
    timer_enable_irq(TIM4, TIM_DIER_UIE);
    timer_enable_counter(TIM4);
}

void tim4_isr(void) {
    if (timer_get_flag(TIM4, TIM_SR_UIF)) {
        timer_clear_flag(TIM4, TIM_SR_UIF);
        display_grid(offset_seq[offset_index]);
        current_grid++;
        if (current_grid > 127) {
            current_grid = 0;
            offset_index++;
            if (offset_index > 2) offset_index = 0;
            }
    }
}

// Using DMA2 Stream 3 Channel 3 for SPI1_TX
static void DMA2_STREAM3_SPI1_TX_setup() {
    nvic_set_priority(NVIC_DMA2_STREAM3_IRQ, 2<<5);
    nvic_enable_irq(NVIC_DMA2_STREAM3_IRQ);
    dma_stream_reset(DMA2, DMA_STREAM3);
    dma_channel_select(DMA2, DMA_STREAM3, DMA_SxCR_CHSEL_3);
    dma_set_transfer_mode(DMA2, DMA_STREAM3, DMA_SxCR_DIR_MEM_TO_PERIPHERAL);
    dma_set_priority(DMA2, DMA_STREAM3, DMA_SxCR_PL_HIGH);
    dma_disable_peripheral_increment_mode(DMA2, DMA_STREAM3);
    dma_enable_memory_increment_mode(DMA2, DMA_STREAM3);
    dma_set_peripheral_size(DMA2, DMA_STREAM3, DMA_SxCR_PSIZE_8BIT);
    dma_set_memory_size(DMA2, DMA_STREAM3, DMA_SxCR_MSIZE_8BIT);
    dma_set_peripheral_address(DMA2, DMA_STREAM3, (uint32_t)&SPI1_DR);
    dma_set_number_of_data(DMA2, DMA_STREAM3, 16);
    dma_set_priority(DMA2, DMA_STREAM3, DMA_SxCR_PL_LOW);
    dma_enable_transfer_complete_interrupt(DMA2, DMA_STREAM3);
    spi_enable_tx_dma(SPI1);
}

// Using DMA1 Stream 4 Channel 0 for SPI2_TX
static void DMA1_STREAM4_SPI2_TX_setup() {
    nvic_set_priority(NVIC_DMA1_STREAM3_IRQ, 2<<5);
    nvic_enable_irq(NVIC_DMA1_STREAM4_IRQ);
    dma_stream_reset(DMA1, DMA_STREAM4);
    dma_channel_select(DMA1, DMA_STREAM4, DMA_SxCR_CHSEL_0);
    dma_set_transfer_mode(DMA1, DMA_STREAM4,
                          DMA_SxCR_DIR_MEM_TO_PERIPHERAL);
    dma_set_priority(DMA1, DMA_STREAM4, DMA_SxCR_PL_HIGH);
    dma_disable_peripheral_increment_mode(DMA1, DMA_STREAM4);
    dma_enable_memory_increment_mode(DMA1, DMA_STREAM4);
    dma_set_peripheral_size(DMA1, DMA_STREAM4, DMA_SxCR_PSIZE_8BIT);
    dma_set_memory_size(DMA1, DMA_STREAM4, DMA_SxCR_MSIZE_8BIT);
    dma_set_peripheral_address(DMA1, DMA_STREAM4, (uint32_t)&SPI2_DR);
    dma_set_number_of_data(DMA1, DMA_STREAM4, 16);
    dma_set_priority(DMA1, DMA_STREAM4, DMA_SxCR_PL_LOW);
    dma_enable_transfer_complete_interrupt(DMA1, DMA_STREAM4);
    spi_enable_tx_dma(SPI2);
}

void dma2_stream3_isr(void) {
    if (dma_get_interrupt_flag(DMA2, DMA_STREAM3, DMA_TCIF)) {
        dma_clear_interrupt_flags(DMA2, DMA_STREAM3, DMA_TCIF);
    }
    if (display_brightness < (DEFAULT_DISPLAY_BRIGHTNESS + 125)) {
        while (!(SPI_SR(SPI1) & SPI_SR_TXE)) {}
        while (SPI_SR(SPI1) & SPI_SR_BSY) {}
        SCS_UP;
        SCS2_UP;
    }
    dma_disable_stream(DMA2, DMA_STREAM3);
}


void dma1_stream4_isr(void) {
    if (dma_get_interrupt_flag(DMA1, DMA_STREAM4, DMA_TCIF)) {
        dma_clear_interrupt_flags(DMA1, DMA_STREAM4, DMA_TCIF);
    }
    dma_disable_stream(DMA1, DMA_STREAM4);
}


static void SPI1_setup(void) {
    spi_reset(SPI1);
    spi_init_master(SPI1, SPI_CR1_BAUDRATE_FPCLK_DIV_8, SPI_CR1_CPOL_CLK_TO_1_WHEN_IDLE,
                    SPI_CR1_CPHA_CLK_TRANSITION_2, SPI_CR1_DFF_8BIT, SPI_CR1_MSBFIRST);
    spi_enable_software_slave_management(SPI1);
    spi_set_nss_high(SPI1);
    spi_enable(SPI1);
}


static void SPI2_setup(void) {
    spi_reset(SPI2);
    spi_init_master(SPI2, SPI_CR1_BAUDRATE_FPCLK_DIV_4, SPI_CR1_CPOL_CLK_TO_1_WHEN_IDLE,
                    SPI_CR1_CPHA_CLK_TRANSITION_2, SPI_CR1_DFF_8BIT, SPI_CR1_MSBFIRST);
    spi_enable_software_slave_management(SPI2);
    spi_set_nss_high(SPI2);
    spi_enable(SPI2);
}


void display_grid(uint8_t frame_offset) {
    (BKA_toggle_flag) ? (SBLK1_DWN) : (SBLK2_DWN);
    BKA_toggle_flag ^= 0xFF;
    (current_grid < 2) ? (GDATA_UP) : (GDATA_DWN);
    GCLK_UP;
    TNOP4;
    GCLK_DWN;
    timer_enable_counter(TIM3);  // Start display brightness control timer
    GBLK_DWN;
    SCS_DWN;
    SCS2_DWN;
    dma_set_memory_address(DMA2, DMA_STREAM3,
                            (uint32_t)&usb_rx_buffer[buffer_offset][(current_grid + frame_offset) * 16]);
    dma_set_number_of_data(DMA2, DMA_STREAM3, 16);

    dma_set_memory_address(DMA1, DMA_STREAM4,
                            (uint32_t)&usb_rx_buffer[buffer_offset][4096 + ((current_grid + frame_offset) * 16)]);
    dma_set_number_of_data(DMA1, DMA_STREAM4, 16);

    dma_enable_stream(DMA1, DMA_STREAM4);
    dma_enable_stream(DMA2, DMA_STREAM3);
    usbd_ep_nak_set(usb_device, EP_DATA_OUT, 0);
}

int main(void) {
    clock_setup();
    GPIO_setup();
    usb_init();
    SPI1_setup();
    SPI2_setup();
    DMA2_STREAM3_SPI1_TX_setup();
    DMA1_STREAM4_SPI2_TX_setup();
    TIM3_setup();
    TIM4_setup();
    while (1) {}
}

// USB OTG interrupt handler
extern "C"
void otg_fs_isr(void) {
    usbd_poll(usb_device);
}
