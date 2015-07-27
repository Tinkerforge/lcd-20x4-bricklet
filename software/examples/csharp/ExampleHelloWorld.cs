using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "XYZ"; // Change to your UID

	static void Main()
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletLCD20x4 lcd204 = new BrickletLCD20x4(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Turn backlight on
		lcd204.BacklightOn();

		// Write "Hello World"
		lcd204.WriteLine(0, 0, "Hello World");

		System.Console.WriteLine("Press enter to exit");
		System.Console.ReadLine();
		ipcon.Disconnect();
	}
}
