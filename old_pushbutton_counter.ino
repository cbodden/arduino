const int switchPin = 13;
int val = 0;
int counter = 0;
int currentState = 0;
int previousState = 0;

void setup(){
  //switched pinMode1 to pinMode11 due to TX/RX 
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

void updateDisplay(int currentState){
  if(currentState == 15){
    digitalWrite(11, HIGH); 
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH); 
    digitalWrite(4, HIGH); 
    digitalWrite(5, HIGH); 
    digitalWrite(6, HIGH); 
    digitalWrite(7, HIGH);
    digitalWrite(11, LOW); 
    digitalWrite(5, LOW); 
    digitalWrite(6, LOW); 
    digitalWrite(7, LOW);
  }
  else if(currentState == 14){
    digitalWrite(11, HIGH); 
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH); 
    digitalWrite(4, HIGH); 
    digitalWrite(5, HIGH); 
    digitalWrite(6, HIGH); 
    digitalWrite(7, HIGH);
    digitalWrite(11, LOW); 
    digitalWrite(4, LOW); 
    digitalWrite(5, LOW); 
    digitalWrite(6, LOW); 
    digitalWrite(7, LOW);
  }
  else if(currentState == 13){
    digitalWrite(11, HIGH); 
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH); 
    digitalWrite(4, HIGH); 
    digitalWrite(5, HIGH); 
    digitalWrite(6, HIGH); 
    digitalWrite(7, HIGH);
    digitalWrite(2, LOW); 
    digitalWrite(3, LOW); 
    digitalWrite(4, LOW); 
    digitalWrite(5, LOW); 
    digitalWrite(7, LOW);
  }
  else if(currentState == 12){
    digitalWrite(11, HIGH); 
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH); 
    digitalWrite(4, HIGH); 
    digitalWrite(5, HIGH); 
    digitalWrite(6, HIGH); 
    digitalWrite(7, HIGH);
    digitalWrite(11, LOW); 
    digitalWrite(4, LOW); 
    digitalWrite(5, LOW); 
    digitalWrite(6, LOW);
  }
  else if(currentState == 11){
    digitalWrite(11, HIGH); 
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH); 
    digitalWrite(4, HIGH); 
    digitalWrite(5, HIGH); 
    digitalWrite(6, HIGH); 
    digitalWrite(7, HIGH);
    digitalWrite(3, LOW); 
    digitalWrite(4, LOW); 
    digitalWrite(5, LOW); 
    digitalWrite(6, LOW); 
    digitalWrite(7, LOW);
  }
  else if(currentState == 10){
    digitalWrite(11, HIGH); 
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH); 
    digitalWrite(4, HIGH); 
    digitalWrite(5, HIGH); 
    digitalWrite(6, HIGH); 
    digitalWrite(7, HIGH);
    digitalWrite(11, LOW); 
    digitalWrite(2, LOW); 
    digitalWrite(3, LOW); 
    digitalWrite(5, LOW); 
    digitalWrite(6, LOW); 
    digitalWrite(7, LOW);
  }
  else if(currentState == 9){
    digitalWrite(11, HIGH); 
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH); 
    digitalWrite(4, HIGH); 
    digitalWrite(5, HIGH); 
    digitalWrite(6, HIGH); 
    digitalWrite(7, HIGH);
    digitalWrite(11, LOW); 
    digitalWrite(2, LOW); 
    digitalWrite(3, LOW); 
    digitalWrite(6, LOW); 
    digitalWrite(7, LOW);
  }
  else if(currentState == 8){
    digitalWrite(11, HIGH); 
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH); 
    digitalWrite(4, HIGH); 
    digitalWrite(5, HIGH); 
    digitalWrite(6, HIGH); 
    digitalWrite(7, HIGH);
    digitalWrite(11, LOW); 
    digitalWrite(2, LOW); 
    digitalWrite(3, LOW); 
    digitalWrite(4, LOW); 
    digitalWrite(5, LOW); 
    digitalWrite(6, LOW); 
    digitalWrite(7, LOW);
  }
  else if(currentState == 7){
    digitalWrite(11, HIGH); 
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH); 
    digitalWrite(4, HIGH); 
    digitalWrite(5, HIGH); 
    digitalWrite(6, HIGH); 
    digitalWrite(7, HIGH);
    digitalWrite(11, LOW); 
    digitalWrite(2, LOW); 
    digitalWrite(3, LOW);
  }
  else if(currentState == 6){
    digitalWrite(11, HIGH); 
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH); 
    digitalWrite(4, HIGH); 
    digitalWrite(5, HIGH); 
    digitalWrite(6, HIGH); 
    digitalWrite(7, HIGH);
    digitalWrite(11, LOW); 
    digitalWrite(3, LOW); 
    digitalWrite(4, LOW); 
    digitalWrite(5, LOW); 
    digitalWrite(6, LOW); 
    digitalWrite(7, LOW);
  }
  else if(currentState == 5){
    digitalWrite(11, HIGH); 
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH); 
    digitalWrite(4, HIGH); 
    digitalWrite(5, HIGH); 
    digitalWrite(6, HIGH); 
    digitalWrite(7, HIGH);
    digitalWrite(11, LOW); 
    digitalWrite(3, LOW); 
    digitalWrite(4, LOW); 
    digitalWrite(6, LOW); 
    digitalWrite(7, LOW);
  }
  else if(currentState == 4){
    digitalWrite(11, HIGH); 
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH); 
    digitalWrite(4, HIGH); 
    digitalWrite(5, HIGH); 
    digitalWrite(6, HIGH); 
    digitalWrite(7, HIGH);
    digitalWrite(2, LOW); 
    digitalWrite(3, LOW); 
    digitalWrite(6, LOW); 
    digitalWrite(7, LOW);
  }
  else if(currentState == 3){
    digitalWrite(11, HIGH); 
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH); 
    digitalWrite(4, HIGH); 
    digitalWrite(5, HIGH); 
    digitalWrite(6, HIGH); 
    digitalWrite(7, HIGH);
    digitalWrite(11, LOW); 
    digitalWrite(2, LOW); 
    digitalWrite(3, LOW); 
    digitalWrite(4, LOW); 
    digitalWrite(7, LOW);
  }
  else if(currentState == 2){
    digitalWrite(11, HIGH); 
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH); 
    digitalWrite(4, HIGH); 
    digitalWrite(5, HIGH); 
    digitalWrite(6, HIGH); 
    digitalWrite(7, HIGH);
    digitalWrite(11, LOW); 
    digitalWrite(2, LOW); 
    digitalWrite(4, LOW); 
    digitalWrite(5, LOW); 
    digitalWrite(7, LOW);
  }
  else if(currentState == 1){
    digitalWrite(11, HIGH); 
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH); 
    digitalWrite(4, HIGH); 
    digitalWrite(5, HIGH); 
    digitalWrite(6, HIGH); 
    digitalWrite(7, HIGH);
    digitalWrite(2, LOW); 
    digitalWrite(3, LOW);
  }
  else if(currentState == 0){
    digitalWrite(11, HIGH); 
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH); 
    digitalWrite(4, HIGH); 
    digitalWrite(5, HIGH); 
    digitalWrite(6, HIGH); 
    digitalWrite(7, HIGH);
    digitalWrite(11, LOW); 
    digitalWrite(2, LOW); 
    digitalWrite(3, LOW); 
    digitalWrite(4, LOW); 
    digitalWrite(5, LOW); 
    digitalWrite(6, LOW);
  }
}

