#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change XYZ to the UID of your LCD 20x4 Bricklet

# Turn backlight on
tinkerforge call lcd-20x4-bricklet $uid backlight-on

# Write some strings using sed to map to the LCD charset
# Note: This assumes that the shell supports UTF-8
tinkerforge call lcd-20x4-bricklet $uid write-line 0 0\
 "`echo 'Stromstärke: 17µA' | sed 'y/\o134~¥→←°αÄäßεµςρ√¹¤¢ⱠñÖöϴ∞ΩÜüΣπ÷■/\o244\o55\o134\o176\o177\o337\o340\o341\o341\o342\o343\o344\o345\o346\o350\o351\o353\o354\o355\o356\o357\o357\o362\o363\o364\o365\o365\o366\o367\o375\o377/'`"
tinkerforge call lcd-20x4-bricklet $uid write-line 1 0\
 "`echo 'Temperatur:  23°C' | sed 'y/\o134~¥→←°αÄäßεµςρ√¹¤¢ⱠñÖöϴ∞ΩÜüΣπ÷■/\o244\o55\o134\o176\o177\o337\o340\o341\o341\o342\o343\o344\o345\o346\o350\o351\o353\o354\o355\o356\o357\o357\o362\o363\o364\o365\o365\o366\o367\o375\o377/'`"

# Write a string directly including characters from the LCD charset
tinkerforge call lcd-20x4-bricklet $uid write-line 2 0\
 "`printf 'Drehzahl:   750min\xe9'`"
