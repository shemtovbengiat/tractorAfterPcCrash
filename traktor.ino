/*

*/

// define the pins used for UNO for MEGA connect to 50 51 52 instead 
#include "config.h"
#include <SPI.h>
#include <SD.h>
#include <Adafruit_VS1053.h> 

#define DEBUG


void setup() {
	Serial.begin(9600);
#if defined(DEBUG)
	Serial.println("DEBUG mode!");
#endif
	mp3Ini();


}

void loop() {

	if (Serial.available()) {
		Serial.read();
		playSound("TRACK001.MP3");
	}
}

