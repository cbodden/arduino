  /* this is a counter in which the score does not to go higher than 9 (numeric) or f (hex)
  7 segment display used is 276-075 from radio shack, pinout : http://www.escol.com.my/Datasheets_specs/pinout-1.jpg
  cesar@pissedoffadmins.com */

const int switchPin = 13;
int val = 0;
int counter = 0;
int currentState = 0;
int previousState = 0;

void setup(){
  pinMode(2, OUTPUT);   // a
  pinMode(3, OUTPUT);   // b
  pinMode(4, OUTPUT);   // c
  pinMode(5, OUTPUT);   // d
  pinMode(6, OUTPUT);   // e
  pinMode(7, OUTPUT);   // f
  pinMode(8, OUTPUT);   // g
  pinMode(9, OUTPUT);   // left decimal
  pinMode(10, OUTPUT);  // right decimal
  pinMode(switchPin, INPUT);
  //Serial.begin(9600);
  segment_digits_write(currentState);
}

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

void segment_digits_write(byte digit){
  byte pin = 2;
  for (byte segCount = 0; segCount < 9; ++segCount){
    digitalWrite(pin, segment_digits_map[digit][segCount]);
    ++pin;
  }
}

void loop(){
  val = digitalRead(switchPin);
  segment_digits_write(currentState);
  if(val == HIGH){
    delay(500);
    currentState++;
    //Serial.print("Displaying: ");
    //Serial.println(currentState);
    if(currentState != previousState){
      segment_digits_write(currentState);
      if(currentState == 16){
        currentState = 0;
      }
    }
  }
}
