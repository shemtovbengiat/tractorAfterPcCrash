

/* 
Drive.ino - controls 2 43A BTS-7960 MOTOR DRIVERs.
Both work together for power sake only (later will test steering with the 2 motoe but each its own direction)

Drive in enabled only if motorOn=1-START pushed, joystick pushed forward or reverse driveLOn or driveROn and then if pedalOn=1 DRIVE pedalOn=0 stop.  
Code for BTS7960 Motor driver uses CLASS - BTS7960MotorDriver at: http://wordpress.bonairetec.com/?p=75
The class has 4 commands: stop() - all 4 pins go 0,
                          ready() [drive Eenable] 2 enable pins 1 and 2 go high, 
                          turnleft(0-255) clockwise - forwared at speed 0-255 to be set by rotary encoder later on 
                          turnRight(0-255) counter clockwise - reverse  at speed 0-255 to be set by rotary encoder later on 
*/

//BTS7960MotorDriver Lmotor (ldrmEn1,ldrmEn2,ldrmPwm1,ldrmPwm2);     //constructor for LEFT motor class
//BTS7960MotorDriver Rmotor (rdrmEn1,rdrmEn2,rdrmPwm1,rdrmPwm2);     //constructor for RIGHT motor class

// ----DRIVE INI  -  Initialization  in SETUP routine--------


void driveIni()
{
  pinMode(ldrmEn1,OUTPUT);        // Set motor pins as output  - PWM PINS !
  pinMode(ldrmEn2,OUTPUT);
  pinMode(ldrmPwm1,OUTPUT);
  pinMode(ldrmPwm2,OUTPUT);

  pinMode(rdrmEn1,OUTPUT);
  pinMode(rdrmEn2,OUTPUT);
  pinMode(rdrmPwm1,OUTPUT);
  pinMode(rdrmPwm2,OUTPUT);
  
  pinMode(ldrmEn1,LOW);           // Varify motor stops at startup 
  pinMode(ldrmEn2,LOW);
  pinMode(rdrmEn1,LOW);
  pinMode(rdrmEn2,LOW);

  pinMode(ldrmPwm1,LOW);
  pinMode(ldrmPwm2,LOW);
  pinMode(rdrmPwm1,LOW);
  pinMode(rdrmPwm2,LOW);

  } //--- END of Ini routine 



// ---------  drive motors routine ---------------------------------
void Drive(int l, int r, int driveSpeed)
{
	//0 =stop, 1 = forward, 2 = reverse
	if (l == 0)	stopMotorL;
	else if (l == 1) driveForwardL(driveSpeed);
	//else if (l == 2) driveReverseR(driveSpeed);

	if (r == 0)	stopMotorR();
	else if (r == 1) driveForwardR(driveSpeed);
	//else if (r == 2) driveReverseR(driveSpeed);



}


