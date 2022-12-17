/*
 * Microsoft WCID descriptors
 *
 * Copyright (c) 2020 Manuel Bleichenbacher
 * Licensed under MIT License
 * https://opensource.org/licenses/MIT
 * 
 */

#ifndef WCID_H_
#define WCID_H_

#include <libopencm3/usb/usbd.h>

// Register control request handlers for Microsoft WCID descriptors
void register_wcid_desc(usbd_device *usb_dev);

#endif  // WCID_H_
