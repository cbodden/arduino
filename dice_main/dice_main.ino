const int latchPin = 5;  // Pin 5 of 74HC595 (Latch)
const int dataPin  = 6;  // Pin 6 of 74HC595 (Data)
const int clockPin = 7;  // Pin 7 of 74HC595 (Clock)
const int d100Pin = 2;   // push button pin
const int d20Pin = 9;
//int d100State = 0;     // set inital buttonState to 0
//int d20State = 0;
int randNumber;

//    LED Segment:  A B C D E F G DP
//         On/Off:  0 1 1 0 0 1 1 0
int numbers[16] = { 
  3,159,37,13,153,73,65,27,1,9,17,193,99,133,97,113 }; // 0 - F int

void setup()
{
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(d100Pin, INPUT);
  pinMode(d20Pin, INPUT);
  randomSeed(analogRead(0));
}

void loop()
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, 255); // clear left
  shiftOut(dataPin, clockPin, LSBFIRST, 255); // clear right
  digitalWrite(latchPin, HIGH);

  //int d100State = digitalRead(d100Pin);
  //int d20State = digitalRead(d20Pin);

  //if (d20State == HIGH) {
  if (digitalRead(d20Pin) == HIGH) {
    randNumber = random(1, 20);
    Serial.print ("Pressed d20 -- ");
    Serial.println(randNumber);
    spin(randNumber);
  }

  //if (d100State == HIGH) {
  if (digitalRead(d100Pin) == HIGH) {
    randNumber = random(0, 99);
    Serial.print ("Pressed d100 -- ");
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
