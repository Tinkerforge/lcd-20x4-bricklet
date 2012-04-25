using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "ABC"; // Change to your UID

	// Callback functions for button status
	static void PressedCB(byte button)
	{
		System.Console.WriteLine("Pressed: " + button);
	}

	static void ReleasedCB(byte button)
	{
		System.Console.WriteLine("Released: " + button);
	}

	static void Main() 
	{
		IPConnection ipcon = new IPConnection(HOST, PORT); // Create connection to brickd
		BrickletLCD20x4 lcd = new BrickletLCD20x4(UID); // Create device object
		ipcon.AddDevice(lcd); // Add device to IP connection
		// Don't use device before it is added to a connection

		// Register callbacks for pressed and released events
		lcd.RegisterCallback(new BrickletLCD20x4.ButtonPressed(PressedCB));
		lcd.RegisterCallback(new BrickletLCD20x4.ButtonReleased(ReleasedCB));

		System.Console.WriteLine("Press ctrl+c to exit");
		ipcon.JoinThread();
	}
}
