/*
   SOS Beacon   
*/
int ledPin = 10;
void setup() {
        pinMode(ledPin, OUTPUT);
}
void loop() {
       // S (...) three dot represents "S".
       for(int x=0;x<3;x++){
        digitalWrite(ledPin,HIGH);            // turn the LED on (HIGH is the voltage level)
        delay(150);                           // wait for 150ms
        digitalWrite(ledPin,LOW);             // turn the LED off by making the voltage LOW
        delay(100);                           // wait for 100ms
        }
       
        // wait for 100ms
        delay(100);

        //O(---) three dash represents "O".
       for(int x=0;x<3;x++){
        digitalWrite(ledPin,HIGH);            // turn the LED on (HIGH is the voltage level)
        delay(400);                           // wait for 400ms
        digitalWrite(ledPin,LOW);             // turn the LED off by making the voltage LOW
        delay(100);                           // wait for 100ms
        }

        // wait for 100ms
        delay(100);

       // S (...) three dot represents "S".
       for(int x=0;x<3;x++){
        digitalWrite(ledPin,HIGH);            // turn the LED on (HIGH is the voltage level)
        delay(150);                           // wait for 150ms
        digitalWrite(ledPin,LOW);             // turn the LED off by making the voltage LOW
        delay(100);                           // wait for 100ms
        }

        // wait for 5s
        delay(5000);
}

