

// ---- SPI ----
// Connect CLK, MISO and MOSI to hardware SPI pins. 
// See http://arduino.cc/en/Reference/SPI "Connections"

#define CLK 52       // SPI Clock, shared with SD card
#define MISO 50      // Input data, from VS1053/SD card
#define MOSI 51      // Output data, to VS1053/SD card

// ---- SPI End ----


// ---- MP3 shield ----
// These are the pins used for the music maker shield

#define SHIELD_RESET  43      // VS1053 reset pin (unused!)
#define SHIELD_CS     53     // VS1053 chip select pin (output)
#define SHIELD_DCS    40      // VS1053 Data/command select pin (output)

// These are common pins between breakout and shield
#define CARDCS 49     // Card chip select pin

// DREQ should be an Int pin, see http://arduino.cc/en/Reference/attachInterrupt
#define DREQ 20       // VS1053 Data request, ideally an Interrupt pin

// ---- MP3 shield End ----

void mp3Ini();
void playSound(char* path);

