
const int ledPin = 25;
 
void setup() {
  Serial.begin(9600); 
  pinMode(ledPin,OUTPUT);
}

  unsigned long DelayTime = 10000;
  unsigned long previosTime = 0;
  char character;
  bool simpleOff;
  
void loop() {
  
  
  
  Num = Serial.read();
  if(Num == 'e')
  {
    simpleOff = false;
    digitalWrite(ledPin,HIGH);
    delay(1);
    unsigned long currentTime = millis();
    if(((currentTime - previosTime)> DelayTime)&&(simpleOff == false))
    {
      digitalWrite(ledPin,LOW);
      delay(1);
      previosTime = currentTime;
    }
    else
    {
      character = Serial.read();
    }
  }
  else if(character == 'r')
  {
    simpleOff = true;
    digitalWrite(ledPin,LOW);
    delay(1);
  }
  
}
