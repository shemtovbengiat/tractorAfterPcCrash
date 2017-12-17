/*
----------- config.h header  --------------
*/

// ---  SPI ---------------------
#define CLK           52      // SPI Clock, shared with SD card - mp3 13
#define MISO          50      // Input data, from VS1053/SD card - mp3 12
#define MOSI          51      // Output data, to VS1053/SD card - mp3 11
// ---- MP3 shield --------------
#define SHIELD_RESET  43      // VS1053 reset pin (unused!) mp3 - mp3  8
#define SHIELD_CS     53      // VS1053 chip select pin (output)- mp3  6
#define SHIELD_DCS    40      // VS1053 Data/command select pin (output) - mp3 7
#define CARDCS        49      // Card chip select pin - mp3 9
#define DREQ          21      // VS1053 Data request, ideally an Interrupt pin - mp3 2

// ---  O U T P U T S   ----------
#define valve1        A1      // LED 1+2 pin  // blinking motor valve pin number 
#define valve2        A2             

#define neoMotorPin    44     //data pin for engine NeoPixel   - PWM
#define neoHeadPin     45     //data pin for head light NeoPixel- PWM
#define neoBackPin     46     //data pin for back light  NeoPixel - PWM
#define neoInteriorPin 10     //data pin for interior NeoPixel - PWM
#define neoExhaostPin  11     //data pin for exhaost NeoPixel ring - PWM

#define turnL          47     // turn signal left pin to activate turn relay
#define turnR          48     // turn signal right pin to activate turn relay

#define ldrmEn1         2      // left DRIVE motor
#define ldrmEn2         3
#define ldrmPwm1        4
#define ldrmPwm2        5

#define rdrmEn1         6       //right DRIVE motor
#define rdrmEn2         7
#define rdrmPwm1        8
#define rdrmPwm2        9

// ---  I N P U T S ---------------
#define btmStart       22     // Bottom  start or second press - stop motor and all functions on the motor
#define btmHorn        24     // Bottom  horn each press another playing of mp3 file from horn librery 
#define wheelBtm1      26     // Bottom  1   Black   select file to mps from path/1 librery
#define wheelBtm2      28     // Bottom   2 Red   select file to mps from path/2 librery  
#define wheelBtm3      30     // Bottom    3  Blue  select file to mps from path/3 librery 
#define btm_l          33	  //push bottom left joystick
#define btm_r          31     //push bottom right
#define btm_u          27     //push bottom up   
#define btm_d          29     //push bottom down 
#define drivePedal     32     //push pedal drive frw rev.

#define ON  1
#define OFF  0


// --- declare All functions and XXXXIni() routines  ----

void mp3Ini();
void playSound(char* path);
void valvesIni();
void valves(bool valvesOn, bool valvesFast);
void readBottomsIni ();
void readBottoms ();
void pumpsIni();
void pumps(bool pumpsOn, int pumpsFast);
void action();
void turnIni();
void turnLights(bool turnLOn, bool turnROn, bool turnFast); 
void turnLights(bool L, bool R);
void neopixleIni();
void nextSong(int i);

void driveIni();
void Drive(int l, int r, int speedL, int speedR);

void stopMotorL();
void stopMotorR();

void driveForwardL(int pwm);
void driveForwardR(int pwm);

void driveReverseL(int pwm);
void driveReversR(int pwm);
void neoMotorSnakeShow();
void stopAll();
