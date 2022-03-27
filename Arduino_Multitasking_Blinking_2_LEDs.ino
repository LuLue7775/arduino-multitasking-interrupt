const int blinkLEDPin1 =  8;
const int blinkLEDPin2 =  9;

int blinkLEDState1 = LOW;
int blinkLEDState2 = LOW;

unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;

long OnTime1 = 400;
long OnTime2 = 750;

long OffTime1 = 400;
long OffTime2 = 750;

void setup() 
{
  pinMode(blinkLEDPin1, OUTPUT);      
  pinMode(blinkLEDPin2, OUTPUT);    
}

void loop()
{
  unsigned long currentMillis = millis();
 
  if((blinkLEDState1 == HIGH) && (currentMillis - previousMillis1 >= OnTime1))
  {
    blinkLEDState1 = LOW;
    previousMillis1 = currentMillis;
    digitalWrite(blinkLEDPin1, blinkLEDState1);
  }
  else if ((blinkLEDState1 == LOW) && (currentMillis - previousMillis1 >= OffTime1))
  {
    blinkLEDState1 = HIGH;
    previousMillis1 = currentMillis;
    digitalWrite(blinkLEDPin1, blinkLEDState1);
  }
  
  if((blinkLEDState2 == HIGH) && (currentMillis - previousMillis2 >= OnTime2))
  {
    blinkLEDState2 = LOW;
    previousMillis2 = currentMillis;
    digitalWrite(blinkLEDPin2, blinkLEDState2);
  }
  else if ((blinkLEDState2 == LOW) && (currentMillis - previousMillis2 >= OffTime2))
  {
    blinkLEDState2 = HIGH;
    previousMillis2 = currentMillis;
    digitalWrite(blinkLEDPin2, blinkLEDState2);
  }
}