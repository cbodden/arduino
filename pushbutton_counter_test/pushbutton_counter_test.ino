// counter to drive a common-anode 7 segment display (from radio shack)

const int switchPin = 13;
int val = 0;
int counter = 0;
int currentState = 0;
int previousState = 0;

void setup(){
  //switched pinMode1 to pinMode11 due to TX/RX
  pinMode(switchPin, INPUT);
  //Serial.begin(9600);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
}


///////////////////////////////////////////////////////////////
for(i=0;i<whatever;i++)
if(urarray[i]==1) dosomething("high");
else dosomething("low");
///////////////////////////////////////////////////////////////
testing array for 7 seg
change pins on seg from 1-9 to 2-10 for consistency

// pins 2,3,4,5,6,7,8,9,10,11

byte segment_digits_map[16][9] = {
        { 0,0,0,0,0,0,1,1,1 },  // 0
        { 1,0,0,1,1,1,1,1,1 },  // 1
        { 0,0,1,0,0,1,0,1,1 },  // 2
        { 0,0,0,0,1,1,0,1,1 },  // 3
        { 1,0,0,1,1,0,0,1,1 },  // 4
        { 0,1,0,0,1,0,0,1,1 },  // 5
        { 0,1,0,0,0,0,0,1,1 },  // 6
        { 0,0,0,1,1,1,1,1,1 },  // 7
        { 0,0,0,0,0,0,0,1,1 },  // 8
        { 0,0,0,1,1,0,0,1,1 },  // 9
        { 0,0,0,1,0,0,0,1,1 },  // 10 - A
        { 1,1,0,0,0,0,0,1,1 },  // 11 - b
        { 0,1,1,0,0,0,1,1,1 },  // 12 - C
        { 1,0,0,0,0,1,0,1,1 },  // 13 - d
        { 0,1,1,0,0,0,0,1,1 },  // 14 - E
        { 0,1,1,1,0,0,0,1,1 }   // 15 - F
        };


void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(switchPin, INPUT);
  blankDisplay();
  }

// blankDisplay is to set all pins to high on display to save lines
void blankDisplay(){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
  }

void segment_digits_write(byte digit){
  byte pin = 2;
  for (byte segCount = 0; segCount < 9; ++segCount) {
    digitalWrite(pin, segment_digits_map[digit][segCount]);
    ++pin;
  }
}

void loop(){
  val = digitalRead(switchPin);
  //updateDisplay(currentState);
  if (val == HIGH){
    delay(500);
    currentState++;
    //Serial.print("Displaying: ");
    //Serial.println(currentState);
    //Serial.print("Read switch input: ");
    //Serial.println(digitalRead(switchPin));
    if(currentState != previousState){
      //updateDisplay(currentState);
      if(currentState == 16){
        currentState = 0;
      }
    }
  }
}


/*
///////////////////////////////////////////////////////////////
http://www.borderlinegeek.com/arduino-7-seg.htm
///////////////////////////////////////////////////////////////

// displays digits from 9 to 0
void loop() {
  for (byte count = 10; count > 0; --count) {
   delay(1000);
   sevenSegWrite(count - 1);
  }
  delay(4000);
}
///////////////////////////////////////////////////////////////
*/


void loop(){
  val = digitalRead(switchPin);
  updateDisplay(currentState);
  if (val == HIGH){
    delay(500);
    currentState++;
    //Serial.print("Displaying: ");
    //Serial.println(currentState);
    //Serial.print("Read switch input: ");
    //Serial.println(digitalRead(switchPin));
    if(currentState != previousState){
      updateDisplay(currentState);
      if(currentState == 16){
        currentState = 0;
      }
    }
  }
}

// blankDisplay is to set all pins to high on display to save lines
void blankDisplay(){
    digitalWrite(11, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
  }

void updateDisplay(int currentState){
  if(currentState == 15){
    blankDisplay();
    digitalWrite(11, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
  else if(currentState == 14){
    blankDisplay();
    digitalWrite(11, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
  else if(currentState == 13){
    blankDisplay();
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
  }
  else if(currentState == 12){
    blankDisplay();
    digitalWrite(11, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  }
  else if(currentState == 11){
    blankDisplay();
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
  else if(currentState == 10){
    blankDisplay();
    digitalWrite(11, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
  else if(currentState == 9){
    blankDisplay();
    digitalWrite(11, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
  else if(currentState == 8){
    blankDisplay();
    digitalWrite(11, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
  else if(currentState == 7){
    blankDisplay();
    digitalWrite(11, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  }
  else if(currentState == 6){
    blankDisplay();
    digitalWrite(11, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
  else if(currentState == 5){
    blankDisplay();
    digitalWrite(11, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
  else if(currentState == 4){
    blankDisplay();
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
  else if(currentState == 3){
    blankDisplay();
    digitalWrite(11, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(7, LOW);
  }
  else if(currentState == 2){
    blankDisplay();
    digitalWrite(11, LOW);
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
  }
  else if(currentState == 1){
    blankDisplay();
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  }
  else if(currentState == 0){
    blankDisplay();
    digitalWrite(11, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  }
}
