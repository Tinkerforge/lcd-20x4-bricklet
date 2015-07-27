#!/usr/bin/env ruby
# -*- ruby encoding: utf-8 -*-

require 'tinkerforge/ip_connection'
require 'tinkerforge/bricklet_lcd_20x4'

include Tinkerforge

HOST = 'localhost'
PORT = 4223
UID = 'XYZ' # Change to your UID

ipcon = IPConnection.new # Create IP connection
lcd204 = BrickletLCD20x4.new UID, ipcon # Create device object

ipcon.connect HOST, PORT # Connect to brickd
# Don't use device before ipcon is connected

# Register button pressed callback
lcd204.register_callback(BrickletLCD20x4::CALLBACK_BUTTON_PRESSED) do |button_pressed|
  puts "Button Pressed: #{button_pressed}"
end

# Register button released callback
lcd204.register_callback(BrickletLCD20x4::CALLBACK_BUTTON_RELEASED) do |button_released|
  puts "Button Released: #{button_released}"
end

puts 'Press key to exit'
$stdin.gets
ipcon.disconnect
