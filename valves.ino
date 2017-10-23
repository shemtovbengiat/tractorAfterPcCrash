/*
 VALVES section.
 Turns on and off 2 (LED) connected to " valves " on the motor,
 Without using the delay() function. code taken from: https://learn.adafruit.com/multi-tasking-the-arduino-part-1/using-millis-for-timing
*/

bool valvesOn = 0;                  // 0-leds off 1-leds on fast or slow to be changed by calling routine !
bool valvesFast = 0;                // 0-slow 1 fast - motorVales(x,valesFast)
int valve1State = LOW;                  // ledState used to set the LED
int valve2State = LOW;
unsigned long previous1Millis = 0;      // will store last time LED was updated
unsigned long previous2Millis = 0;        

long OnTime1 = 0;          //blink 5-on time igition till about 25msec for fast motor whilde driving
long OffTime1 = 0;         
long OnTime2 = 0;          
long OffTime2 = 0;      

// ----valves   Initialization  in SETUP routine--------
void valvesIni() {                    
    pinMode(valve1, OUTPUT);              // set the motor  Valves digital pin as output:
    pinMode(valve2, OUTPUT);
	}// END of INI routine 


// ------------------- Motor Valves routine  -----------------------

void valves(bool valvesOn, bool valvesFast) {
	   if (valvesOn==0)
		  {
			digitalWrite(valve1, 0);
			digitalWrite(valve2, 0);
		  }
		  else if (valvesFast==0)  // motor on slow valves
				{
				OnTime1 = 15;
				OffTime1 = 770;
				OnTime2 = 15;
				OffTime2 = 800;
				lightValves();			// service routine next peragaph 
				return;
				}
		if (valvesOn==1 && valvesFast==1)
				{
				OnTime1 = 10;
				OffTime1 = 280;
				OnTime2 = 10;
				OffTime2 = 300;
				lightValves();                  // service routine next peragaph 
				}
}// END of VALVES routine

void lightValves() {  // ---- light valve sub routine according to fast=1 or slow=0 (1/2 speed)

	unsigned long currentMillis = millis();
	//  --- valve 1
	if ((valve1State == 1) && (currentMillis - previous1Millis >= OnTime1))
	{
		valve1State = 0;  // Turn it off
		previous1Millis = currentMillis;  // Remember the time
		digitalWrite(valve1, valve1State);  // Update the actual LED
	}
	else if ((valve1State == 0) && (currentMillis - previous1Millis >= OffTime1))
	{
		valve1State = 1;  // turn it on
		previous1Millis = currentMillis;   // Remember the time
		digitalWrite(valve1, valve1State);	  // Update the actual LED
	}

	// -----valve 2 

	if ((valve2State == 1) && (currentMillis - previous2Millis >= OnTime2))
	{
		valve2State = 0;  // Turn it off
		previous2Millis = currentMillis;  // Remember the time
		digitalWrite(valve2, valve2State);  // Update the actual LED
	}
	else if ((valve2State == 0) && (currentMillis - previous2Millis >= OffTime2))
	{
		valve2State = 1;  // turn it on
		previous2Millis = currentMillis;   // Remember the time
		digitalWrite(valve2, valve2State);	  // Update the actual LED
	}
}
 //- END of lightValves routine