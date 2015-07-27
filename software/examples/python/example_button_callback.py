#!/usr/bin/env python
# -*- coding: utf-8 -*-

HOST = "localhost"
PORT = 4223
UID = "XYZ" # Change to your UID

from tinkerforge.ip_connection import IPConnection
from tinkerforge.bricklet_lcd_20x4 import LCD20x4

# Callback function for button pressed callback
def cb_button_pressed(button_pressed):
    print('Button Pressed: ' + str(button_pressed))

# Callback function for button released callback
def cb_button_released(button_released):
    print('Button Released: ' + str(button_released))

if __name__ == "__main__":
    ipcon = IPConnection() # Create IP connection
    lcd204 = LCD20x4(UID, ipcon) # Create device object

    ipcon.connect(HOST, PORT) # Connect to brickd
    # Don't use device before ipcon is connected

    # Register button pressed callback to function cb_button_pressed
    lcd204.register_callback(lcd204.CALLBACK_BUTTON_PRESSED, cb_button_pressed)

    # Register button released callback to function cb_button_released
    lcd204.register_callback(lcd204.CALLBACK_BUTTON_RELEASED, cb_button_released)

    raw_input('Press key to exit\n') # Use input() in Python 3
    ipcon.disconnect()
