/*
   Fading Light
   This example shows how to fade an LED on pin 10 using the analogWrite() function.
*/
int ledPin = 10;       // the pin that the LED is attached to

void setup() {
      // declare pin 9 to be an output:
      pinMode(ledPin,OUTPUT);
      // initialize serial communication at 9600 bits per second:
      Serial.begin(9600);
}

void loop(){
      fadeOn(1000,5);
      fadeOff(1000,5);
}

void fadeOn(unsigned int time,int increament){
       //change the brightness by FOR statement
	for (byte value = 0 ; value < 255; value+=increament){ 
                // print out the value:
	        Serial.println(value);
                // set the brightness of pin 10:
		analogWrite(ledPin, value);
		delay(time/(255/5));
        } 
}

void fadeOff(unsigned int time,int decreament){
       //change the brightness by FOR statement
	for (byte value = 255; value >0; value-=decreament){ 
	        Serial.println(value);
		analogWrite(ledPin, value); 
		delay(time/(255/5)); 
	}
}
