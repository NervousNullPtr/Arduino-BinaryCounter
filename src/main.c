#include <Arduino.h>
#include "types.h"

#define LIGHTUP_DELAY 250

void setup() {
	for (u8 i = 2; i < 10; i++)
	{
		pinMode(i, OUTPUT);
	}
	for (u8 i = 2; i < 10; i++)
	{
		digitalWrite(i, HIGH);
		delay(LIGHTUP_DELAY);
	}
	for (u8 i = 2; i < 10; i++)
	{
		digitalWrite(i, LOW);
	}
}

u8 usedPins[7] = { 9, 8, 7, 6, 5, 4, 3, 2 }; // Pins to be set low/high

void loop() {
	for (u8 num = 0; num < 256; num++) // 8 LEDs => Counting up to 2^8
	{
		for (u8 j = 0; j < 8; j++)
		{
			if ( (num & ( 0b00000001 << j ) ) >> j == 1)
			{ digitalWrite(usedPins[j], HIGH); }
			else
			{ digitalWrite(usedPins[j], LOW); }
		}

		delay(LIGHTUP_DELAY);
	}
	
}