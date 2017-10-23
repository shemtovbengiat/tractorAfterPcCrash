/*
 TURN section.
 Turns on and off 2 arrows left and right turn/warning lights(Vinkers).
 Without using the delay() function, based on code from VALVES routine. 
 */

int turnLState = 0;                  // ledState used to set the LED
int turnRState = 0;             

unsigned long previousLMillis = 0;      // will store last time LED was updated
unsigned long previousRMillis = 0;        

long turnLRTiming = 500;                // interval at which to blink (10 fast 200 slowest in milliseconds)

// ----Turn -  Initialization  in SETUP routine--------
void turnIni()
{
	pinMode(turnL, OUTPUT);              // set the motor  Valves digital pin as output:
	pinMode(turnR, OUTPUT);
	digitalWrite(turnL, 0);
	digitalWrite(turnR, 0);
} //--- END of Ini routine 



 // --------TURN SISNALS  routine  ---------------------
void turn()   //      Lights(bool turnLOn, bool turnROn, bool turnFast)      // turnfast -( 0=slowe 1=fast )
 {
 //   bool _turnLOn = turnLOn;                     // for internal use                   
   // bool _turnROn = turnROn;                     // for internal use                   
      //bool _turnFast = turnFast;
  
   if (turnLOn==0 && turnROn==0)
      {
//        turnLRTiming = 0;                  // interval at which to blink (10 fast 200 slowest in milliseconds)
        digitalWrite(turnL, 0);            
        digitalWrite(turnR, 0);               // 1 = RELAY OFF ,pin at 0 activate relay by going ground !!!!!!!!!!!!
	  }
 /*     else if (_turnFast==0)  // motor on slow valves 
              {
                turnLRTiming = 900;                 //  slow 200 milliseconds)
                turnAction (_turnLOn, _turnROn);                     // service routine next peragaph 
              }
              else if ( _turnFast==1)
                  {
                    turnLRTiming = 400;               //  fast 60 milliseconds)
                    turnAction (_turnLOn, _turnROn);                     // service routine next peragaph 
                  }
   // return;  */                                           // do nothing with the leds go back empty
 



    // left turn first allways
	
   if (turnLOn == 1 && turnROn == 0)
		{
        unsigned long currentLMillis = millis();
        if (currentLMillis - previousLMillis >= turnLRTiming)
          {
            previousLMillis = currentLMillis;   // save the last time you blinked the LED
            // if the turn light is off turn it on and vice-versa  --- valve 1 *********************************
            if (turnLState == 0)
              {
                turnLState = 1;
              } else {
                      turnLState = 0;       // 1 = RELAY OFF ,pin at 0 activate relay by going ground !!!!!!!!!!!!
                     }
          }
        digitalWrite(turnL, turnLState);
      }
	else digitalWrite(turnL, 0);

	// right turn 
	if (turnLOn == 0 && turnROn == 1)

      {
        unsigned long currentRMillis = millis();            //  valve 2 *********************************
        if (currentRMillis - previousRMillis >= turnLRTiming)
          {
             previousRMillis = currentRMillis;   // save the last time you blinked the LED
             if (turnRState == 0)
             {
                turnRState = 1;
             } else {
                      turnRState = 0;     // 1 = RELAY OFF ,pin at 0 activate relay by going ground !!!!!!!!!!!!
                    }
          }
          digitalWrite(turnR, turnRState);   // set the LED with the ledState of the variable
      }
	else digitalWrite(turnR, 0);
} // --- END of TURNlight  routine 

 