use std::{io, error::Error};

use tinkerforge::{ip_connection::IpConnection, 
                  lcd_20x4_bricklet::*};


const HOST: &str = "localhost";
const PORT: u16 = 4223;
const UID: &str = "XYZ"; // Change XYZ to the UID of your LCD 20x4 Bricklet.

fn main() -> Result<(), Box<dyn Error>> {
    let ipcon = IpConnection::new(); // Create IP connection.
    let lcd = Lcd20x4Bricklet::new(UID, &ipcon); // Create device object.

    ipcon.connect((HOST, PORT)).recv()??; // Connect to brickd.
    // Don't use device before ipcon is connected.

		// Turn backlight on
		lcd.backlight_on();

		// Write "Hello World"
		lcd.write_line(0, 0, "Hello World".to_string());

    println!("Press enter to exit.");
    let mut _input = String::new();
    io::stdin().read_line(&mut _input)?;
    ipcon.disconnect();
    Ok(())
}
