/*************************************************************
 * This file was automatically generated on 23.08.2011.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICKLET_LCD_20X4_H
#define BRICKLET_LCD_20X4_H

#include "ip_connection.h"

typedef Device LCD20x4;

#define LCD_20X4_CALLBACK_BUTTON_PRESSED 9
#define LCD_20X4_CALLBACK_BUTTON_RELEASED 10

void lcd_20x4_create(LCD20x4 *lcd_20x4, const char *uid);

int lcd_20x4_write_line(LCD20x4 *lcd_20x4, uint8_t line, uint8_t position, char text[20]);
int lcd_20x4_clear_display(LCD20x4 *lcd_20x4);
int lcd_20x4_backlight_on(LCD20x4 *lcd_20x4);
int lcd_20x4_backlight_off(LCD20x4 *lcd_20x4);
int lcd_20x4_is_backlight_on(LCD20x4 *lcd_20x4, bool *ret_backlight);
int lcd_20x4_set_config(LCD20x4 *lcd_20x4, bool cursor, bool blinking);
int lcd_20x4_get_config(LCD20x4 *lcd_20x4, bool *ret_cursor, bool *ret_blinking);
int lcd_20x4_is_button_pressed(LCD20x4 *lcd_20x4, uint8_t button, bool *ret_pressed);
int lcd_20x4_button_pressed(LCD20x4 *lcd_20x4, uint8_t *ret_button);
int lcd_20x4_button_released(LCD20x4 *lcd_20x4, uint8_t *ret_button);

void lcd_20x4_register_callback(LCD20x4 *lcd_20x4, uint8_t cb, void *func);

#endif