/*
 * Splash screen
 * 
 * Copyright (c) 2022 iiiytn1k
 * Licensed under MIT License
 * https://opensource.org/licenses/MIT
 * 
 */

#ifndef SPLASH_SCREEN_H_
#define SPLASH_SCREEN_H_

volatile uint8_t usb_rx_buffer[2][6144] __attribute__((aligned(4))) = {{
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xaa, 0x00, 0x03, 0xf0, 0x7f, 0xe0, 0xff, 0xf8, 0x15, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x03, 0xd0, 0x02, 0xa2, 0xaa, 0xaa, 0xaa, 0x80, 0x2f, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf1, 0x94, 0x30, 0x01, 0x55, 0x55, 0x55, 0x54, 0x10, 0x10, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xc0, 0xe0, 0x09, 0x43, 0x80, 0x00, 0x00, 0x0f, 0x3c, 0x10, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x83, 0x00, 0xc3, 0x03, 0xff, 0xff, 0x03, 0x2c, 0x3c, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x2e, 0x03, 0x00, 0x10, 0xc2, 0xd0, 0x2a, 0x80, 0x0f, 0x1c, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x0e, 0x00, 0xc1, 0x2d, 0x40, 0x15, 0x7f, 0x3c, 0x3f, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x02, 0x04, 0x22, 0x02, 0x82, 0xaf, 0xff, 0xac, 0x3c, 0x3f, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x08, 0x00, 0x05, 0x01, 0x0a, 0x80, 0x00, 0x3c, 0x38, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x78, 0x04, 0x13, 0x1f, 0xc2, 0x00, 0x00, 0x00, 0x78, 0x3c, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf4, 0x0c, 0x02, 0x2a, 0x14, 0x05, 0x50, 0x00, 0xf0, 0x30, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf8, 0x0c, 0x10, 0x78, 0x04, 0x00, 0x00, 0x03, 0xc0, 0x3d, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x03, 0x14, 0x90, 0xc1, 0xc0, 0x00, 0x0b, 0xc7, 0x00, 0x5e, 
0x55, 0x55, 0x55, 0x55, 0x55, 0x7d, 0x00, 0x28, 0x02, 0x83, 0x00, 0x00, 0x0f, 0x8f, 0x0f, 0xed, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf4, 0x20, 0x10, 0x03, 0x00, 0x01, 0x7e, 0x1c, 0x0a, 0x8b, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xfc, 0x14, 0x08, 0x03, 0x40, 0xff, 0xfc, 0x3c, 0x00, 0x07, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xd5, 0x2c, 0xe0, 0x04, 0x43, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x91, 0x5a, 0x20, 0xc3, 0x02, 0xaa, 0xaf, 0x0c, 0x03, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x35, 0x40, 0x00, 0x03, 0xc0, 0x00, 0x0f, 0x0c, 0x00, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xa0, 0x48, 0x43, 0xd0, 0x00, 0x1e, 0x1c, 0x00, 0x03, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xcb, 0xfc, 0x07, 0x27, 0xc0, 0xff, 0xdf, 0xfc, 0x38, 0x00, 0x02, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xc0, 0x10, 0x0f, 0x34, 0x00, 0x00, 0x05, 0x00, 0x2f, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xea, 0x03, 0x20, 0x2a, 0x61, 0x80, 0x00, 0x0b, 0x40, 0x00, 0x54, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x0e, 0x00, 0xc3, 0x00, 0x00, 0x00, 0xf0, 0x02, 0xf9, 
0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0x81, 0x0a, 0x04, 0x04, 0x83, 0x00, 0x00, 0x00, 0x30, 0xc0, 0x03, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x01, 0x08, 0x38, 0x03, 0xf5, 0xfd, 0x55, 0xf1, 0xc0, 0x02, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xc0, 0x0c, 0x00, 0xc3, 0xfe, 0xbb, 0xef, 0xc3, 0x80, 0x4f, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3a, 0x12, 0x00, 0x32, 0x03, 0xfc, 0x00, 0x0b, 0x0f, 0x02, 0x02, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x47, 0x40, 0x00, 0xb5, 0x45, 0x04, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf4, 0x11, 0xca, 0x03, 0x00, 0x0a, 0x93, 0x4f, 0x0f, 0x40, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xc3, 0x40, 0x60, 0x03, 0x00, 0x00, 0x03, 0xcf, 0x0f, 0x80, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x0f, 0xc4, 0xf1, 0x43, 0xc1, 0x50, 0x03, 0xcb, 0x08, 0x05, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x53, 0x88, 0xb2, 0x83, 0x80, 0x08, 0x00, 0xc3, 0x00, 0x0f, 
0x55, 0x55, 0x55, 0x55, 0x55, 0x7f, 0xf0, 0xc3, 0x80, 0x03, 0x00, 0x01, 0x40, 0xc7, 0x01, 0x7e, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x06, 0x44, 0x00, 0x43, 0x01, 0x1f, 0x03, 0xcf, 0x02, 0xa8, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x1d, 0x08, 0x0a, 0x03, 0x02, 0xa8, 0x07, 0x8f, 0x00, 0x50, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x08, 0x70, 0x10, 0x03, 0x00, 0x00, 0x0f, 0x4e, 0x00, 0xa0, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x02, 0x51, 0x80, 0x03, 0x00, 0x00, 0x0b, 0x80, 0x2a, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xe8, 0x00, 0x0c, 0x00, 0x01, 0x00, 0x00, 0x00, 0x14, 0x10, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xdd, 0x54, 0x48, 0x40, 0x03, 0x00, 0x00, 0x00, 0x0f, 0x3c, 0x10, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x87, 0x57, 0x64, 0x03, 0x00, 0x00, 0x00, 0x0e, 0x38, 0x28, 
0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0x95, 0xcd, 0xc4, 0xc0, 0x03, 0xff, 0xbf, 0x40, 0x3c, 0x70, 0x1d, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x2a, 0x10, 0x28, 0x09, 0x03, 0xf0, 0x02, 0xa3, 0xf1, 0x80, 0x7f, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x1d, 0x31, 0x3c, 0x00, 0xc3, 0xf4, 0x00, 0x4b, 0xc7, 0x07, 0xf1, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x37, 0xc0, 0x02, 0x83, 0xff, 0x22, 0x07, 0x0e, 0x0b, 0xa0, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x58, 0xc0, 0x00, 0x03, 0x80, 0x05, 0x5c, 0x3c, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0x84, 0x41, 0x03, 0x00, 0x03, 0xf0, 0x70, 0x10, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0xa2, 0x00, 0x37, 0x92, 0x00, 0x03, 0xf1, 0xe0, 0xc0, 0x07, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x2a, 0xd4, 0x08, 0x0c, 0x18, 0x00, 0x01, 0x00, 0x04, 0x01, 0xff, 
0x55, 0x55, 0x55, 0x55, 0x55, 0x40, 0xc5, 0x30, 0x0c, 0xc3, 0x00, 0x00, 0xc3, 0x4f, 0x03, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x0e, 0x02, 0x7c, 0x03, 0x00, 0x00, 0x03, 0xcf, 0x07, 0xc0, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x0c, 0x06, 0x2c, 0x03, 0xc0, 0x50, 0x03, 0xcf, 0x0f, 0x0f, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xbc, 0x40, 0x0b, 0x43, 0xe0, 0x08, 0x00, 0xcb, 0x0f, 0xfe, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0x0f, 0x45, 0x13, 0xc3, 0x08, 0x05, 0x01, 0xcf, 0x08, 0x30, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xea, 0x02, 0xaa, 0xd0, 0x83, 0x00, 0x02, 0x03, 0x8e, 0x05, 0xfe, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xd7, 0x50, 0x00, 0x2d, 0x43, 0x50, 0x00, 0x5e, 0x38, 0x0f, 0xed, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf4, 0xf4, 0xcf, 0xc0, 0xaa, 0xaa, 0x85, 0xe4, 0x0f, 0x03, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xc9, 0x8f, 0x82, 0xf5, 0x5f, 0xa8, 0x21, 0xdf, 0xd1, 
0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xbf, 0x81, 0x08, 0x1b, 0x74, 0x00, 0x00, 0x00, 0x1a, 0xbc, 0x34, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x70, 0x27, 0xf2, 0xe3, 0xf0, 0x7e, 0x00, 0x2d, 0x3c, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xc0, 0x0e, 0x80, 0x04, 0x80, 0xff, 0xd5, 0x0a, 0xf0, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x07, 0x40, 0x6c, 0x70, 0x3f, 0xc3, 0xfc, 0x03, 0xd0, 0x7c, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xfe, 0x14, 0x99, 0x50, 0x81, 0x55, 0x54, 0x04, 0x0a, 0x8f, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x0c, 0x28, 0x00, 0x90, 0xe0, 0x00, 0x02, 0xf4, 0x53, 0x40, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x7d, 0x30, 0x10, 0x03, 0x00, 0x00, 0x00, 0x3c, 0xd0, 0xc0, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0xff, 0x84, 0x97, 0xc3, 0x00, 0x15, 0x55, 0xfc, 0xf0, 0x80, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xac, 0x0e, 0x8b, 0xc3, 0x00, 0xff, 0xff, 0xfc, 0xf0, 0x03, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3b, 0x4c, 0x0e, 0x97, 0x83, 0x00, 0x2e, 0x91, 0x20, 0xf0, 0xd7, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfe, 0x20, 0xa9, 0x43, 0x00, 0x3d, 0x33, 0x00, 0xf0, 0x00, 
0x55, 0x55, 0x55, 0x55, 0x55, 0x57, 0xac, 0x0c, 0x0f, 0xc3, 0x00, 0x2f, 0xf0, 0x20, 0xc0, 0xd4, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x2c, 0x38, 0x0a, 0x13, 0x40, 0x0b, 0xf3, 0xc1, 0xd0, 0x5b, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x3c, 0x00, 0x15, 0x54, 0x94, 0x00, 0xb3, 0xf4, 0x06, 0xf0, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x28, 0x08, 0x0f, 0xe1, 0xa8, 0xa2, 0xaa, 0xbe, 0xca, 0x55, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xf4, 0x11, 0x80, 0x0f, 0xc3, 0x40, 0x00, 0x00, 0x3c, 0xf0, 0xab, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xcd, 0x07, 0x05, 0x7f, 0xc2, 0xd0, 0x00, 0x00, 0x3c, 0xb0, 0x54, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0x70, 0x3f, 0xac, 0x01, 0x2d, 0x40, 0x00, 0x3c, 0xb0, 0xf0, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xca, 0xf4, 0xa0, 0x1c, 0xb2, 0x00, 0xa0, 0x3a, 0x9c, 0x70, 0x06, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x2c, 0xf1, 0x8c, 0x08, 0x0c, 0x00, 0x21, 0x7c, 0xf0, 0x78, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x0a, 0x44, 0x01, 0x55, 0x7d, 0x04, 0x00, 0x3c, 0xf0, 0xa9, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x08, 0x0f, 0x80, 0x0f, 0x1d, 0x00, 0xf1, 0xc0, 0x14, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x0c, 0x0c, 0x10, 0xf5, 0x7e, 0x1b, 0xff, 0xc3, 0x93, 0x45, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x1c, 0x04, 0x90, 0xff, 0xfd, 0x08, 0xbf, 0xc3, 0x80, 0xaf, 
0xff, 0xfe, 0xbf, 0xaf, 0xae, 0x85, 0xec, 0xca, 0x83, 0xfe, 0x95, 0xfc, 0x45, 0x51, 0x2f, 0xad, 
0xff, 0xfc, 0x3f, 0x0f, 0x0a, 0xea, 0x01, 0x8e, 0x8b, 0x81, 0x55, 0x55, 0x58, 0xb4, 0xc8, 0xd3, 
0xff, 0xfc, 0x3f, 0x0f, 0x05, 0x40, 0x01, 0x81, 0xb0, 0x03, 0xe0, 0x00, 0x00, 0x3c, 0xe2, 0xa6, 
0xff, 0xfc, 0x3f, 0x0f, 0x0a, 0x80, 0x00, 0xe0, 0xc1, 0xc3, 0xf5, 0x40, 0x00, 0x78, 0xc0, 0x30, 
0xff, 0xfc, 0x3f, 0x0f, 0x00, 0x7f, 0xf0, 0xe7, 0x2c, 0xc0, 0x2a, 0xbf, 0xd7, 0xe1, 0xc0, 0x3d, 
0xff, 0xfc, 0x2f, 0x0f, 0x00, 0xff, 0xe3, 0x04, 0x17, 0xd2, 0x80, 0x02, 0xaa, 0x82, 0xd1, 0x6f, 
0xff, 0xfc, 0x3f, 0x0f, 0x05, 0xff, 0xc0, 0x6e, 0x83, 0xd1, 0x55, 0x55, 0x45, 0x51, 0x14, 0x0f, 
0xff, 0xfc, 0x2f, 0x0f, 0x0c, 0x7f, 0xfc, 0x8a, 0x90, 0xb2, 0xaa, 0xaa, 0x8e, 0xf2, 0x4f, 0x5c, 
0xff, 0xfc, 0x3f, 0x0f, 0x0e, 0xaa, 0xac, 0x14, 0x3c, 0x41, 0x6a, 0xaa, 0xa8, 0x3c, 0xd1, 0xaf, 
0xff, 0xfc, 0x3f, 0x0f, 0x00, 0x7d, 0x0b, 0x3f, 0x2d, 0x43, 0xc0, 0x00, 0x00, 0x7c, 0xc0, 0x0e, 
0xff, 0xfc, 0x3f, 0x0f, 0x00, 0xff, 0xc2, 0x55, 0x7f, 0xc3, 0xc0, 0x00, 0x01, 0xe1, 0xc0, 0x59, 
0xff, 0xfc, 0x3f, 0x0f, 0x0f, 0x5b, 0xc0, 0x3f, 0xff, 0x83, 0xf0, 0x00, 0x3f, 0x87, 0x00, 0x83, 
0xff, 0xfc, 0x3f, 0x0f, 0x02, 0xf4, 0xba, 0xa1, 0xe8, 0x12, 0xaa, 0xaa, 0xa8, 0x02, 0xa0, 0xf5, 
0xff, 0xfc, 0x3f, 0x0f, 0x00, 0x20, 0xf2, 0x07, 0x07, 0xe8, 0x48, 0x00, 0x09, 0x40, 0xa0, 0x0a, 
0xff, 0xfc, 0x3f, 0x0f, 0x00, 0x07, 0xf5, 0xa8, 0x38, 0x21, 0x00, 0x00, 0x00, 0xf0, 0x47, 0x81, 
0xff, 0xfc, 0x3f, 0x0f, 0x00, 0x3c, 0xf0, 0x00, 0x0d, 0xc3, 0x00, 0x00, 0x00, 0x34, 0xc1, 0x1f, 
0xff, 0xfc, 0x3f, 0x0f, 0x00, 0xf4, 0xf1, 0xf0, 0x03, 0xc3, 0x40, 0x41, 0x01, 0xfc, 0xd0, 0x3f, 
0xff, 0xfc, 0x3f, 0x0f, 0x00, 0x2f, 0xc3, 0xf0, 0x0f, 0xc3, 0x02, 0x01, 0x1f, 0x18, 0xf0, 0xfd, 
0xff, 0xfc, 0x3f, 0x0f, 0x00, 0x04, 0x00, 0xf5, 0xe0, 0x03, 0x02, 0x11, 0xff, 0x01, 0xe0, 0xff, 
0xea, 0xa8, 0x2f, 0x0f, 0x0f, 0x00, 0x00, 0xea, 0x01, 0x43, 0x00, 0x03, 0xf3, 0x07, 0x80, 0xc0, 
0xc0, 0x50, 0x2f, 0x0f, 0x0f, 0xf0, 0x03, 0xc1, 0x0e, 0x83, 0x40, 0x03, 0xc2, 0x0f, 0x00, 0xb5, 
0xc0, 0x00, 0x3f, 0x0f, 0x0a, 0x50, 0x00, 0xd2, 0x0d, 0x12, 0xc0, 0x03, 0xf4, 0x08, 0x06, 0xc0, 
0xd1, 0x58, 0x3f, 0x0f, 0x00, 0xfc, 0x00, 0xbd, 0xaf, 0xf8, 0x2d, 0x55, 0xd5, 0x50, 0xa4, 0x05, 
0xa0, 0x00, 0x3f, 0x0f, 0x00, 0xa5, 0xed, 0x40, 0x4f, 0xf1, 0x20, 0x00, 0x02, 0xf2, 0xc0, 0x3f, 
0x02, 0xa8, 0x1f, 0x0f, 0x00, 0x4b, 0x57, 0xf0, 0x1f, 0xc1, 0x00, 0x00, 0x00, 0x3c, 0xd2, 0x0b, 
0x55, 0x54, 0x3f, 0x0f, 0x07, 0xf4, 0x03, 0xff, 0xff, 0xc3, 0x01, 0x7f, 0x50, 0x3c, 0x30, 0x03, 
0xff, 0xfc, 0x2f, 0x0f, 0x0b, 0x03, 0x03, 0xfe, 0xbf, 0xc3, 0x4f, 0xaa, 0xb5, 0x7c, 0x30, 0x97, 
0xe0, 0x02, 0x3f, 0x0f, 0x03, 0x04, 0x97, 0xfd, 0x7f, 0xc3, 0x00, 0x00, 0x00, 0x1c, 0xb0, 0x00, 
0xc5, 0x54, 0x3f, 0x0f, 0x0f, 0x40, 0x2a, 0xbf, 0xcb, 0xc3, 0x00, 0x00, 0x02, 0x3c, 0xf0, 0x7f, 
0xc0, 0x00, 0x3f, 0x0f, 0x07, 0xff, 0x40, 0x3f, 0xbf, 0xc3, 0x00, 0x00, 0x00, 0x78, 0xc0, 0xd7, 
0xca, 0xa8, 0x3f, 0x0f, 0x0e, 0xaa, 0xff, 0xfc, 0x0f, 0x82, 0xc0, 0x00, 0x00, 0xf1, 0xc0, 0xa1, 
0xd5, 0x55, 0x1f, 0x0f, 0x0c, 0xfc, 0xb5, 0xea, 0xa8, 0x32, 0x90, 0x00, 0x03, 0xc3, 0xa2, 0xd2, 
0xa0, 0x00, 0x3f, 0x0f, 0x03, 0x68, 0x78, 0x7f, 0x47, 0x68, 0x28, 0xaa, 0xa0, 0x20, 0x14, 0x0d, 
0x02, 0xa8, 0x3f, 0x0f, 0x00, 0x2b, 0xf0, 0xaa, 0x38, 0x03, 0x00, 0x00, 0x00, 0xb0, 0x43, 0x46, 
0x15, 0x50, 0x3f, 0x0f, 0x00, 0x00, 0x29, 0x6a, 0x81, 0x03, 0x40, 0x00, 0x00, 0x3c, 0xd0, 0xfd, 
0xe2, 0xa0, 0x3f, 0x0f, 0x00, 0xf4, 0x80, 0x54, 0x0f, 0xc3, 0xc0, 0x00, 0x00, 0x3c, 0xb0, 0x0e, 
0xc1, 0xf0, 0x3f, 0x0f, 0x04, 0xa8, 0x03, 0xff, 0x04, 0x82, 0xb4, 0x06, 0xf5, 0xfc, 0xf0, 0x7c, 
0xc0, 0xa0, 0x2f, 0x0f, 0x00, 0x14, 0x03, 0xaf, 0x28, 0x00, 0x00, 0x03, 0x00, 0x3c, 0x70, 0x82, 
0xd0, 0x00, 0x3f, 0x0f, 0x03, 0xff, 0x40, 0x7f, 0x00, 0x01, 0x00, 0x02, 0x00, 0x3c, 0xf0, 0x40, 
0xc0, 0x00, 0x3f, 0x0f, 0x03, 0xfe, 0x00, 0x3d, 0x7f, 0x43, 0x40, 0x00, 0x00, 0x78, 0xe0, 0xab, 
0xc0, 0x08, 0x3f, 0x0f, 0x02, 0x00, 0x04, 0x3f, 0xff, 0xc2, 0xfd, 0x55, 0x7f, 0x87, 0x80, 0xc0, 
0xc0, 0x02, 0x3f, 0x0f, 0x00, 0x04, 0x00, 0x0a, 0x83, 0xc1, 0x55, 0x55, 0x55, 0x78, 0x62, 0xb4, 
0xc0, 0x00, 0x3f, 0x0f, 0x0f, 0xfa, 0xb4, 0x00, 0x07, 0xa0, 0x00, 0x00, 0x00, 0x08, 0x08, 0x1c, 
0xc0, 0x00, 0x3f, 0x0f, 0x03, 0xe0, 0x30, 0x00, 0x0c, 0x03, 0xfa, 0xaa, 0xfe, 0xa9, 0x01, 0xe0, 
0xc0, 0x20, 0x3f, 0x0f, 0x03, 0x01, 0x7f, 0xe2, 0xfd, 0x07, 0xfc, 0x05, 0xf8, 0x00, 0x7a, 0x87, 
0x82, 0x00, 0x2a, 0x0a, 0x0a, 0x08, 0x07, 0xdd, 0xa2, 0xab, 0xfe, 0xa5, 0x74, 0x53, 0xdf, 0xad, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfd, 0x55, 0xff, 0xff, 0xff, 0x80, 0x1f, 0x00, 0x07, 0xff, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xef, 0xfc, 0x2f, 0xfa, 0xa8, 0x00, 0x00, 0x00, 0x2a, 0xff, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x0e, 0x14, 0x0f, 0xc0, 0x55, 0x55, 0x55, 0x55, 0x54, 0x3f, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x3c, 0xe0, 0x02, 0x80, 0x7f, 0xff, 0xff, 0xf0, 0x3c, 0x2f, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x80, 0x7c, 0x00, 0xff, 0xff, 0xff, 0xfc, 0x2c, 0x03, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0xfc, 0x00, 0x00, 0x00, 0x2f, 0xff, 0xff, 0xf0, 0x1c, 0x3f, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 0xfc, 0x01, 0xcc, 0x01, 0x02, 0xbf, 0xea, 0x80, 0x3c, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xfc, 0x01, 0x45, 0xc2, 0x80, 0x00, 0x00, 0x00, 0x3c, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xe0, 0x02, 0xcf, 0xf5, 0x54, 0x00, 0x00, 0x00, 0x3c, 0x07, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x01, 0x8f, 0xff, 0xfd, 0x00, 0x00, 0x00, 0x7c, 0x03, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x02, 0xcf, 0xff, 0xeb, 0x00, 0x54, 0x00, 0xfc, 0x0f, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x04, 0x03, 0x8f, 0x80, 0x00, 0x00, 0x00, 0x03, 0xfc, 0x02, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x01, 0x2f, 0x00, 0x3f, 0xff, 0xf4, 0x07, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xfc, 0x02, 0xcd, 0x40, 0xff, 0xff, 0xf0, 0x0f, 0x00, 0x10, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x03, 0x8f, 0xc0, 0xff, 0xfe, 0x80, 0x1f, 0x05, 0x74, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x01, 0xd3, 0xc0, 0xbf, 0x00, 0x00, 0x3e, 0x0f, 0xf8, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xd0, 0x0a, 0xe3, 0xc0, 0xfc, 0x00, 0x00, 0x00, 0x3f, 0x80, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbc, 0x05, 0x5f, 0xc0, 0xff, 0xff, 0xfa, 0xa5, 0x0c, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xc0, 0x3f, 0xff, 0xf0, 0x0f, 0x0f, 0xff, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfe, 0xea, 0xb7, 0xc0, 0x2f, 0xff, 0xe0, 0x1f, 0x0f, 0xfc, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x0b, 0xfe, 0x00, 0x4f, 0xc0, 0x00, 0x20, 0x00, 0x3e, 0x0f, 0xfd, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfc, 0x01, 0xcf, 0x10, 0x00, 0x00, 0x00, 0x00, 0x50, 0xff, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0x02, 0x0b, 0x40, 0x7f, 0xff, 0xf4, 0x00, 0xbf, 0xff, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0x01, 0xfc, 0xc0, 0xff, 0xff, 0xff, 0x00, 0x0b, 0xfe, 
0x55, 0x55, 0x55, 0x55, 0x55, 0x7e, 0xfc, 0x01, 0xc6, 0x80, 0xff, 0xff, 0xff, 0xc0, 0xd0, 0xbc, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0x02, 0x09, 0x00, 0x0a, 0x02, 0xaa, 0x01, 0xfc, 0x3d, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x3c, 0x03, 0xcc, 0xc0, 0x01, 0x00, 0x00, 0x03, 0xa0, 0x3f, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc5, 0xe8, 0x00, 0x05, 0xc0, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x07, 0x88, 0x80, 0x5f, 0x40, 0x00, 0x04, 0x0f, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x04, 0x05, 0xc0, 0xff, 0xf5, 0x40, 0x0f, 0x00, 0xbf, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x3c, 0x2a, 0x1f, 0xc0, 0xff, 0xff, 0xf0, 0x0f, 0x00, 0x7f, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x08, 0x0f, 0xc0, 0x3e, 0xef, 0xf0, 0x0b, 0x07, 0xfa, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x0b, 0x80, 0x7e, 0x47, 0xf3, 0x03, 0x0f, 0xf0, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xc0, 0x4c, 0x00, 0xfd, 0x5b, 0xf7, 0x07, 0x0e, 0x81, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x41, 0x62, 0x40, 0xff, 0xff, 0xfc, 0x0f, 0x0d, 0x57, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x02, 0xcf, 0xc0, 0xff, 0xff, 0xf8, 0x0f, 0x0f, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0f, 0x8f, 0xc0, 0xff, 0xff, 0xf0, 0x0e, 0x0f, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x40, 0x7f, 0xc0, 0xff, 0xff, 0xf4, 0x00, 0x00, 0xbf, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xc0, 0x55, 0x55, 0x55, 0x40, 0x14, 0x3f, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0x80, 0xbf, 0xc0, 0xff, 0xff, 0xff, 0xf0, 0x3c, 0x3f, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xa7, 0x50, 0x0b, 0xc0, 0xff, 0xff, 0xff, 0xf0, 0x3c, 0x3f, 
0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0x95, 0xcd, 0xc1, 0x0f, 0xc0, 0x00, 0x00, 0xbf, 0xc0, 0x7c, 0x3f, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xf4, 0x02, 0x8a, 0xc0, 0x00, 0x00, 0x0c, 0x01, 0xa8, 0x3f, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0xf0, 0x03, 0xfc, 0xc0, 0x00, 0x00, 0x04, 0x07, 0x05, 0xfe, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf4, 0xc0, 0x45, 0xc0, 0x00, 0x02, 0x00, 0x0f, 0x0f, 0xff, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xac, 0xc0, 0xcf, 0xc0, 0x7f, 0x50, 0x00, 0x3f, 0x0f, 0xff, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x83, 0x8f, 0xc0, 0xff, 0xfc, 0x00, 0x78, 0x0f, 0xff, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x35, 0x5c, 0x01, 0x0f, 0x80, 0xff, 0xfc, 0x04, 0x80, 0x3f, 0xff, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x2a, 0xfc, 0x06, 0xcc, 0x00, 0x5f, 0xfc, 0x01, 0x04, 0x2f, 0xff, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x08, 0xcc, 0x00, 0xff, 0xff, 0x00, 0x0f, 0x0f, 0xff, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0x9c, 0x1c, 0x00, 0xff, 0xff, 0xf0, 0x0f, 0x0f, 0xc0, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0x01, 0x4c, 0x00, 0x3f, 0xaf, 0xf0, 0x0f, 0x0f, 0x0f, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbc, 0x1c, 0xcf, 0x40, 0x1a, 0x47, 0xf3, 0x0b, 0x0f, 0xff, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x20, 0x8f, 0xc0, 0xf9, 0x5f, 0xf6, 0x0f, 0x0f, 0xff, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xaa, 0xff, 0xc0, 0xff, 0xff, 0xfc, 0x0f, 0x0f, 0xfe, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0x51, 0x05, 0x3f, 0xc0, 0xaf, 0xff, 0xa0, 0x3f, 0x0f, 0xfd, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xf4, 0xf4, 0x0f, 0xc0, 0x00, 0x00, 0x05, 0xfa, 0x0f, 0xff, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0xc8, 0x4f, 0x83, 0xf5, 0x5f, 0xfe, 0x80, 0x7f, 0xfe, 
0x55, 0x55, 0x55, 0x55, 0x55, 0x7f, 0xfc, 0x02, 0x8f, 0x50, 0x00, 0x00, 0x00, 0x57, 0xfc, 0x3f, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0f, 0x4f, 0xf2, 0xe0, 0x00, 0x7f, 0xff, 0xfd, 0x3f, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x11, 0xce, 0x80, 0x04, 0x00, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x26, 0x1c, 0x00, 0x3a, 0x96, 0xa9, 0x57, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x81, 0x2d, 0x56, 0x05, 0x55, 0x55, 0x50, 0x2e, 0x8f, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0c, 0x02, 0xcf, 0xe1, 0x9f, 0xff, 0xfd, 0x00, 0xc2, 0x40, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xe8, 0x7c, 0x03, 0x8f, 0xc0, 0xff, 0xff, 0xff, 0xc0, 0xf0, 0xc0, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xfe, 0x01, 0x2f, 0xc0, 0xff, 0xea, 0xaa, 0x00, 0xf0, 0x80, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc1, 0xfc, 0x00, 0x4f, 0xc0, 0xff, 0x40, 0x00, 0x40, 0xf0, 0x03, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xfc, 0x01, 0x0f, 0x80, 0xfc, 0x00, 0x00, 0x30, 0xf0, 0xd7, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xfc, 0x01, 0x38, 0x00, 0xff, 0x40, 0x00, 0x30, 0xf0, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xd7, 0xfc, 0x02, 0xc0, 0x00, 0xff, 0xd0, 0x00, 0x60, 0xf0, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x00, 0xc0, 0x01, 0xbf, 0xf4, 0x00, 0x01, 0xe1, 0x0b, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x09, 0x25, 0x70, 0x3b, 0xff, 0x40, 0x05, 0x82, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x06, 0xcf, 0xc0, 0x57, 0x5d, 0x55, 0x40, 0x42, 0x55, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xec, 0x38, 0xcf, 0xc0, 0xbf, 0xff, 0xff, 0xc0, 0xf0, 0xab, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xff, 0x8f, 0x5f, 0xc0, 0x2f, 0xff, 0xff, 0xc0, 0xb0, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0xf0, 0x3f, 0xfc, 0x01, 0x02, 0xbf, 0xff, 0xc0, 0xb0, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xca, 0xf5, 0xaa, 0xac, 0x10, 0xaa, 0x8f, 0xca, 0x90, 0x70, 0x07, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x2c, 0xf0, 0x4c, 0x0a, 0xa4, 0x0f, 0xd0, 0x60, 0xf0, 0x7f, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x08, 0x41, 0xc1, 0x55, 0x7c, 0x0b, 0xff, 0xc0, 0xf0, 0xab, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x01, 0x02, 0xcf, 0xff, 0xfc, 0x12, 0xff, 0x01, 0xf0, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x0c, 0x03, 0x8f, 0xff, 0xfd, 0x20, 0x00, 0x03, 0xe0, 0x45, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x1f, 0x01, 0x2f, 0xff, 0xff, 0x40, 0x15, 0x56, 0x07, 0xff, 
0xff, 0xff, 0xea, 0xaf, 0xfe, 0x85, 0xfc, 0xc0, 0x4f, 0xff, 0xd5, 0xf5, 0x04, 0x01, 0x0f, 0xaf, 
0xff, 0xff, 0xc0, 0x0f, 0xff, 0xff, 0xfc, 0x81, 0x1f, 0xe0, 0x00, 0x00, 0x0b, 0x40, 0x40, 0x03, 
0xff, 0xff, 0xc0, 0x0f, 0xfa, 0xbf, 0xfe, 0x00, 0x2f, 0xc0, 0x1f, 0xff, 0xff, 0xc0, 0xd0, 0x07, 
0xff, 0xff, 0xc0, 0x0f, 0xf5, 0x7f, 0xfc, 0xe0, 0x0a, 0xc0, 0x0a, 0xbf, 0xff, 0x80, 0xf0, 0x3f, 
0xff, 0xff, 0xc0, 0x0f, 0xff, 0xff, 0xfc, 0xe0, 0xfc, 0xc0, 0x00, 0x00, 0x28, 0x01, 0xf0, 0x3f, 
0xff, 0xff, 0xd0, 0x0f, 0xff, 0xff, 0xfc, 0x01, 0x05, 0xc3, 0xd5, 0x55, 0x55, 0x57, 0xa0, 0x6f, 
0xff, 0xff, 0xc0, 0x0f, 0xff, 0xff, 0xfc, 0x00, 0x4f, 0xf4, 0x00, 0x00, 0x04, 0x00, 0x06, 0x0f, 
0xff, 0xff, 0xd0, 0x0f, 0xfc, 0x7f, 0xfc, 0x45, 0x0f, 0xe8, 0x00, 0x00, 0x0d, 0x02, 0x0b, 0x5f, 
0xff, 0xff, 0xc0, 0x0f, 0xff, 0xff, 0xfe, 0x20, 0xbf, 0x82, 0xbf, 0xff, 0xf7, 0xc0, 0xc2, 0xaf, 
0xff, 0xff, 0xc0, 0x0f, 0xff, 0xff, 0xff, 0x00, 0x2f, 0xc0, 0x3f, 0xff, 0xff, 0x80, 0xf0, 0x0f, 
0xff, 0xff, 0xc0, 0x0f, 0xff, 0xff, 0xff, 0x55, 0x7f, 0xc0, 0x3f, 0xff, 0xfe, 0x01, 0xf0, 0x5e, 
0xff, 0xff, 0xc0, 0x0f, 0xf0, 0xaf, 0xff, 0xff, 0xff, 0xc0, 0x0f, 0xff, 0xc0, 0x07, 0xf0, 0xfc, 
0xff, 0xff, 0xc0, 0x0f, 0xfd, 0x0b, 0xfa, 0xa1, 0xff, 0xc2, 0xaa, 0xaa, 0xaa, 0xa8, 0x01, 0xff, 
0xff, 0xff, 0xc0, 0x0f, 0xff, 0xdf, 0xf0, 0x07, 0xff, 0xf0, 0x17, 0xff, 0xf4, 0x84, 0x18, 0x0a, 
0xff, 0xff, 0xc0, 0x0f, 0xff, 0xff, 0xf5, 0xff, 0xf8, 0x00, 0xff, 0xff, 0xff, 0x02, 0x00, 0x01, 
0xff, 0xff, 0xc0, 0x0f, 0xff, 0xfc, 0xff, 0xff, 0xfd, 0xc0, 0xff, 0xff, 0xff, 0xc0, 0xd2, 0x1f, 
0xff, 0xff, 0xc0, 0x0f, 0xff, 0xf4, 0xff, 0xff, 0xff, 0xc0, 0xbf, 0xaa, 0xfe, 0x00, 0xf0, 0x3f, 
0xff, 0xff, 0xc0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xfe, 0x00, 0xe0, 0x10, 0xf0, 0xfd, 
0xff, 0xff, 0xc0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0xff, 0x4e, 0x00, 0x31, 0xf0, 0xff, 
0xfa, 0xaa, 0xd0, 0x0f, 0xf0, 0xff, 0xff, 0xea, 0x01, 0x40, 0xff, 0xfc, 0x00, 0x37, 0xf0, 0xff, 
0xf1, 0x41, 0xd0, 0x0f, 0xf0, 0x0f, 0xff, 0xc0, 0x0f, 0xc0, 0xbf, 0xfc, 0x00, 0x3f, 0xf0, 0xbf, 
0xf0, 0xa3, 0xc0, 0x0f, 0xf5, 0xff, 0xff, 0xd0, 0x0f, 0xc2, 0x3f, 0xfc, 0x00, 0x00, 0x00, 0x00, 
0xf1, 0x5b, 0xc0, 0x0f, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xf4, 0x22, 0xa8, 0x80, 0x00, 0x24, 0x05, 
0x80, 0x03, 0xc0, 0x0f, 0xff, 0xff, 0xef, 0xff, 0xbf, 0xe0, 0xdf, 0xff, 0xfd, 0x02, 0x41, 0x3f, 
0x00, 0xab, 0xe0, 0x0f, 0xff, 0xff, 0x57, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xff, 0xc0, 0xf0, 0x0b, 
0x15, 0x57, 0xc0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xfe, 0x80, 0xaf, 0xc0, 0x30, 0x03, 
0xff, 0xff, 0xd0, 0x0f, 0xff, 0x03, 0xff, 0xff, 0xff, 0xc0, 0xb0, 0x15, 0x5f, 0x80, 0x30, 0xd7, 
0xfa, 0xa8, 0xc0, 0x0f, 0xff, 0x00, 0xbf, 0xff, 0xff, 0xc0, 0xfc, 0x00, 0x00, 0x10, 0xb0, 0xff, 
0xf5, 0x51, 0xc0, 0x0f, 0xff, 0x40, 0x2a, 0xbf, 0xcb, 0xc0, 0xff, 0xd5, 0x55, 0xc0, 0xf0, 0xff, 
0xf0, 0x00, 0xc0, 0x0f, 0xff, 0xff, 0x40, 0x3f, 0xff, 0xc0, 0xff, 0xff, 0xff, 0x80, 0xf0, 0xd7, 
0xfa, 0xa2, 0xc0, 0x0f, 0xfe, 0xaa, 0xff, 0xff, 0xff, 0x80, 0x3f, 0xff, 0xff, 0x01, 0xf0, 0xfe, 
0xf5, 0x54, 0xe0, 0x0f, 0xfc, 0x00, 0xbf, 0xea, 0xa8, 0x12, 0x2f, 0xff, 0xfc, 0x03, 0xc1, 0xfd, 
0x80, 0x03, 0xc0, 0x0f, 0xff, 0x40, 0x78, 0x00, 0x07, 0x60, 0x08, 0x00, 0x00, 0x28, 0x0c, 0x0f, 
0x00, 0xab, 0xc0, 0x0f, 0xff, 0xff, 0xf0, 0x00, 0x3f, 0xc0, 0xff, 0xff, 0xff, 0x42, 0x42, 0x47, 
0x15, 0x43, 0xc0, 0x0f, 0xff, 0xff, 0xfd, 0x7f, 0xff, 0xc0, 0xbf, 0xff, 0xff, 0xc0, 0xf0, 0xff, 
0xf2, 0x82, 0xc0, 0x0f, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xc0, 0x3f, 0xff, 0xff, 0xc0, 0xb0, 0xfe, 
0xf0, 0xd3, 0xc0, 0x0f, 0xfb, 0xff, 0xff, 0xff, 0xfb, 0xc1, 0x5f, 0xf8, 0x5f, 0x00, 0xf0, 0xfc, 
0xf2, 0x83, 0xd0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xd7, 0xf0, 0x03, 0xff, 0x00, 0x10, 0x70, 0x82, 
0xf5, 0x53, 0xc0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x57, 0xff, 0x55, 0xc0, 0xf0, 0x40, 
0xf0, 0x07, 0xc0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xbf, 0xff, 0xff, 0x80, 0xf0, 0xff, 
0xf0, 0x3a, 0xc0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x02, 0xaa, 0x80, 0x07, 0xf0, 0xff, 
0xf0, 0x00, 0xc0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc1, 0x55, 0x55, 0x55, 0x7f, 0x81, 0xbf, 
0xf0, 0x00, 0xc0, 0x0f, 0xff, 0xfa, 0xbf, 0xff, 0xff, 0x92, 0xaa, 0xaa, 0xaa, 0xa0, 0x10, 0x1f, 
0xf0, 0x00, 0xc0, 0x0f, 0xff, 0xe0, 0x3f, 0xff, 0xfc, 0x09, 0x50, 0x00, 0x54, 0x02, 0x01, 0xff, 
0xf2, 0x23, 0xc0, 0x0f, 0xff, 0x01, 0x7f, 0xe2, 0xfd, 0x07, 0xfc, 0x05, 0xf8, 0x00, 0x7f, 0xf8, 
0xa0, 0x02, 0x80, 0x0a, 0xaa, 0x1f, 0xfa, 0x80, 0xff, 0xff, 0xff, 0xfa, 0xa1, 0x02, 0xa0, 0x50, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0xc0, 0x03, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfc, 0x03, 0xff, 0xff, 0xff, 0xff, 0xd0, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xcc, 0x02, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x40, 0x00, 0x2a, 0xaf, 0xfe, 0xab, 0xc0, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xaa, 0xc0, 0x00, 0x00, 0x0f, 0xfc, 0x03, 0xc0, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x80, 0x00, 0x00, 0x0f, 0xfc, 0x03, 0x80, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xee, 0xc0, 0x00, 0x00, 0x0f, 0xa8, 0x03, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xcf, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x00, 0x01, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xea, 0xc0, 0x03, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb3, 0x80, 0x03, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0xd0, 0x03, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xea, 0xe0, 0x03, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x40, 0x00, 0x00, 0x03, 0xfd, 0x55, 0x55, 0x50, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xc0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x34, 0x00, 0x7f, 0x40, 0x03, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0xd1, 0xc0, 0xc0, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x00, 0x81, 0xff, 0xff, 0xff, 0xd0, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xfc, 0x03, 0xff, 0xff, 0xff, 0xfd, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0xc1, 0x43, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xaa, 0x02, 0xc3, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xcc, 0x03, 0xfe, 0xaa, 0xaf, 0xfc, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfc, 0x00, 0x0b, 0xf0, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xc0, 0x00, 0x5f, 0xfd, 0x01, 0x50, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd5, 0xc0, 0x03, 0xff, 0xff, 0xc3, 0xf0, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2a, 0x00, 0x03, 0xff, 0xff, 0xf3, 0xf0, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x03, 0xff, 0xbf, 0xf3, 0xf4, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x43, 0xfc, 0x0b, 0xf3, 0xfc, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xcc, 0xc3, 0xfc, 0x07, 0xf7, 0xf8, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x45, 0x83, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xaa, 0xc0, 0x03, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x80, 0x03, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xa0, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x01, 0x55, 0x55, 0x55, 0x55, 0x40, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x40, 0x2f, 0x40, 0x03, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
0x55, 0x55, 0x55, 0x55, 0x55, 0x6a, 0x00, 0x15, 0xc0, 0x03, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x02, 0xaa, 0x80, 0x03, 0xfe, 0xaa, 0xab, 0xfe, 0x00, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x0c, 0xff, 0xfc, 0x03, 0xfc, 0x15, 0x03, 0xf8, 0x00, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x08, 0x10, 0x40, 0x03, 0xfd, 0x08, 0x0f, 0xf0, 0x00, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x2c, 0xc0, 0x03, 0xff, 0x55, 0x5f, 0xc0, 0x00, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x7f, 0xc0, 0x03, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x41, 0x00, 0x42, 0xff, 0xff, 0xfa, 0x00, 0x00, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xd5, 0x00, 0xce, 0xc3, 0xe0, 0x5f, 0xfd, 0x00, 0x50, 0x00, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xb8, 0xc3, 0xc3, 0xff, 0xff, 0xc3, 0xf0, 0x00, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x03, 0xc3, 0xff, 0xff, 0xf3, 0xf0, 0x00, 0x3f, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0xc7, 0x43, 0xc3, 0xff, 0xff, 0xf3, 0xf0, 0x00, 0xf0, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x40, 0xdc, 0xc0, 0x83, 0xfc, 0x0b, 0xf3, 0xf4, 0x00, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x20, 0x80, 0x03, 0xf4, 0x03, 0xf7, 0xf0, 0x00, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x55, 0x00, 0x03, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x01, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xe8, 0xae, 0xaa, 0x80, 0x03, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x02, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x08, 0x00, 0xc0, 0x03, 0xff, 0xff, 0xfa, 0x00, 0x00, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x15, 0xc0, 0x40, 0x0a, 0xa0, 0x00, 0x00, 0x00, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0xaa, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x7f, 0x40, 0x0d, 0x1f, 0xff, 0x80, 0x00, 0x02, 0xc0, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0xd1, 0xc1, 0x7f, 0xfb, 0xff, 0x00, 0x00, 0x00, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x22, 0x03, 0xff, 0xc0, 0x28, 0x02, 0xa8, 0x00, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x15, 0x02, 0xa8, 0x00, 0x00, 0x00, 0x00, 0x01, 0x70, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xf0, 0xea, 0xc0, 0x00, 0x7f, 0xff, 0xff, 0xff, 0x00, 0xbf, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xd7, 0x80, 0xb3, 0x80, 0x03, 0xff, 0xff, 0xff, 0xff, 0x00, 0x3f, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x15, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0x00, 0x7f, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0xee, 0xc0, 0x03, 0xff, 0xaa, 0xaa, 0xbf, 0x00, 0xfc, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc4, 0x00, 0xcf, 0x80, 0x43, 0xff, 0x15, 0x40, 0x0f, 0x00, 0x28, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x41, 0x07, 0xc3, 0xff, 0xff, 0xc0, 0x0f, 0x00, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xe8, 0x00, 0xce, 0xcf, 0xc3, 0xff, 0xff, 0xc0, 0x1f, 0x00, 0x00, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0xb8, 0xcf, 0xc2, 0xff, 0xff, 0xc0, 0xfe, 0x00, 0xf4, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x41, 0x0a, 0x80, 0xaf, 0xff, 0xc0, 0xfa, 0x01, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0xce, 0xc0, 0x01, 0x55, 0x55, 0x55, 0x55, 0x00, 0xaa, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0xb8, 0xc0, 0x03, 0xff, 0xff, 0xff, 0xff, 0x00, 0x54, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x50, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0x40, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x0f, 0xc0, 0x03, 0xc2, 0xff, 0xff, 0xff, 0xff, 0x40, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xf5, 0x0a, 0x00, 0x03, 0xc0, 0x00, 0x3f, 0xf0, 0x2f, 0x80, 0xf8, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd0, 0x0f, 0xc3, 0xf5, 0x50, 0x3f, 0xf4, 0x1f, 0x00, 0x80, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf4, 0x15, 0xce, 0xaa, 0x80, 0x3f, 0xff, 0xff, 0x00, 0x54, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xaa, 0xc0, 0x00, 0x00, 0x2f, 0xff, 0xfe, 0x00, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 0x80, 0x00, 0x00, 0x0f, 0xff, 0xfc, 0x00, 0xba, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x15, 0x00, 0x00, 0x00, 0x02, 0xea, 0xa8, 0x00, 0x00, 
0xff, 0xff, 0xff, 0xfa, 0xab, 0xfa, 0x00, 0x2a, 0xc0, 0x00, 0x2a, 0x00, 0x01, 0x54, 0x00, 0x50, 
0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x00, 0x00, 0x00, 0x07, 0xff, 0x03, 0xfc, 
0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x15, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0x00, 0xf8, 
0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x0a, 0xc0, 0x03, 0xff, 0xff, 0xff, 0xff, 0x00, 0xc0, 
0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x1f, 0xfc, 0x03, 0xff, 0xff, 0xff, 0xfe, 0x00, 0xc0, 
0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x2a, 0xaa, 0xaa, 0xa8, 0x00, 0x90, 
0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0xee, 0xc0, 0x00, 0x00, 0x00, 0x01, 0x54, 0x01, 0xf0, 
0xff, 0xff, 0xff, 0xf0, 0x03, 0x80, 0x00, 0xcf, 0x80, 0x00, 0x00, 0x00, 0x03, 0xfd, 0x00, 0xa0, 
0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x01, 0x55, 0x40, 0x01, 0x55, 0x55, 0x5f, 0xff, 0x00, 0x50, 
0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0xff, 0xd0, 0x03, 0xff, 0xff, 0xff, 0xff, 0x00, 0xf0, 
0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0xaa, 0x80, 0x03, 0xff, 0xff, 0xff, 0xfe, 0x00, 0xa0, 
0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 
0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x05, 0x5e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xf8, 0x00, 0x00, 0x7f, 0xff, 0xff, 0x50, 0x07, 0xf5, 
0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x0a, 0x00, 0x07, 0xc3, 0xff, 0xff, 0xff, 0xfd, 0x0b, 0xfe, 
0xff, 0xff, 0xff, 0xf0, 0x00, 0x03, 0x00, 0x00, 0x02, 0x03, 0xff, 0xff, 0xff, 0xff, 0x00, 0xe0, 
0xff, 0xff, 0xff, 0xf0, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0x00, 0xc0, 
0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfc, 0x03, 0xfc, 0x2f, 0x00, 0x02, 
0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xc3, 0xfd, 0x57, 0xfc, 0x0e, 0x00, 0x00, 
0xfa, 0xaa, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x15, 0xfe, 0x83, 0xff, 0xff, 0xfc, 0x08, 0x00, 0x00, 
0xf0, 0x00, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x3f, 0xf0, 0x03, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x40, 
0xf2, 0x83, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x2f, 0xf0, 0x00, 0xff, 0xff, 0xf8, 0x00, 0x01, 0xff, 
0xf4, 0x07, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x0a, 0xaa, 0x00, 0x00, 0x0b, 0xfa, 
0x30, 0x03, 0xff, 0xf0, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xfd, 0x02, 0xc0, 
0x22, 0xab, 0xff, 0xf0, 0x00, 0x00, 0xa8, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0x00, 0xf4, 
0x40, 0x03, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xfc, 
0xff, 0xff, 0xff, 0xf0, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x03, 0xff, 0xea, 0xaa, 0xff, 0xc0, 0x28, 
0xfa, 0xae, 0xff, 0xf0, 0x00, 0xff, 0x40, 0x00, 0x00, 0x03, 0xff, 0x00, 0x00, 0x2f, 0x40, 0x00, 
0xf0, 0x0c, 0xff, 0xf0, 0x00, 0xbf, 0xd5, 0x40, 0x34, 0x03, 0xff, 0x55, 0x55, 0x7f, 0x00, 0x00, 
0xf0, 0x0c, 0xff, 0xf0, 0x00, 0x00, 0xbf, 0xc0, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0x00, 0x28, 
0xf0, 0x0c, 0xff, 0xf0, 0x01, 0x55, 0x00, 0x00, 0x00, 0x43, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 
0xf0, 0x09, 0xff, 0xf0, 0x03, 0xff, 0x40, 0x15, 0x57, 0xc0, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 
0x30, 0x03, 0xff, 0xf0, 0x00, 0xbf, 0x87, 0xff, 0xf8, 0x80, 0x02, 0xaa, 0xaa, 0x80, 0x03, 0xf0, 
0x22, 0xab, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0xc0, 0x03, 0xff, 0xff, 0xff, 0xfd, 0x00, 0xb8, 
0x40, 0x03, 0xff, 0xf0, 0x00, 0x00, 0x02, 0x80, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 
0xf8, 0x00, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0x40, 0x01, 
0xf1, 0x41, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xab, 0xff, 0xaa, 0xff, 0x00, 0x03, 
0xf0, 0x03, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfc, 0x00, 0x2f, 0x80, 0x7d, 
0xf5, 0x43, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x57, 0xfd, 0x55, 0x7f, 0x00, 0xbf, 
0xf0, 0x03, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 
0xff, 0xc3, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 
0xf0, 0x00, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xaa, 0xaa, 0xaa, 0x80, 0x00, 0x40, 
0xfa, 0xaa, 0xff, 0xf0, 0x00, 0x05, 0x40, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x07, 0xe0, 
0xf5, 0x15, 0xff, 0xf0, 0x00, 0x1f, 0xc0, 0x00, 0x03, 0xf4, 0x05, 0x55, 0x01, 0x55, 0xfe, 0x00, 
0xf8, 0x0b, 0xff, 0xf0, 0x00, 0xfe, 0x80, 0x1d, 0x02, 0xf8, 0x03, 0xfa, 0x07, 0xff, 0x80, 0x00, 
0xa0, 0x82, 0xaa, 0xa0, 0x00, 0xa0, 0x00, 0x2a, 0x00, 0x00, 0x00, 0x00, 0x0a, 0xa8, 0x00, 0x00, 
},
{}};
#endif  // SPLASH_SCREEN_H_
