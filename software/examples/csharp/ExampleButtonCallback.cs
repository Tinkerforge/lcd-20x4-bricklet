using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "XYZ"; // Change to your UID

	// Callback function for button pressed callback
	static void ButtonPressedCB(BrickletLCD20x4 sender, byte buttonPressed)
	{
		System.Console.WriteLine("Button Pressed: " + buttonPressed);
	}

	// Callback function for button released callback
	static void ButtonReleasedCB(BrickletLCD20x4 sender, byte buttonReleased)
	{
		System.Console.WriteLine("Button Released: " + buttonReleased);
	}

	static void Main()
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletLCD20x4 lcd204 = new BrickletLCD20x4(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Register button pressed callback to function ButtonPressedCB
		lcd204.ButtonPressed += ButtonPressedCB;

		// Register button released callback to function ButtonReleasedCB
		lcd204.ButtonReleased += ButtonReleasedCB;

		System.Console.WriteLine("Press enter to exit");
		System.Console.ReadLine();
		ipcon.Disconnect();
	}
}
