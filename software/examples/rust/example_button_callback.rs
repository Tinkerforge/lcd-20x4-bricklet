use std::{error::Error, io, thread};
use tinkerforge::{ipconnection::IpConnection, lcd_20x4_bricklet::*};

const HOST: &str = "127.0.0.1";
const PORT: u16 = 4223;
const UID: &str = "XYZ"; // Change XYZ to the UID of your LCD 20x4 Bricklet

fn main() -> Result<(), Box<dyn Error>> {
    let ipcon = IpConnection::new(); // Create IP connection
    let lcd_20x4_bricklet = LCD20x4Bricklet::new(UID, &ipcon); // Create device object

    ipcon.connect(HOST, PORT).recv()??; // Connect to brickd
                                        // Don't use device before ipcon is connected

    //Create listener for button pressed events.
    let button_pressed_listener = lcd_20x4_bricklet.get_button_pressed_receiver();
    // Spawn thread to handle received events. This thread ends when the lcd_20x4_bricklet
    // is dropped, so there is no need for manual cleanup.
    thread::spawn(move || {
        for event in button_pressed_listener {
            println!("Button Pressed: {}", event);
        }
    });

    //Create listener for button released events.
    let button_released_listener = lcd_20x4_bricklet.get_button_released_receiver();
    // Spawn thread to handle received events. This thread ends when the lcd_20x4_bricklet
    // is dropped, so there is no need for manual cleanup.
    thread::spawn(move || {
        for event in button_released_listener {
            println!("Button Released: {}", event);
        }
    });

    println!("Press enter to exit.");
    let mut _input = String::new();
    io::stdin().read_line(&mut _input)?;
    ipcon.disconnect();
    Ok(())
}
