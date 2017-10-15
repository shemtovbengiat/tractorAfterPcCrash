/*
----------- config.h header  --------------
*/

// ---  SPI ---------------------
#define CLK           52      // SPI Clock, shared with SD card
#define MISO          50      // Input data, from VS1053/SD card
#define MOSI          51      // Output data, to VS1053/SD card
// ---- MP3 shield --------------
#define SHIELD_RESET  43      // VS1053 reset pin (unused!)
#define SHIELD_CS     53      // VS1053 chip select pin (output)
#define SHIELD_DCS    40      // VS1053 Data/command select pin (output)
#define CARDCS        49      // Card chip select pin
#define DREQ          20      // VS1053 Data request, ideally an Interrupt pin

// ---  O U T P U T S   ----------
#define valve1        A1      // LED 1+2 pin  // blinking motor valve pin number 
#define valve2        A2             

#define neoMotorPin    44     //data pin for engine NeoPixel   - PWM
#define neoHeadPin     45     //data pin for head light NeoPixel- PWM
#define neoBackPin     46     //data pin for back light  NeoPixel - PWM
#define neoInteriorPin 10     //data pin for interior NeoPixel - PWM
#define neoExhaostPin  11     //data pin for exhaost NeoPixel ring - PWM

#define turnL          47     // turn signal left pin to activate turn relay
#define turnR          32     // turn signal right pin to activate turn relay

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
#define wheelBtm1      26     // Bottom  1 select file to mps from path/1 librery
#define wheelBtm2      28     // Bottom   2 select file to mps from path/2 librery  
#define wheelBtm3      30     // Bottom    3 select file to mps from path/3 librery 
#define btm_l          29     //push bottom left joystick
#define btm_r          23     //push bottom right
#define btm_u          25     //push bottom up   
#define btm_d          27     //push bottom down 
#define drivePedal     31     //push pedal drive frw rev.


// --- declare All functions and XXXXIni() routines  ----

void mp3Ini();
void playSound(char* path);
void motorValvesIni();
void motorValves(bool valvesOn, bool valvesFast);
void readBottomsIni ();
void readBottoms ();
void pumpsIni();
void pumps(bool pumpsOn, int pumpsFast);
void lightValves ();  
void action();
void turnIni();
void vinkers(bool turnLOn, bool turnROn, bool turnFast); 
void turnLights();
void neopixleIni();
void driveIni();                   
//void drive(int leftMotor, int dML__en_l, int dML_pwm_l, int dML_pwm_r);                   
