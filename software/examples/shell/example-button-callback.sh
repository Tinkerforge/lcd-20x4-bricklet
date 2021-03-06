#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change XYZ to the UID of your LCD 20x4 Bricklet

# Handle incoming button pressed callbacks
tinkerforge dispatch lcd-20x4-bricklet $uid button-pressed &

# Handle incoming button released callbacks
tinkerforge dispatch lcd-20x4-bricklet $uid button-released &

echo "Press key to exit"; read dummy

kill -- -$$ # Stop callback dispatch in background
