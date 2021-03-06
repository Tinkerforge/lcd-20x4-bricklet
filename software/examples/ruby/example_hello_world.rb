#!/usr/bin/env ruby
# -*- ruby encoding: utf-8 -*-

require 'tinkerforge/ip_connection'
require 'tinkerforge/bricklet_lcd_20x4'

include Tinkerforge

HOST = 'localhost'
PORT = 4223
UID = 'XYZ' # Change XYZ to the UID of your LCD 20x4 Bricklet

ipcon = IPConnection.new # Create IP connection
lcd = BrickletLCD20x4.new UID, ipcon # Create device object

ipcon.connect HOST, PORT # Connect to brickd
# Don't use device before ipcon is connected

# Turn backlight on
lcd.backlight_on

# Write "Hello World"
lcd.write_line 0, 0, 'Hello World'

puts 'Press key to exit'
$stdin.gets
ipcon.disconnect
