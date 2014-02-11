var IPConnection = require('Tinkerforge/IPConnection');
var BrickletLCD20x4 = require('Tinkerforge/BrickletLCD20x4');

var HOST = 'localhost';
var PORT = 4223;
var UID = 'SCD32';// Change to your UID

var ipcon = new IPConnection();// Create IP connection
var lcd = new BrickletLCD20x4(UID, ipcon);// Create device object

ipcon.connect(HOST, PORT,
    function(error) {
        if(error === IPConnection.ERROR_ALREADY_CONNECTED) {
            console.log('Error: Already connected');        
        }
    }
);// Connect to brickd

// Don't use device before ipcon is connected

// Register button status callbacks
lcd.on(BrickletLCD20x4.CALLBACK_BUTTON_PRESSED,
    function(buttonNumber) {
        console.log('Pressed: '+buttonNumber);
    }
);
lcd.on(BrickletLCD20x4.CALLBACK_BUTTON_RELEASED,
    function(buttonNumber) {
        console.log('Released: '+buttonNumber);
    }
);

console.log("Press any key to exit ...");
process.stdin.on('data', function(data) {
	    ipcon.disconnect(
            function(error) {
                if(error === IPConnection.ERROR_NOT_CONNECTED) {
                    console.log('Error: Not connected');        
                }
            }
        );
process.exit(0);
});

