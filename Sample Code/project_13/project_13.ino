/*
   Motor Fan
*/

int buttonPin = 2;                          // button pin -- Digital 2
int relayPin = 3;                           // relay pin -- Digital 3
int relayState = HIGH;                      
int buttonState;                            
int lastButtonState = LOW;                 
long lastDebounceTime = 0;                  
long debounceDelay = 50;                    

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(relayPin, OUTPUT);

  digitalWrite(relayPin, relayState);       
}
void loop() {
   // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);  
  
  // check to see if you just pressed the button 
  // (i.e. the input went from LOW to HIGH),  and you've waited 
  // long enough since the last press to ignore any noise:  

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {   
    lastDebounceTime = millis();
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;
      
      // only toggle the Relay if the new button state is HIGH
      if (buttonState == HIGH) {
        relayState = !relayState;
      }
    }
  }
 
   // set the relay: 
  digitalWrite(relayPin, relayState);

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;
}

