#!/usr/bin/env python
# -*- coding: utf-8 -*-

HOST = "localhost"
PORT = 4223
UID = "XYZ" # Change XYZ to the UID of your LCD 20x4 Bricklet

from tinkerforge.ip_connection import IPConnection
from tinkerforge.bricklet_lcd_20x4 import BrickletLCD20x4

# Callback function for button pressed callback
def cb_button_pressed(button):
    print("Button Pressed: " + str(button))

# Callback function for button released callback
def cb_button_released(button):
    print("Button Released: " + str(button))

if __name__ == "__main__":
    ipcon = IPConnection() # Create IP connection
    lcd = BrickletLCD20x4(UID, ipcon) # Create device object

    ipcon.connect(HOST, PORT) # Connect to brickd
    # Don't use device before ipcon is connected

    # Register button pressed callback to function cb_button_pressed
    lcd.register_callback(lcd.CALLBACK_BUTTON_PRESSED, cb_button_pressed)

    # Register button released callback to function cb_button_released
    lcd.register_callback(lcd.CALLBACK_BUTTON_RELEASED, cb_button_released)

    input("Press key to exit\n") # Use raw_input() in Python 2
    ipcon.disconnect()
