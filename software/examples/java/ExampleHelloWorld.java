import com.tinkerforge.BrickletLCD20x4;
import com.tinkerforge.IPConnection;

public class ExampleHelloWorld {
	private static final String host = "localhost";
	private static final int port = 4223;
	private static final String UID = "ABC"; // Change to your UID
	
	// Note: To make the example code cleaner we do not handle exceptions. Exceptions you
	//       might normally want to catch are described in the commnents below
	public static void main(String args[]) throws Exception {
		// Create connection to brickd
		IPConnection ipcon = new IPConnection(host, port); // Can throw IOException
		BrickletLCD20x4 lcd = new BrickletLCD20x4(UID); // Create device object

		// Add device to IP connection
		ipcon.addDevice(lcd); // Can throw IPConnection.TimeoutException
		// Don't use device before it is added to a connection

		// Turn backlight on
		lcd.backlightOn();

		// Write "Hello World"
		lcd.writeLine((short)0, (short)0, "Hello World");

		System.out.println("Press ctrl+c to exit");
		ipcon.joinThread();
	}
}