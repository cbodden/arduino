const int latchPin = 5;
const int clockPin = 7;
const int dataPin = 6;
const int switchPin = 13;
int val = 0;
int counter = 0;
int currentState = 0;
int previousState = 0;

void setup(){
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
}

const byte numbers[16] = {
  0b11111100,
  0b01100000,
  0b11011010,
  11110010,
  01100110,
  10110110,
  10111110,
  11100000,
  11111110,
  11100110,
  11101110,
  00111110,
  10011100,
  01111010,
  10011110,
  10001110
};
/*
void loop(){
  val = digitalRead(switchPin);

  Serial.print("Displaying: ");
  Serial.println(currentState);
  Serial.println(numbers[currentState]);
  Serial.println(val);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, numbers[currentState]);
  digitalWrite(latchPin, HIGH);

  if(val == HIGH){
    delay(500);
    currentState++;

    Serial.print("Displaying: ");
    Serial.println(currentState);
    Serial.println(numbers[currentState]);

    if(currentState != previousState){
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, numbers[currentState]);
      digitalWrite(latchPin, HIGH);
      if(currentState == 16){
        currentState = 0;
      }
    }
  }
}*/

int seq[14] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void loop(){
    for (int n = 0; n < 10; n++){
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, MSBFIRST, seq[n]);
        digitalWrite(latchPin, HIGH);
        delay(1000);
    }
}
