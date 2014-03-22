/*
  d4 - d100 Dice roller using multiplexed 74HC595's to dual 7 segment LED's

  Connections:

    Vcc = 3.3v - 2 x AA 
    
    ATmega328:
    ATmega328 pin 1  (RST)     => Vcc
    ATmega328 pin 2  (D0 RX)   => Not Connected
    ATmega328 pin 3  (D1 TX)   => Not Connected
    ATmega328 pin 4  (D2)      => 74HC595 (Both) pin 12 (STCP) 
    ATmega328 pin 5  (D3 PWM)  => 74HC595 (Left) pin 14 (DS)
    ATmega328 pin 6  (D4)      => 74HC595 (Both) pin 11 (SHCP)
    ATmega328 pin 7  (VCC)     => Vcc
    ATmega328 pin 8  (GND)     => Ground
    ATmega328 pin 9  (XLAT1)   => Cap 1
    ATmega328 pin 10 (XLAT2)   => Cap 2
    ATmega328 pin 11 (D5 PWM)  => Not Connected
    ATmega328 pin 12 (D6 PWM)  => d100 Button
    ATmega328 pin 13 (D7)      => d20 Button
    ATmega328 pin 14 (D8)      => d12 Button
    ATmega328 pin 15 (D9 PWM)  => d10 Button
    ATmega328 pin 16 (D10 PWM) => d8 Button
    ATmega328 pin 17 (D11 PWM) => d6 Button
    ATmega328 pin 18 (D12)     => d4 Button
    ATmega328 pin 19 (D13)     => Power LED
    ATmega328 pin 20 (AVCC)    => Vcc
    ATmega328 pin 21 (AREF)    => Vcc
    ATmega328 pin 22 (GND)     => Ground
    ATmega328 pin 23 (A0)      => Not Connected
    ATmega328 pin 24 (A1)      => Not Connected
    ATmega328 pin 25 (A2)      => Not Connected
    ATmega328 pin 26 (A3)      => Not Connected
    ATmega328 pin 27 (A4)      => Not Connected
    ATmega328 pin 28 (A5)      => Not Connected
    
    Left Register (Registers the same except for pins 9 & 14):
    74HC595 pin 1  (Q1)        => LED Pin 6  (B)
    74HC595 pin 2  (Q2)        => LED Pin 4  (C)
    74HC595 pin 3  (Q3)        => LED Pin 2  (D)
    74HC595 pin 4  (Q4)        => LED Pin 1  (E)
    74HC595 pin 5  (Q5)        => LED Pin 9  (F)
    74HC595 pin 6  (Q6)        => LED Pin 10 (G)
    74HC595 pin 7  (Q7)        => LED Pin 5  (DP)
    74HC595 pin 8  (GND)       => Ground
    74HC595 pin 9  (Q7S)       => 74HC595 pin 14 (Right Register)
    74HC595 pin 10 (MR)        => Vcc (High)
    74HC595 pin 11 (SHCP)      => ATmega328 pin 6 (Both Registers)
    74HC595 pin 12 (STCP)      => ATmega328 pin 4 (Both Registers)
    74HC595 pin 13 (OE)        => Ground (Low)
    74HC595 pin 14 (DS)        => ATmega328 pin 14 (Left Register)
    74HC595 pin 15 (Q0)        => LED Pin 7  (A)
    74HC595 pin 16 (Vcc)       => Vcc

    LED pin 3 or 8 => 220 Ohm resistor => Vcc
    
    www.pissedoffadmins.com
 */

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
    // print a random number from 0 to 99
    randNumber = random(0, 100);
    Serial.print ("Pressed d100 -- ");
    Serial.println(randNumber);
    // calculation and print to displays function
    spin(randNumber);
  }

  if (digitalRead(d20Pin) == HIGH) {
    randNumber = random(1, 21);
    Serial.print ("Pressed d20 -- ");
    Serial.println(randNumber);
    spin(randNumber);
  }

  if (digitalRead(d12Pin) == HIGH) {
    randNumber = random(1, 13);
    Serial.print ("Pressed d12 -- ");
    Serial.println(randNumber);
    spin(randNumber);
  }

  if (digitalRead(d10Pin) == HIGH) {
    randNumber = random(1, 11);
    Serial.print ("Pressed d10 -- ");
    Serial.println(randNumber);
    spin(randNumber);
  }

  if (digitalRead(d8Pin) == HIGH) {
    randNumber = random(1, 9);
    Serial.print ("Pressed d8 -- ");
    Serial.println(randNumber);
    spin(randNumber);
  }

  if (digitalRead(d6Pin) == HIGH) {
    randNumber = random(1, 7);
    Serial.print ("Pressed d6 -- ");
    Serial.println(randNumber);
    spin(randNumber);
  }

  if (digitalRead(d4Pin) == HIGH) {
    randNumber = random(1, 5);
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
    delay(750);
  }
}
