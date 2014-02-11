var IPConnection = require('Tinkerforge/IPConnection');
var BrickletLCD20x4 = require('Tinkerforge/BrickletLCD20x4');

var HOST = 'localhost';
var PORT = 4223;
var UID = 'SCD32';// Change to your UID

var ipcon = new IPConnection();// Create IP connection
var lcd = new BrickletLCD20x4(UID, ipcon);// Create device object

ipcon.connect(HOST, PORT,
    function(error) {
        console.log('Error: '+error);        
    }
);// Connect to brickd

// Don't use device before ipcon is connected
ipcon.on(IPConnection.CALLBACK_CONNECTED,
    function(connectReason) {
    // Turn backlight on
    lcd.backlightOn();
    // Write "Hello World"
    lcd.writeLine(0, 0, 'Hello World');     
    }
);

console.log("Press any key to exit ...");
process.stdin.on('data',
    function(data) {
        ipcon.disconnect();
        process.exit(0);
    }
);

