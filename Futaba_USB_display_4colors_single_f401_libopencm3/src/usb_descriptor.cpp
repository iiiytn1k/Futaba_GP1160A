/*
 * USB descriptor
 * 
 * Copyright (c) 2022 iiiytn1k
 * Licensed under MIT License
 * https://opensource.org/licenses/MIT
 * 
 */

#include "./usb_descriptor.h"
#include <libopencm3/stm32/desig.h>

#define USB_VID 0x0483
#define USB_PID 0xcafe
#define USB_DEVICE_REL 0x0001

static char Serial_Number[13];

const char *const usb_desc_strings[] = {
    "",                                                     // USB Manufacturer
    "Futaba GP1160A USB Display 4 Colors Single",           // USB Product
    Serial_Number,                                          // Serial number
    "USB Display Interface",                                // Data interface
};

enum usb_strings_index {
    USB_STRINGS_MANUFACTURER_ID = 1,
    USB_STRINGS_PRODUCT_ID,
    USB_STRINGS_SERIAL_NUMBER_ID,
    USB_STRINGS_DATA_IF_ID,
};

static const struct usb_endpoint_descriptor comm_endpoint_descs[] = {
    {
        .bLength = USB_DT_ENDPOINT_SIZE,
        .bDescriptorType = USB_DT_ENDPOINT,
        .bEndpointAddress = EP_DATA_OUT,
        .bmAttributes = USB_ENDPOINT_ATTR_BULK,
        .wMaxPacketSize = 64,
        .bInterval = 0,     // Ignored for Bulk & Control Endpoints.
        .extra = nullptr,
        .extralen = 0,
    },
};

static const struct usb_interface_descriptor comm_if_descs[] = {
    {
        .bLength = USB_DT_INTERFACE_SIZE,
        .bDescriptorType = USB_DT_INTERFACE,
        .bInterfaceNumber = 0,
        .bAlternateSetting = 0,
        .bNumEndpoints = sizeof(comm_endpoint_descs) / sizeof(comm_endpoint_descs[0]),
        .bInterfaceClass = USB_CLASS_VENDOR,
        .bInterfaceSubClass = 0,
        .bInterfaceProtocol = 0,
        .iInterface = USB_STRINGS_DATA_IF_ID,
        .endpoint = comm_endpoint_descs,
        .extra = nullptr,
        .extralen = 0,
    },
};

static const struct usb_interface usb_interfaces[] = {
    {
        .cur_altsetting = nullptr,
        .num_altsetting = sizeof(comm_if_descs) / sizeof(comm_if_descs[0]),
        .iface_assoc = nullptr,
        .altsetting = comm_if_descs,
    },
};

const struct usb_config_descriptor usb_config_descs[] = {
    {
        .bLength = USB_DT_CONFIGURATION_SIZE,
        .bDescriptorType = USB_DT_CONFIGURATION,
        .wTotalLength = 0,
        .bNumInterfaces = sizeof(usb_interfaces) / sizeof(usb_interfaces[0]),
        .bConfigurationValue = 1,
        .iConfiguration = 0,
        .bmAttributes = 0x80,    // bus-powered, i.e. it draws power from USB bus
        .bMaxPower = 0xfa,       // Maximum Power Consumption in 2mA units (500 mA)
        .interface = usb_interfaces,
    },
};

const struct usb_device_descriptor usb_device_desc = {
    .bLength = USB_DT_DEVICE_SIZE,
    .bDescriptorType = USB_DT_DEVICE,
    .bcdUSB = 0x0200,
    .bDeviceClass = USB_CLASS_VENDOR,
    .bDeviceSubClass = 0,
    .bDeviceProtocol = 0,
    .bMaxPacketSize0 = 64,
    .idVendor = USB_VID,
    .idProduct = USB_PID,
    .bcdDevice = USB_DEVICE_REL,
    .iManufacturer = USB_STRINGS_MANUFACTURER_ID,
    .iProduct = USB_STRINGS_PRODUCT_ID,
    .iSerialNumber = USB_STRINGS_SERIAL_NUMBER_ID,
    .bNumConfigurations = sizeof(usb_config_descs) / sizeof(usb_config_descs[0]),
};

void usb_get_serial_number() {
    desig_get_unique_id_as_string(Serial_Number, sizeof(Serial_Number));
}
