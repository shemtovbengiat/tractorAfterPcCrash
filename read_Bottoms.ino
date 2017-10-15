/*
reads all the bottoms and ?  ???  set an interupt to get attention from main routine
*/

bool btmStartState = 0;       // Strat / Stop
bool lastbtmStartState =0;
int btmHornState = 0;         // horn
int lastbtmHornState =0;
int wheelBtm1State = 0;       // wheel bottom # 1 clockwise from 12 oclock
int lastWheelBtm1State =0;
int wheelBtm2State = 0;       // wheel bottom # 1 clockwise from 12 oclock
int lastWheelBtm2State =0;
int wheelBtm3State = 0;       // wheel bottom # 1 clockwise from 12 oclock
int lastWheelBtm3State =0;
int btm_lState = 0;           // Left turn signal
int lastbtm_lState =0;
int btm_rState = 0;           // Right turn signal
int lastbtm_rState =0;
int btm_uState = 0;           // Up = Forward drive
int lastbtm_uState =0;
int btm_dState = 0;           // Down = Reverse drive
int lastbtm_dState =0;
int drivePedalState = 0;      // Foot Pedal for drive FRW. & REV.
int lastDrivePedalState =0;

long lastTime = 0;

void readBottomsIni ()  // ---   initionlize in SETUP routine ----     
{
    pinMode(btmStart,  INPUT_PULLUP);    // define all bottoms with pullup resistor      
    pinMode(btmHorn,   INPUT_PULLUP);       
    pinMode(wheelBtm1, INPUT_PULLUP);     
    pinMode(wheelBtm2, INPUT_PULLUP);     
    pinMode(wheelBtm3, INPUT_PULLUP);     
    pinMode(btm_l,     INPUT_PULLUP);         
    pinMode(btm_r,     INPUT_PULLUP);         
    pinMode(btm_u,     INPUT_PULLUP);          
    pinMode(btm_d,     INPUT_PULLUP);         
    pinMode(drivePedal,INPUT_PULLUP);    
}  // --- END of readBottoms INI rotine

// ----  Called from whithin LOOP routine
void readBottoms ()         
{
// --------------------------------------------- btm  START ENGINE -MOTOR ON-------------------------
	btmStartState = digitalRead(btmStart);
	if (btmStartState != lastbtmStartState)
	{
		if (btmStartState == LOW && (lastTime + 100) < millis())
		{
			lastTime = millis();
			Serial.println(" [ START  ] ");
			motorOn = !motorOn;
		}
	}
	lastbtmStartState = btmStartState;

// ----------------------------  ------------------ btm HORN -HORN PUSHED-------------------------
    btmHornState = digitalRead(btmHorn);
    if (btmHornState != lastbtmHornState) 
      {
        if (btmHornState == LOW) 
          {
            Serial.println(" [ HORN  ] ");
            
            hornPushed = random (0,10);
          }
      }
        lastbtmHornState = btmHornState;

// -------------------------------------------------- btm  RIGHT SIGNAL- -turnROn------------------------

    btm_rState = digitalRead(btm_r);
    if (btm_rState != lastbtm_rState)
      {
        if (btm_rState == LOW) 
          {
            Serial.println(" [ Right Turn ] ");
            
            turnROn = !turnROn;         // toggel switch !!!
          }
      }
        lastbtm_rState = btm_rState;
        
// -------------------------------------------------- btm  LEFT SIGNAL-turnLOn-------------------------

      btm_lState = digitalRead(btm_l);
      if (btm_lState != lastbtm_lState) 
        {
          if (btm_lState == LOW)  
            {
              Serial.println(" [ Left Turn ] ");
           
              turnLOn = !turnLOn;       // toggel switch !!!
            }
        }
      lastbtm_lState = btm_lState;
 
// ------------------------------------------- btm   DOWN = REVERSE --reverseOn------------------------
      btm_dState = digitalRead(btm_d);
      if (btm_dState != lastbtm_dState)
        {
          if (btm_dState == LOW) 
            {
              Serial.println("[ REVERSE ]");
              
              reverseOn = !reverseOn;         // toggel switch !!!
             }
        }
      lastbtm_dState = btm_dState;
 
// ------------------------------------------- btm  UP = FORWARD ---forwardOn-----------------------
      btm_uState = digitalRead(btm_u);
      if (btm_uState != lastbtm_uState)
        {
          if (btm_uState == LOW) 
            {
              Serial.println("[ FORWARD ]");
           
              forwardOn =!forwardOn;          // toggel switch !!!
             }
        }
      lastbtm_uState = btm_uState;

// -------------------------------------------------- WHEEL BOTTOM # 1  ----wheelBottom1Pushed----------------------

      wheelBtm1State = digitalRead(wheelBtm1);
      if (wheelBtm1State != lastWheelBtm1State) 
        {
          if (wheelBtm1State == LOW)  
            {
              Serial.println(" [ WHEEL SW  1  ] ");
            
              wheelBottom1Pushed = random( 1,11);         // random switch !!!!!!!!!!!!!!!!!!!!
            }
        }
      lastWheelBtm1State = wheelBtm1State;
      
// -------------------------------------------------- WHEEL BOTTOM # 2  --------------------------

      wheelBtm2State = digitalRead(wheelBtm2);
      if (wheelBtm2State != lastWheelBtm2State) 
        {
          if (wheelBtm2State == LOW)  
            {
              Serial.println(" [ WHEEL SW  2  ] ");
          
              wheelBottom2Pushed = random( 2,12);       // random switch !!!!!!!!!!!!!!!!!!!!
            }
        }
      lastWheelBtm2State = wheelBtm2State;

// -------------------------------------------------- WHEEL BOTTOM # 3  --------------------------

      wheelBtm3State = digitalRead(wheelBtm3);
      if (wheelBtm3State != lastWheelBtm3State) 
        {
          if (wheelBtm3State == LOW)  
            {
              Serial.println(" [ WHEEL SW  3  ] ");
             
              wheelBottom3Pushed = random( 3,13);       // random switch !!!!!!!!!!!!!!!!!!!!
            }
        }
      lastWheelBtm3State = wheelBtm3State;

// -------------------------------------------------- Drive Pedal  ---drivePedalOn-----------------------

      drivePedalState = digitalRead(drivePedal);
      if (drivePedalState != lastDrivePedalState) 
        {
          if (drivePedalState == LOW)  
            {
              Serial.println(" [ Drive Pedal  ] ");
          
              drivePedalOn = 1;                 //  S A F T Y   switch 
            }
            else drivePedalOn = 0;              // only MOMENTARY witch  on when pushed OFF when not pushed
        }
      lastDrivePedalState = drivePedalState;
      
      if (drivePedalOn = 1 && motorOn==1 && (forwardOn==1 || reverseOn==1))
        {
          driveEnable=1;    // S A F A T Y  fleg !!!
        }
          else driveEnable=0;
        
}// ----END read bottoms routine   ---------------------  


