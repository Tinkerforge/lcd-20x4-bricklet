package main

import (
	"fmt"
	"github.com/Tinkerforge/go-api-bindings/ipconnection"
	"github.com/Tinkerforge/go-api-bindings/lcd_20x4_bricklet"
)

const ADDR string = "localhost:4223"
const UID string = "XYZ" // Change XYZ to the UID of your LCD 20x4 Bricklet.

func main() {
	ipcon := ipconnection.New()
	defer ipcon.Close()
	lcd, _ := lcd_20x4_bricklet.New(UID, &ipcon) // Create device object.

	ipcon.Connect(ADDR) // Connect to brickd.
	defer ipcon.Disconnect()
	// Don't use device before ipcon is connected.

	lcd.RegisterButtonPressedCallback(func(button uint8) {
		fmt.Printf("Button Pressed: %d\n", button)
	})

	lcd.RegisterButtonReleasedCallback(func(button uint8) {
		fmt.Printf("Button Released: %d\n", button)
	})

	fmt.Print("Press enter to exit.")
	fmt.Scanln()
}
