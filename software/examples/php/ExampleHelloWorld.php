<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletLCD20x4.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletLCD20x4;

$host = 'localhost';
$port = 4223;
$uid = '6mJ'; // Change to your UID

$ipcon = new IPConnection(); // Create IP connection
$lcd = new BrickletLCD20x4($uid, $ipcon); // Create device object

$ipcon->connect($host, $port); // Connect to brickd
// Don't use device before ipcon is connected

// Turn backlight on
$lcd->backlightOn();

// Write "Hello World"
$lcd->writeLine(0, 0, 'Hello World');

echo "Press key to exit\n";
fgetc(fopen('php://stdin', 'r'));

?>
