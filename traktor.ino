/*
TRACTOR main program.
Include libreries, global variables declartion, SETUP loop and the main LOOP routin.
1. Read_bottoms - whitch checks every loop all the input bottoms and sets variables accordngly.
2. Action - here we act upon "every" (ha ha..) possible variables combinations to make the tractor as close as to a modern tractor.
3. Turn - turn singnal while driving and at all time WARNING lights.
*/

/*
Qustion to mikel
1. how to play random file from 4 libreries in sd card \1\xxx \2\xxx...?
2. interupt timer1 or regular for mp3 play music in the backround?

}*/


#define DEBUG
//---- mp3 and SD card
#include "config.h"
#include <SPI.h>
#include <SD.h>
#include <Adafruit_VS1053.h> 
// ---- adafruite motor shild V2 at pumps.routine
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

#include <Adafruit_NeoPixel.h>

#include <btsmotordriver.h>     //? ??? BTS7960MotorDriver - Version: Latest 

// ----- G L O B A L    V A R I A B L E S  set at read_Bottems.ino routine  ----------------

volatile bool motorOn = 0;              // 1 = start engine slow, light valves, pumps, fan and running mp3 starter sound. motorOn=0 all OFF
volatile int  hornPushed = 0;           // each time horn bottom pushed we get random number to play MP3 another file from horn librery
volatile bool drivePedalOn = 0;         // pedal on = 1=driving FRW REV 0= STOP  momntery sw spring !! not toggel !! 

volatile bool forwardOn = 0;            // forward on = 1 = drive with pedalOn = 1 together living pedal off cause to restart frw aging befor driving !!
volatile bool reverseOn = 0;            // reverse on = 1 = drive with pedalOn = 1 together

volatile bool turnROn = 0;              // right signal "vinker" = 1 = blinking,     0> off
volatile bool turnLOn = 0;              // left signal "vinker" = 1 = blinking,     0> off
volatile bool turnFast =0;              // turnfast 1 when motor off warning light fast rate, motor ON >slow vinker rate slow

volatile int  weelBtm1Pushed = 0;	   // wheel Bottom  # 1 Pushed > play random file from 1/ librery
volatile int  weelBtm2Pushed = 0;	   // wheel Bottom  # 2 Pushed > play random file from 2/ librery
volatile int  weelBtm3Pushed = 0;	   // wheel Bottom  # 3 Pushed > play random file from 3/ librery

volatile bool driveEnable = 0;         // safty flag variable first D or R and onlt then pedal will allow driving.!!  set at action.ino routine
volatile bool drivingFrw = 0;          // safty flag variable first joystick Forward and onlt then pedal will allow driving FOWARD.!!  set at action.ino routine
volatile bool drivingRev = 0;          // safty flag variable first joystick Reverse and onlt then pedal will allow driving REverse.!!  set at action.ino routine

volatile bool isMP3On = 0;
volatile int  driveSpeed = 100;				// to be set by the speed encoder potentiometer 0 - 255 full speed

int songCount = 0;

//  -------   S E T U  P      ROUTINE  -------------------
void setup() 
{        
	Serial.begin(9600);
	randomSeed(analogRead(0));    // for random numbers not the same every other time.

  #if defined(DEBUG)
  	Serial.println("DEBUG mode!");
  #endif
    //  --------O N L Y  initilazition routins in SETUP  !!! 
  mp3Ini();       
  valvesIni();
  readBottomsIni();
  pumpsIni();
  turnIni();
  driveIni();
  neopixleIni();

  valves(0, 0);                        // 2 leds in motor (x,y)( x- 1=blink leds 0=off,  y- 1= fast blink 0=slow blink 
  pumps(0, 0);					    // water and air pumps fan motor (0=off 1=on slow, 1=fast 0=slow)


	playSound("TRACK02.MP3");
}//---END SETUP routine  ---
  
//  -------   LOOP     ROUTINE  ---------------
void loop() 
	{
	  readBottoms();
	  turn();
	  action();
	}//---END of loop routine  -----

