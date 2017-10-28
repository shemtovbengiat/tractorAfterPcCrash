/*
 ACTION section.
 We make decisions on what to do with the inputs from READ BOTTOMS routine and ACT on outputs based on global variables
 */
 
void action()
{
	/* --------  MOTOR section- pumps, valves, neopixle, sound and speed section  -------------------------

	1. If START pushbottom NOT pushed - all functions are disabled (pumps, valves, motorNeopixle, sound).
	2. DRIVEENABLE variable is a flag that assurs that no driving F or R of the tractor will occer if  motor
	   is not started, then drive F or R is selected and then if pedal is 1 then driveEnable=1, if pedal is 0 then
	   driveEnable=0.
   3.  if motor started and driveEnable=0 then pumps + motorNeopixle + valves start at slow speed "1000 rpm"
   */
	if (motorOn == 0)         // start bottom not pushed  yet.. - DO Nothing
		{
			//drive(0,0)							// stop l and r motors
			//musicPlayer.stopPlaying();          //---- האם נכון?    not right should be playSound()
			valves(0, 0);                        // 2 leds in motor (x,y)( x- 1=blink leds 0=off,  y- 1= fast blink 0=slow blink 
			pumps(0, 0);					    // water and air pumps fan motor (0=off 1=on slow, 1=fast 0=slow)
			//motorNeopixle(0,0);                    // 42 neopixle on board thee motor base (1,2)(1- 1=blink  0=off, 2- 1= fast blink 0=slow blink                                
			//musicPlayer.sineTest(0x44, 500);       // Make a tone to indicate VS1053 is working
			//Serial.println(isMP3On);
			return;
		}

	if (motorOn == 1 && driveEnable == 0)          //   START bottom pushed motorOn ==1
		{
			// drive(0,0)						// stop l and r motors
			valves(1, 0);                    //rpm 1000 = slow
			pumps(1, 0);                          // water and air pumps fan motor (0=off 1=on slow, 1=fast 0=slow)
			//playSound("TRACK02.MP3");          // low rpm sound 1000rpm
			return;
		}

	if (motorOn == 1 && driveEnable == 1)       // verify that no driving if first set F or R and only then drive pedal push
		{
			//playSound.sineTest(0x44, 500);    // Make a tone to indicate VS1053 is working
			valves(1, 1);						//rpm  = fast
			pumps(1, 1);                        //rpm  = fast
			//motorNeopixle(1,0);               //rate  = fast
			//playSound("TRACK03.MP3");         // High  rpm sound 
			if (drivePedal == 1) 
				{
					if (forwardOn == 1) Drive(1, 1, driveSpeed);		// 0-stop 1-frw 2-rev
					if (reverseOn == 1) Drive(2, 2, driveSpeed);
				}
				else if (drivePedal == 0) {
					valves(1, 0);
					pumps(1, 0);
					Drive(0, 0, 0);
					}
	//				return;
		}

	/* -----------TURN SIGNALS - TURN L or R signal, turn L and R togther as WARNING Light Section ---------------

	  If motor did not start yet then each L or R  push will activate both L+R "warning lights" fast
	  If motor started then pushing ether R or L will activate L or R turn signal on slow,
	  Either way deactivating is done by pushing again the R or left whitch ever was pushed first.

		example:1. no start pushed, L pushed warning light will flash bothe R and L, pushing L again will shut off L+R
				2. start phushed motor run all functions, pushing either L or R will activate L or R  respectivly,
				   pushing L agian will shut down L and pushing R agian will shut down R.
	*/
	Serial.println(turnROn, turnLOn); // toggel switch !!!

/*	if (turnLOn == 0 && turnROn == 0)         //no start bottom pushed DO Nothing with the turn lights
	{
		turnLights(0, 0, 0);
	return;                           // no vinkers
	}

	if ((turnLOn == 1 && turnROn == 0) && motorOn == 1)         //left vinker (slow)
	{
		turnLights(1, 0, 0); // left turn signal
		turnLOn == 0;
	return;
	}
	if ((turnLOn == 0 && turnROn == 1) && motorOn == 1)         //right vinker (slow)
	{
		turnLights(0, 1, 0);                        // right turn  signal
	return;
	}

	if ((turnLOn == 1 || turnROn == 1) && driveEnable == 1)
	{
		turnLights(1, 1, 1);                        // both l and r together - fat warning lights
		return;
	}
	else if ((turnLOn == 1 && turnROn == 0) && motorOn == 0) turnLights(0, 0, 0);
	else if ((turnLOn == 0 && turnROn == 1) && motorOn == 0) turnLights(0, 0, 0);

}//---END of ACTION routine
*/

/* -----------DRIVE section activating the drive motors---------------
1. If motor not started then push START to activate motorON=1
2. Motor activated, select forward or reverse on the joystick. forwardOn=1 or reverseOn=1
3. push DRIVE PEDAL to drive frw. or rev. pedalOn = 1
*/
 
