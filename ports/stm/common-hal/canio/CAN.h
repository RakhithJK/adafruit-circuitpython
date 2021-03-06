/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2020 Jeff Epler for Adafruit Industries
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#pragma once

#include "py/obj.h"
#include "shared-bindings/canio/__init__.h"
#include "shared-bindings/canio/CAN.h"
#include "common-hal/microcontroller/Pin.h"
#include "common-hal/canio/__init__.h"
#include "shared-module/canio/Message.h"

#include STM32_HAL_H

#define FILTER_BANK_COUNT (28)

typedef struct canio_can_obj {
    mp_obj_base_t base;
    CAN_HandleTypeDef handle;
    CAN_TypeDef *filter_hw;
    int baudrate;
    const mcu_pin_obj_t *rx_pin;
    const mcu_pin_obj_t *tx_pin;
    bool loopback : 1;
    bool silent : 1;
    bool auto_restart : 1;
    bool fifo0_in_use : 1;
    bool fifo1_in_use : 1;
    uint8_t periph_index : 2;
    uint8_t cancel_mailbox;
    uint8_t start_filter_bank;
    uint8_t end_filter_bank;
    long filter_in_use; // bitmask for the 28 filter banks
} canio_can_obj_t;
