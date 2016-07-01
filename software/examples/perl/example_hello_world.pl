#!/usr/bin/perl

use Tinkerforge::IPConnection;
use Tinkerforge::BrickletLCD20x4;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'XYZ'; # Change XYZ to the UID of your LCD 20x4 Bricklet

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $lcd = Tinkerforge::BrickletLCD20x4->new(&UID, $ipcon); # Create device object

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Turn backlight on
$lcd->backlight_on();

# Write "Hello World"
$lcd->write_line(0, 0, "Hello World");

print "Press key to exit\n";
<STDIN>;
$ipcon->disconnect();
