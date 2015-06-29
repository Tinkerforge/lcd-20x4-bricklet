function octave_example_hello_world()
    more off;

    HOST = "localhost";
    PORT = 4223;
    UID = "SCD32"; % Change to your UID

    ipcon = java_new("com.tinkerforge.IPConnection"); % Create IP connection
    lcd = java_new("com.tinkerforge.BrickletLCD20x4", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Turn on LCD backlight
    lcd.backlightOn();

    % Write "Hello World"
    lcd.writeLine(0, 0, "Hello World");

    input("Press any key to exit...\n", "s");
    ipcon.disconnect();
end

