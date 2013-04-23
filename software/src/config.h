/* lcd-bricklet
 * Copyright (C) 2011-2012 Olaf Lüke <olaf@tinkerforge.com>
 * Copyright (C) 2013 Matthias Bolte <matthias@tinkerforge.com>
 *
 * config.h: LCD Bricklet specific configuration
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>
#include <stdbool.h>

#include "bricklib/drivers/board/sam3s/SAM3S.h"

#include "lcd.h"

#define BRICKLET_FIRMWARE_VERSION_MAJOR 2
#define BRICKLET_FIRMWARE_VERSION_MINOR 0
#define BRICKLET_FIRMWARE_VERSION_REVISION 3

#define BRICKLET_DEVICE_IDENTIFIER 212

#define BOARD_MCK 64000000

#define INVOCATION_IN_BRICKLET_CODE

#define PIN_BUTTON_0   (BS->pin1_ad)
#define PIN_BUTTON_1   (BS->pin2_da)
#define PIN_BUTTON_2   (BS->pin3_pwm)
#define PIN_BUTTON_3   (BS->pin4_io)
#define PIN_RESET      (BS->pin4_io)

#define NUM_BUTTON 4

typedef struct {
	bool button_pressed[NUM_BUTTON];
	bool button_3_available;
	uint8_t port_a;
	uint8_t port_b;
	uint8_t cursor;
	uint8_t blinking;
	uint8_t hardware_version[3];
	uint8_t line;
	uint8_t position;

	int32_t default_text_counter;
	char default_text[4][20];
} BrickContext;

#endif
