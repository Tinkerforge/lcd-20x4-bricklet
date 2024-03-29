<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletLCD20x4.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletLCD20x4;

const HOST = 'localhost';
const PORT = 4223;
const UID = 'XYZ'; // Change XYZ to the UID of your LCD 20x4 Bricklet

// Callback function for button pressed callback
function cb_buttonPressed($button)
{
    echo "Button Pressed: $button\n";
}

// Callback function for button released callback
function cb_buttonReleased($button)
{
    echo "Button Released: $button\n";
}

$ipcon = new IPConnection(); // Create IP connection
$lcd = new BrickletLCD20x4(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Register button pressed callback to function cb_buttonPressed
$lcd->registerCallback(BrickletLCD20x4::CALLBACK_BUTTON_PRESSED, 'cb_buttonPressed');

// Register button released callback to function cb_buttonReleased
$lcd->registerCallback(BrickletLCD20x4::CALLBACK_BUTTON_RELEASED, 'cb_buttonReleased');

echo "Press ctrl+c to exit\n";
$ipcon->dispatchCallbacks(-1); // Dispatch callbacks forever

?>
