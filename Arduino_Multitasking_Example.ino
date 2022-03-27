const int toggleLEDPin = 10;
const int buttonPin = 2;

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

int buttonDebounce = 20;
int ledToggle = LOW;
volatile int buttonFlag=0;
int previousState = HIGH;
unsigned int previousPress;

void setup() 
{
  pinMode(blinkLEDPin1, OUTPUT);      
  pinMode(blinkLEDPin2, OUTPUT);
  pinMode(toggleLEDPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); 
  attachInterrupt(digitalPinToInterrupt(buttonPin), button_ISR, CHANGE);     
}
void button_ISR()
{
  buttonFlag = 1;
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
  
  if(buttonFlag==1)
  {
    if((millis() - previousPress) > buttonDebounce && buttonFlag)
    {
      previousPress = millis();
      if(digitalRead(buttonPin) == LOW && previousState == HIGH)
      {
        ledToggle =! ledToggle;
        digitalWrite(toggleLEDPin, ledToggle);
        previousState = LOW;
      }
      else if(digitalRead(buttonPin) == HIGH && previousState == LOW)
      {
        previousState = HIGH;
      }
      buttonFlag = 0;
    }
  }
}