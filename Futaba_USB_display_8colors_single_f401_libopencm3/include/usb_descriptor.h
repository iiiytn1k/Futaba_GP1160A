/*
 * USB descriptor
 * 
 * Copyright (c) 2022 iiiytn1k
 * Licensed under MIT License
 * https://opensource.org/licenses/MIT
 * 
 */

#ifndef USB_DESCRIPTOR_H_
#define USB_DESCRIPTOR_H_

#include <libopencm3/usb/usbd.h>

// OUT bulk endpoint address
#define EP_DATA_OUT 0x01

// USB descriptor string table
extern const char *const usb_desc_strings[4];

// USB device descriptor
extern const struct usb_device_descriptor usb_device_desc;

// USB device configurations
extern const struct usb_config_descriptor usb_config_descs[];

void usb_get_serial_number();

#endif  // USB_DESCRIPTOR_H_
