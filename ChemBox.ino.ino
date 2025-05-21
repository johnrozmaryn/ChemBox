
#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment controller object

int SW1 = A4;  
int btnReset = A1;

int stateSW1 = LOW;

long n = 0; //n represents value displayed on the LED display. When n=0,0000 is displayed

void setup() {
  byte numDigits = 4;
  byte digitPins[] = {13, 10, 9, 7};
  byte segmentPins[] = {12, 8, 5, 3, 2, 11, 6, 4};
  bool resistorsOnSegments = true; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_CATHODE; // See README.md for options
  bool updateWithDelays = false; // Default 'false' is Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = true; // Use 'true' if your decimal point doesn't exist or isn't connected
  
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
  updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(10);
  sevseg.setNumber(n,0);

  pinMode(SW1, INPUT_PULLUP);
 
  pinMode(btnReset, INPUT_PULLUP);

  stateSW1 = digitalRead(SW1);
  Serial.begin(9600);
}

void loop() {
  if (stateSW1 != digitalRead(SW1)) add1();
  if (digitalRead(btnReset) == LOW) reset();  
 

  sevseg.refreshDisplay(); // Must run repeatedly
}

void add1()
{
  n += 1;
  if (n > 9999) n = 0;
  stateSW1 = digitalRead(SW1);
  sevseg.setNumber(n,0);
  Serial.print(n);
}


void reset()
{
 n = 0; 
 sevseg.setNumber(n,0);
 Serial.print(n);
}

