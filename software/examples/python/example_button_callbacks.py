#!/usr/bin/env python
# -*- coding: utf-8 -*-  

HOST = "localhost"
PORT = 4223
UID = "XYZ" # Change to your UID

from tinkerforge.ip_connection import IPConnection
from tinkerforge.bricklet_lcd_20x4 import LCD20x4

# Callback functions for button status
def cb_pressed(i):
    print('Pressed: ' + str(i))

def cb_released(i):
    print('Released: ' + str(i))

if __name__ == "__main__":
    ipcon = IPConnection() # Create IP connection
    lcd = LCD20x4(UID, ipcon) # Create device object

    ipcon.connect(HOST, PORT) # Connect to brickd
    # Don't use device before ipcon is connected

    # Register button status callbacks to cb_pressed and cb_released
    lcd.register_callback(lcd.CALLBACK_BUTTON_PRESSED, cb_pressed)
    lcd.register_callback(lcd.CALLBACK_BUTTON_RELEASED, cb_released)

    raw_input('Press key to exit\n') # Use input() in Python 3
    ipcon.disconnect()
