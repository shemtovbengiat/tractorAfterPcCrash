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

BTS7960MotorDriver Lmotor (ldrmEn1,ldrmEn2,ldrmPwm1,ldrmPwm2);     //constructor for LEFT motor class
BTS7960MotorDriver Rmotor (rdrmEn1,rdrmEn2,rdrmPwm1,rdrmPwm2);     //constructor for RIGHT motor class

// ----DRIVE INI  -  Initialization  in SETUP routine--------
void driveIni()                   
{ 
  pinMode(ldrmEn1,OUTPUT);        // Set motor pins as output  - PWM PINS !
  pinMode(ldrmEn2,OUTPUT);
  pinMode(rdrmEn1,OUTPUT);
  pinMode(rdrmEn2,OUTPUT);

  pinMode(ldrmPwm1,OUTPUT);
  pinMode(ldrmPwm2,OUTPUT);
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
/*void drive(int dML_en_l, int dML_en_l, int dML_pwm_l, int dML_pwm_r);                   
 {

      mypowermotor.Ready();
    mypowermotor.TrunRight(255);
    delay(2000);
    mypowermotor.TurnLeft(255);
    mypowermotor.Stop();
  }//--- END of DRIVE routine
  
/*
---------------.h  the header program class-------------------

  #ifndef BTS7960_H
#define BTS7960_H

#include "Arduino.h"

#define LOWER_ANALOG_LIMIT 0

class BTS7960MotorDriver
{
private:
    //int M_pin1 , M_pin2, M_PWMPin;
	int M_pin1 , M_pin2, M_RPWMPin, M_LPWMPin;

    int M_Speed;

    int turnDirection;

public:

    BTS7960MotorDriver(int, int, int, int);

    ~BTS7960MotorDriver();

    void Ready();

    void TurnLeft(int);
	
	void TurnRight(int);
    
    void Stop();

};


#endif // BTS7960_H

---------------cpp program class follows: -------------------

#include "btsmotordriver.h"

BTS7960MotorDriver::BTS7960MotorDriver(int p1, int p2, int p3, int p4)
{
    M_pin1 = p1;

    M_pin2 = p2;

    //M_RPWMPin = p3;
    M_RPWMPin = p3;
	
	M_LPWMPin = p4;
	
    pinMode(M_pin1, OUTPUT);
    
    pinMode(M_pin2, OUTPUT);
}

BTS7960MotorDriver::~BTS7960MotorDriver()
{
	
}

void BTS7960MotorDriver::Ready()
{
    digitalWrite(M_pin1, HIGH);
    digitalWrite(M_pin2, HIGH);
}


void BTS7960MotorDriver::TurnLeft(int s)
{
	M_Speed = s;
    analogWrite(M_LPWMPin, M_Speed);
}

void BTS7960MotorDriver::TurnRight(int s)
{
	M_Speed = s;
    analogWrite(M_RPWMPin, M_Speed);
}

void BTS7960MotorDriver::Stop()
{
	digitalWrite(M_LPWMPin, LOW);
	digitalWrite(M_RPWMPin, LOW);
    digitalWrite(M_pin1, LOW);
    digitalWrite(M_pin2, LOW);
}



*/

