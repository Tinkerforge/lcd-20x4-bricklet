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

# Register button pressed callback
lcd.register_callback(BrickletLCD20x4::CALLBACK_BUTTON_PRESSED) do |button|
  puts "Button Pressed: #{button}"
end

# Register button released callback
lcd.register_callback(BrickletLCD20x4::CALLBACK_BUTTON_RELEASED) do |button|
  puts "Button Released: #{button}"
end

puts 'Press key to exit'
$stdin.gets
ipcon.disconnect
