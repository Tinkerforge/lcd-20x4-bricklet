#!/usr/bin/perl  

use Tinkerforge::IPConnection;
use Tinkerforge::BrickletLCD20x4;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'jup'; # Change to your UID

$ipcon = IPConnection->new(); # Create IP connection
$lcd = BrickletLCD20x4->new(&UID, $ipcon); # Create device object

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before $ipcon is connected

# Turn backlight on
$lcd->backlight_on();

#Clearing display
$lcd->clear_display();

# Write "Hello World"
$lcd->write_line(0, 0, 'Hello World');

print "\nPress any key to exit...\n";
<STDIN>;
$ipcon->disconnect();