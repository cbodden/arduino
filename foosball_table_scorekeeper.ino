// begin input mapping 
const int switchPin = 13;
int val = 0;
int counter = 0;
int currentState = 0;
int previousState = 0;
// end input mapping 

void setup() {
  pinMode(1, OUTPUT); pinMode(2, OUTPUT); pinMode(3, OUTPUT); pinMode(4, OUTPUT); pinMode(5, OUTPUT); pinMode(6, OUTPUT); pinMode(7, OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop() {
 val = digitalRead(switchPin);
 if (val == HIGH) {
   currentState = currentState + 1;
   // previousState = currentState;
   // Serial.printin(counter);
 //}
 if(currentState != previousState){
   if(currentState == 1){
     digitalWrite(2, LOW); digitalWrite(3, LOW);
     delay(500);
     digitalWrite(2, HIGH); digitalWrite(3, HIGH);
     delay(250);
   }
   if(currentState == 2){
     digitalWrite(1, LOW); digitalWrite(2, LOW); digitalWrite(4, LOW); digitalWrite(5, LOW); digitalWrite(7, LOW);
     delay(500);
     digitalWrite(1, HIGH); digitalWrite(2, HIGH); digitalWrite(4, HIGH); digitalWrite(5, HIGH); digitalWrite(7, HIGH);
     delay(250);
   }
   if(currentState == 3){
     digitalWrite(1, LOW); digitalWrite(2, LOW); digitalWrite(3, LOW); digitalWrite(4, LOW); digitalWrite(7, LOW);
     delay(500);
     digitalWrite(1, HIGH); digitalWrite(2, HIGH); digitalWrite(3, HIGH); digitalWrite(4, HIGH); digitalWrite(7, HIGH);
     delay(250);
   }
   if(currentState == 4){
     digitalWrite(2, LOW); digitalWrite(3, LOW); digitalWrite(6, LOW); digitalWrite(7, LOW);
     delay(500);
     digitalWrite(2, HIGH); digitalWrite(3, HIGH); digitalWrite(6, HIGH); digitalWrite(7, HIGH);
     delay(250);
   }
   if(currentState == 5){
     digitalWrite(1, LOW); digitalWrite(3, LOW); digitalWrite(4, LOW); digitalWrite(6, LOW); digitalWrite(7, LOW);
     delay(500);
     digitalWrite(1, HIGH); digitalWrite(3, HIGH); digitalWrite(4, HIGH); digitalWrite(6, HIGH); digitalWrite(7, HIGH);
     delay(250);
   }
   if(currentState == 6){
     digitalWrite(1, LOW); digitalWrite(2, LOW); digitalWrite(3, LOW); digitalWrite(4, LOW); digitalWrite(5, LOW); digitalWrite(6, LOW); digitalWrite(7, LOW);
     delay(100);
     digitalWrite(1, HIGH); digitalWrite(2, HIGH); digitalWrite(3, HIGH); digitalWrite(4, HIGH); digitalWrite(5, HIGH); digitalWrite(6, HIGH); digitalWrite(7, HIGH);
     delay(100);
     }
   else {
     digitalWrite(1, LOW); digitalWrite(2, LOW); digitalWrite(3, LOW); digitalWrite(4, LOW); digitalWrite(5, LOW); digitalWrite(6, LOW);
     delay(500);
     digitalWrite(1, HIGH); digitalWrite(2, HIGH); digitalWrite(3, HIGH); digitalWrite(4, HIGH); digitalWrite(5, HIGH); digitalWrite(6, HIGH); digitalWrite(7, HIGH);
     delay(250);
   }
  }
}
}
