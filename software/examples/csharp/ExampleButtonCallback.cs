using System;
using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "XYZ"; // Change XYZ to the UID of your LCD 20x4 Bricklet

	// Callback function for button pressed callback
	static void ButtonPressedCB(BrickletLCD20x4 sender, byte button)
	{
		Console.WriteLine("Button Pressed: " + button);
	}

	// Callback function for button released callback
	static void ButtonReleasedCB(BrickletLCD20x4 sender, byte button)
	{
		Console.WriteLine("Button Released: " + button);
	}

	static void Main()
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletLCD20x4 lcd = new BrickletLCD20x4(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Register button pressed callback to function ButtonPressedCB
		lcd.ButtonPressed += ButtonPressedCB;

		// Register button released callback to function ButtonReleasedCB
		lcd.ButtonReleased += ButtonReleasedCB;

		Console.WriteLine("Press enter to exit");
		Console.ReadLine();
		ipcon.Disconnect();
	}
}
