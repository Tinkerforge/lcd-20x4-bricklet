#!/usr/bin/perl  

use Tinkerforge::IPConnection;
use Tinkerforge::BrickletLCD20x4;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'jup'; # Change to your UID

# Callback functions for button status
sub cb_pressed
{
    my ($i) = @_;

    print "\nPressed: $i\n";
}


sub cb_released
{
    my ($i) = @_;

    print "\nRealeased: $i\n";
}

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $lcd = Tinkerforge::BrickletLCD20x4->new(&UID, $ipcon); # Create device object

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Register button status callbacks to cb_pressed and cb_released
$lcd->register_callback($lcd->CALLBACK_BUTTON_PRESSED, 'cb_pressed');
$lcd->register_callback($lcd->CALLBACK_BUTTON_RELEASED, 'cb_released');

print "\nPress any key to exit...\n";
<STDIN>;
$ipcon->disconnect();
