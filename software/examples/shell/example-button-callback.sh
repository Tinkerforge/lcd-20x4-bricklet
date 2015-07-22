#!/bin/sh
# connects to localhost:4223 by default, use --host and --port to change it

# change to your UID
uid=XYZ

# handle incoming pressed and released callbacks
# note: this chaining of two dispatches assumes that a pressed callback is
#       always followed by a released callback for the same button
tinkerforge dispatch lcd-20x4-bricklet $uid button-pressed\
 --execute "echo Pressed: {button};
            tinkerforge dispatch --duration exit-after-first lcd-20x4-bricklet $uid button-released\
             --execute 'echo Released: {button}'"
