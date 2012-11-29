#!/usr/bin/env ruby
# -*- ruby encoding: utf-8 -*-

require 'tinkerforge/ip_connection'
require 'tinkerforge/bricklet_lcd_20x4'

include Tinkerforge

HOST = 'localhost'
PORT = 4223
UID = '6mJ' # Change to your UID

ipcon = IPConnection.new # Create IP connection
lcd = BrickletLCD20x4.new UID, ipcon # Create device object

ipcon.connect HOST, PORT # Connect to brickd
# Don't use device before ipcon is connected

# Register button status callbacks
lcd.register_callback(BrickletLCD20x4::CALLBACK_BUTTON_PRESSED) do |i|
  puts "Pressed: #{i}"
end
lcd.register_callback(BrickletLCD20x4::CALLBACK_BUTTON_RELEASED) do |i|
  puts "Released: #{i}"
end

puts 'Press key to exit'
$stdin.gets
