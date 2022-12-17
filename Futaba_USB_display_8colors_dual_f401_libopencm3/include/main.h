/*
 * main.h
 * 
 * Copyright (c) 2022 iiiytn1k
 * Licensed under MIT License
 * https://opensource.org/licenses/MIT
 * 
 */

#ifndef MAIN_H_
#define MAIN_H_

#define    GGLK_PIN      GPIO2
#define    GCLK_PIN      GPIO0
#define    GDATA_PIN     GPIO1
#define    SBLK1_PIN     GPIO4
#define    SBLK2_PIN     GPIO3
#define    SCS_PIN       GPIO6
#define    SCS2_PIN      GPIO8

#define    GBLK_UP       gpio_set(GPIOA, GGLK_PIN)
#define    GBLK_DWN      gpio_clear(GPIOA, GGLK_PIN)
#define    GCLK_UP       gpio_set(GPIOA, GCLK_PIN)
#define    GCLK_DWN      gpio_clear(GPIOA, GCLK_PIN)
#define    GDATA_UP      gpio_set(GPIOA, GDATA_PIN)
#define    GDATA_DWN     gpio_clear(GPIOA, GDATA_PIN)
#define    SBLK1_UP      gpio_set(GPIOA, SBLK1_PIN)
#define    SBLK1_DWN     gpio_clear(GPIOA, SBLK1_PIN)
#define    SBLK2_UP      gpio_set(GPIOA, SBLK2_PIN)
#define    SBLK2_DWN     gpio_clear(GPIOA, SBLK2_PIN)
#define    SCS_UP        gpio_set(GPIOA, SCS_PIN)
#define    SCS_DWN       gpio_clear(GPIOA, SCS_PIN)
#define    SCS2_UP       gpio_set(GPIOA, SCS2_PIN)
#define    SCS2_DWN      gpio_clear(GPIOA, SCS2_PIN)

#endif  // MAIN_H_
