function octave_example_button_callbacks
    more off;
    
    HOST = "localhost";
    PORT = 4223;
    UID = "SCD32"; % Change to your UID

    ipcon = java_new("com.tinkerforge.IPConnection"); % Create IP connection
    lcd = java_new("com.tinkerforge.BrickletLCD20x4", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Register button status callbacks to cb_pressed and cb_released
    lcd.addButtonPressedListener("cb_pressed");
    lcd.addButtonReleasedListener("cb_released");

    input("\nPress any key to exit...\n", "s");
    ipcon.disconnect();
end

% Callback functions for button status
function cb_pressed(i)
    fprintf("Pressed: %s\n", i.toString());
end

function cb_released(i)
    fprintf("Released: %s\n", i.toString());
end
