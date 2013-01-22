const int latchPin = 5;  // Pin connected to Pin 12 of 74HC595 (Latch)
const int dataPin  = 6;  // Pin connected to Pin 14 of 74HC595 (Data)
const int clockPin = 7;  // Pin connected to Pin 11 of 74HC595 (Clock)
unsigned long t1;
unsigned long t2;
int i = 0;

const byte numbers[16] = {
                    0b11111100,
                    0b01100000,
                    0b11011010,
                    0b11110010,
                    0b01100110,
                    0b10110110,
                    0b10111110,
                    0b11100000,
                    0b11111110,
                    0b11100110,
                    0b11101110,
                    0b00111110,
                    0b10011100,
                    0b01111010,
                    0b10011110,
                    0b10001110
};

void setup()
{
  // initialisation time
  t1 = millis();
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop()
{
    // update digit every two seconds
    t2 = millis();
    if(t2 - t1 > 2000)
    {
      i++;
      t1 = t2;
      if(i > 15) { i = 0; }
    }
    // display the current digit
    show(numbers[i]);
    show(11111111);
}

void show( byte number)
{
  for(int j = 0; j <= 7; j++)
  {
    byte toWrite = number & (0b10000000 >> j); 
    // If all bits are 0 then no point writing it to the shift register, so break out and move on to next segment.
    if(!toWrite) { continue; }
    // Otherwise shift it into the register
    shiftIt(toWrite);
  }
}

void shiftIt (byte data)
{
    // Set latchPin LOW while clocking these 8 bits in to the register
    digitalWrite(latchPin, LOW);
    for (int k=0; k <= 7; k++)
    {
      // clockPin LOW prior to sending a bit
      digitalWrite(clockPin, LOW); 

      if ( data & (1 << k) )
      {
        digitalWrite(dataPin, LOW); // turn “On”
      }
      else
      {
        digitalWrite(dataPin, HIGH); // turn “Off”
      }

      // and clock the bit in
      digitalWrite(clockPin, HIGH);
    }
    //stop shifting out data
    digitalWrite(clockPin, LOW); 
    //set latchPin to high to lock and send data
    digitalWrite(latchPin, HIGH);
    // put delay here if you want to see the multiplexing in action!
    delay(100);
}
