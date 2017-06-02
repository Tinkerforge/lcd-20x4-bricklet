function octave_example_hello_world()
    more off;

    HOST = "localhost";
    PORT = 4223;
    UID = "XYZ"; % Change XYZ to the UID of your LCD 20x4 Bricklet

    ipcon = javaObject("com.tinkerforge.IPConnection"); % Create IP connection
    lcd = javaObject("com.tinkerforge.BrickletLCD20x4", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Turn backlight on
    lcd.backlightOn();

    % Write "Hello World"
    lcd.writeLine(0, 0, "Hello World");

    input("Press key to exit\n", "s");
    ipcon.disconnect();
end
