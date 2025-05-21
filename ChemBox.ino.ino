/*
  Showing number 0-9 on a Common Anode 7-segment LED display (plus the eigth decimal poit)
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---        X Decimal
    D
 */

int pinA = 12;
int pinB = 8;
int pinC = 5;
int pinD = 3;
int pinE = 2;
int pinF = 11;
int pinG = 6;
//int pinDP = 4; I don't think I'm going to use the decimal points
int D1 = 13;
int D2 = 10;
int D3 = 9;
int D4 = 7;

int SW1 = A4;  
int btnReset = A1;

int stateSW1 = LOW;


long n = 0; //n represents value displayed on the LED display. When n=0,0000 is displayed
int x = 100; //not sure what this is yet?
int del = 2; //used for fine tuning the display code

int count = 0; //This goes up by 1 every 0.1 second? Not sure if that's pertinent here yet

void setup() {
  // set all the pins to output
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
// pinMode(pinDP, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);

  // these are my cool buttons
  pinMode(SW1, INPUT_PULLUP);
 
  pinMode(btnReset, INPUT_PULLUP);
 

  stateSW1 = digitalRead(SW1);

 // Serial.begin(9600);
 
}

void loop() {
  // put your main code here, to run repeatedly:
 // Serial.write("alive");
  clearLEDs();//clear the 7-segment display screen
  pickDigit(0);//Light up 7-segment display d1
  pickNumber((n/1000));// get the value of thousand
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(1);//Light up 7-segment display d2
  pickNumber((n%1000)/100);// get the value of hundred
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(2);//Light up 7-segment display d3
  pickNumber(n%100/10);//get the value of ten
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(3);//Light up 7-segment display d4
  pickNumber(n%10);//Get the value of single digit
  delay(del);//delay 5ms
  
  if (stateSW1 != digitalRead(SW1)) add1();
 
  if (digitalRead(btnReset) == LOW) reset();  
}


void pickDigit(int x) //
{
  //first, turn them all on high. Then we'll push the one we want low (if I have a common anode this will need to be backwards?

  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);

  switch(x)
  {
    case 0:
    digitalWrite(D1, LOW);
    break;
    case 1:
    digitalWrite(D2, LOW);
    break;
    case 2:
    digitalWrite(D3, LOW);
    break;
    case 3:
    digitalWrite(D4, LOW);
    break;
  }
}

void pickNumber(int x)   //10 for blank
{
  switch(x)
  {
    default: 
    zero(); 
    break;
    case 1: 
    one(); 
    break;
    case 2: 
    two(); 
    break;
    case 3: 
    three(); 
    break;
    case 4: 
    four(); 
    break;
    case 5: 
    five(); 
    break;
    case 6: 
    six(); 
    break;
    case 7: 
    seven(); 
    break;
    case 8: 
    eight(); 
    break;
    case 9: 
    nine(); 
    case 10:
    blank();
    break;
  }
}

void clearLEDs() //clear the 7-segment display screen
{
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
//  digitalWrite(pinDP, LOW);
}

void zero() //the 7-segment led display 0
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
//  digitalWrite(pinDP, LOW);
}

void one() //the 7-segment led display 1
{
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
 // digitalWrite(pinDP, LOW);
}

void two() //the 7-segment led display 2
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
// digitalWrite(pinDP, LOW);
}
void three() //the 7-segment led display 3
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
//  digitalWrite(pinDP, LOW);
}

void four() //the 7-segment led display 4
{
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
//  digitalWrite(pinDP, LOW);
}

void five() //the 7-segment led display 5
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
//  digitalWrite(pinDP, LOW);
}

void six() //the 7-segment led display 6
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
 // digitalWrite(pinDP, LOW);
}

void seven() //the 7-segment led display 7
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
//  digitalWrite(pinDP, LOW);
}

void eight() //the 7-segment led display 8
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
//  digitalWrite(pinDP, LOW);
}

void nine() //the 7-segment led display 9
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
//  digitalWrite(pinDP, LOW);
}

void blank() //not used yet, but here in case we don't want leading zeroes
{
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
//  digitalWrite(pinDP, LOW);
}

void add1()
{
  n += 1;
  if (n > 9999) n = 0;
  stateSW1 = digitalRead(SW1);
}


void reset()
{
 n = 0; 
}
