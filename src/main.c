#include <Arduino.h>
#include "types.h"

#define LIGHTUP_DELAY 250

u8 usedPins[8] = { 9, 8, 7, 6, 5, 4, 3, 2 };

void setup() {
	for (u8 i = 0; i < 8; i++)
	{ pinMode(usedPins[i], OUTPUT); }  // Set all used pins to OUTPUT mode

	for (u8 i = 0; i < 8; i++) {
		digitalWrite(usedPins[i], HIGH); // Show that everything is running
		delay(LIGHTUP_DELAY);  			 // Delay, so that it doesn't turn off instantly
	}

	for (u8 i = 0; i < 8; i++)
	{ digitalWrite(usedPins[i], LOW); } // Turn of every LED
}

void loop() {
	for (u8 num = 0; num < 256; num++) { // 8 LEDs => Counting up to 2^8

		for (u8 j = 0; j < 8; j++) {

			if ( (num & ( 0b00000001 << j ) ) >> j == 1)
			{ digitalWrite(usedPins[j], HIGH); }
			else
			{ digitalWrite(usedPins[j], LOW); }
		}
		
		delay(LIGHTUP_DELAY);
	}
}