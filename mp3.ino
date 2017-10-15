/*
befor trying to play muisc be sure that the mp3On flag is true "isMP3On"
*/

Adafruit_VS1053_FilePlayer musicPlayer = Adafruit_VS1053_FilePlayer(SHIELD_RESET, SHIELD_CS, SHIELD_DCS, DREQ, CARDCS);

bool isMP3On = false;

void printDirectory(File dir, int numTabs);



 // ---- mp3   Initialization  --------
void mp3Ini() {                    

#if defined(DEBUG)
	Serial.println("MP3 inishlizing");
#endif
	if (!musicPlayer.begin()) { // initialise the music player
#if defined(DEBUG)
		Serial.println("Couldn't find VS1053, do you have the right pins defined?");
#endif
		isMP3On = false;
		return;
	}
#if defined(DEBUG)
	Serial.println("VS1053 found");
#endif


	if (!SD.begin(CARDCS)) {
#if defined(DEBUG)
		Serial.println("SD failed, or not present");
#endif

		isMP3On = false;
		return;
	}

	isMP3On = true;
	// list files
	if (isMP3On) {
#if defined(DEBUG)
		printDirectory(SD.open("/"), 0);
#endif

		// Set volume for left, right channels. lower numbers == louder volume!
		musicPlayer.setVolume(15,15);
 // Timer interrupts are not suggested, better to use DREQ interrupt!
  //musicPlayer.useInterrupt(VS1053_FILEPLAYER_TIMER0_INT); // timer int
		musicPlayer.useInterrupt(VS1053_FILEPLAYER_TIMER0_INT);  ///   check with mickel  no to use TIMER0_INT  !!!!!!!!!!!!!!!!!!!!!!
	}//---END of mp# inisilaztion routine

}

/*
this is to start a sound,  give it the path to the file
*/
void playSound(char* path)
    {
      #if defined(DEBUG)
      	Serial.print("playing file: ");
      	Serial.println(path);
      #endif
    	// Start playing a file, then we can do stuff while waiting for it to finish
    	if (!musicPlayer.startPlayingFile(path)) {
    		Serial.println("Could not open file track02.mp3");
    		while (1);                                          //  stucks the program!!!! need RESET
    	}
    	Serial.println("Started playing");
//     return;
    }

















/// File listing helper
void printDirectory(File dir, int numTabs) {
	while (true) {

		File entry = dir.openNextFile();
		if (!entry) {
			// no more files
			//Serial.println("**nomorefiles**");
			break;
		}
		for (uint8_t i = 0; i<numTabs; i++) {
			Serial.print('\t');
		}
		Serial.print(entry.name());
		if (entry.isDirectory()) {
			Serial.println("/");
			printDirectory(entry, numTabs + 1);
		}
		else {
			// files have sizes, directories do not
			Serial.print("\t\t");
			Serial.println(entry.size(), DEC);
		}
		entry.close();
	}
}