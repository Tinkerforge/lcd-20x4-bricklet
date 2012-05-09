<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletLCD20x4.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletLCD20x4;

$host = 'localhost';
$port = 4223;
$uid = '6mJ'; // Change to your UID

// Callback functions for button status
function cb_pressed($i)
{
    echo "Pressed: $i\n";
}

function cb_released($i)
{
    echo "Released: $i\n";
}

$ipcon = new IPConnection($host, $port); // Create IP connection to brickd
$lcd = new BrickletLCD20x4($uid); // Create device object

$ipcon->addDevice($lcd); // Add device to IP connection
// Don't use device before it is added to a connection

// Register button status callbacks to cb_pressed and cb_released
$lcd->registerCallback(BrickletLCD20x4::CALLBACK_BUTTON_PRESSED, 'cb_pressed');
$lcd->registerCallback(BrickletLCD20x4::CALLBACK_BUTTON_RELEASED, 'cb_released');

echo "Press ctrl+c to exit\n";
$ipcon->dispatchCallbacks(-1); // Dispatch callbacks forever

?>
