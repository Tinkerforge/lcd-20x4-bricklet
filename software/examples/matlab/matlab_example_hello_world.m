function matlab_example_hello_world()
    import com.tinkerforge.IPConnection;
    import com.tinkerforge.BrickletLCD20x4;

    HOST = 'localhost';
    PORT = 4223;
    UID = 'XYZ'; % Change XYZ to the UID of your LCD 20x4 Bricklet

    ipcon = IPConnection(); % Create IP connection
    lcd = handle(BrickletLCD20x4(UID, ipcon), 'CallbackProperties'); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Turn backlight on
    lcd.backlightOn();

    % Write "Hello World"
    lcd.writeLine(0, 0, 'Hello World');

    input('Press key to exit\n', 's');
    ipcon.disconnect();
end
