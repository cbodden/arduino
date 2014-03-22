const int latchPin = 2;  // Pin 5 of 74HC595 (Latch)
const int dataPin  = 3;  // Pin 6 of 74HC595 (Data)
const int clockPin = 4;  // Pin 7 of 74HC595 (Clock)
const int d100Pin = 6;   // d100 button pin
const int d20Pin = 7;    // d20 button pin
const int d12Pin = 8;    // d12 button pin
const int d10Pin = 9;    // d10 button pin
const int d8Pin = 10;    // d8 button pin
const int d6Pin = 11;    // d6 button pin
const int d4Pin = 12;    // d4 button pin

//int d100State = 0;     // set inital buttonState to 0
//int d20State = 0;
int randNumber;

// LED Segment:  A B C D E F G DP
//      On/Off:  0 1 1 0 0 1 1 0
// 0 - F int
int numbers[16] = { 
  3,159,37,13,153,73,65,27,1,9,17,193,99,133,97,113 };

void setup()
{
  // initializing serial @ 9600
  Serial.begin(9600);
  // initializing output pins
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  // initializing input pins
  pinMode(d100Pin, INPUT);
  pinMode(d20Pin, INPUT);
  pinMode(d12Pin, INPUT);
  pinMode(d10Pin, INPUT);
  pinMode(d8Pin, INPUT);
  pinMode(d6Pin, INPUT);
  pinMode(d4Pin, INPUT);
  // initializing the pseudo-random number generator
  // on unconnected analog pin 0
  randomSeed(analogRead(0));
}

void loop()
{
  // clearing displays before and after pin press
  // 255 powers down
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, 255); // left
  shiftOut(dataPin, clockPin, LSBFIRST, 255); // right
  digitalWrite(latchPin, HIGH);

  //int d100State = digitalRead(d100Pin);
  //int d20State = digitalRead(d20Pin);
  //if (d100State == HIGH) {

  // on specific pin press, generate specified random value  
  if (digitalRead(d100Pin) == HIGH) {
    randNumber = random(0, 99);
    Serial.print ("Pressed d100 -- ");
    Serial.println(randNumber);
    // calculation and print to displays function
    spin(randNumber);
  }

  if (digitalRead(d20Pin) == HIGH) {
    randNumber = random(1, 20);
    Serial.print ("Pressed d20 -- ");
    Serial.println(randNumber);
    spin(randNumber);
  }

  if (digitalRead(d12Pin) == HIGH) {
    randNumber = random(1, 12);
    Serial.print ("Pressed d12 -- ");
    Serial.println(randNumber);
    spin(randNumber);
  }

  if (digitalRead(d10Pin) == HIGH) {
    randNumber = random(1, 10);
    Serial.print ("Pressed d10 -- ");
    Serial.println(randNumber);
    spin(randNumber);
  }

  if (digitalRead(d8Pin) == HIGH) {
    randNumber = random(1, 8);
    Serial.print ("Pressed d8 -- ");
    Serial.println(randNumber);
    spin(randNumber);
  }

  if (digitalRead(d6Pin) == HIGH) {
    randNumber = random(1, 6);
    Serial.print ("Pressed d6 -- ");
    Serial.println(randNumber);
    spin(randNumber);
  }

  if (digitalRead(d4Pin) == HIGH) {
    randNumber = random(1, 4);
    Serial.print ("Pressed d4 -- ");
    Serial.println(randNumber);
    spin(randNumber);
  }
}

void spin(byte randNumber)
{
  if (randNumber >= 0)
  {
    float d = randNumber % 10;
    int c = int(d);
    float b = randNumber / 10;
    int e = int(b);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, numbers[c]); 
    shiftOut(dataPin, clockPin, LSBFIRST, numbers[e]); 
    digitalWrite(latchPin, HIGH);
    delay(500);
  }
}
