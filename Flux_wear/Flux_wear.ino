#include <Bounce2.h>



const int buttonPin = 5;    
const int ledPin = 2;      
const int buttonPin2 = 6;    
const int ledPin2 = 3;      


const int tempo_on = 10000;

int ledState = HIGH; 
int ledState2 = HIGH;        
       
int buttonState;             
int lastButtonState = LOW;   

int buttonState2;             
int lastButtonState2 = LOW;   


unsigned long lastDebounceTime = 0;  
unsigned long debounceDelay = 50;    

unsigned long lastDebounceTime2 = 0;  
unsigned long debounceDelay2 = 50;    

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  pinMode(buttonPin2, INPUT);
  pinMode(ledPin2, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, ledState);
    digitalWrite(ledPin2, ledState2);

}

void loop() {
  
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
   
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }

  if ((millis() - lastDebounceTime) > tempo_on) {
        ledState = LOW;  
  }

  digitalWrite(ledPin, ledState);

  
  lastButtonState = reading;


   int reading2 = digitalRead(buttonPin2);
  if (reading2 != lastButtonState2) {
   
    lastDebounceTime2 = millis();
  }

  if ((millis() - lastDebounceTime2) > debounceDelay2) {
    
    if (reading2 != buttonState2) {
      buttonState2 = reading2;

      if (buttonState2 == HIGH) {
        ledState2 = !ledState2;
      }
    }
  }

  if ((millis() - lastDebounceTime2) > tempo_on) {
        ledState2 = LOW;  
  }

  digitalWrite(ledPin2, ledState2);

  
  lastButtonState2 = reading2;
}
