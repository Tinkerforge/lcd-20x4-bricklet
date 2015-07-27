import com.tinkerforge.IPConnection;
import com.tinkerforge.BrickletLCD20x4;

public class ExampleButtonCallback {
	private static final String HOST = "localhost";
	private static final int PORT = 4223;
	private static final String UID = "XYZ"; // Change to your UID

	// Note: To make the example code cleaner we do not handle exceptions. Exceptions you
	//       might normally want to catch are described in the documentation
	public static void main(String args[]) throws Exception {
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletLCD20x4 lcd204 = new BrickletLCD20x4(UID, ipcon); // Create device object

		ipcon.connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Add button pressed listener
		lcd204.addButtonPressedListener(new BrickletLCD20x4.ButtonPressedListener() {
			public void buttonPressed(short buttonPressed) {
				System.out.println("Button Pressed: " + buttonPressed);
			}
		});

		// Add button released listener
		lcd204.addButtonReleasedListener(new BrickletLCD20x4.ButtonReleasedListener() {
			public void buttonReleased(short buttonReleased) {
				System.out.println("Button Released: " + buttonReleased);
			}
		});

		System.out.println("Press key to exit"); System.in.read();
		ipcon.disconnect();
	}
}
