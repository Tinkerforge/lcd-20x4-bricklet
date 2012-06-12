
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_lcd_20x4.h"

#define HOST "localhost"
#define PORT 4223
#define UID "XYZ" // Change to your UID

int main() {
	// Create IP connection to brickd
	IPConnection ipcon;
	if(ipcon_create(&ipcon, HOST, PORT) < 0) {
		fprintf(stderr, "Could not create connection\n");
		exit(1);
	}

	// Create device object
	LCD20x4 lcd;
	lcd_20x4_create(&lcd, UID); 

	// Add device to IP connection
	if(ipcon_add_device(&ipcon, &lcd) < 0) {
		fprintf(stderr, "Could not connect to Bricklet\n");
		exit(1);
	}
	// Don't use device before it is added to a connection

	// Turn backlight on
	lcd_20x4_backlight_on(&lcd);

	// Write "Hello World"
	lcd_20x4_write_line(&lcd, 0, 0, "Hello World");

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon);
}
