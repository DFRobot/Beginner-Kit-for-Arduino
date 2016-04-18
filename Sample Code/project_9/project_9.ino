/*
  Ambient Light controlled LED 
*/
int LED = 13;                     //Led pin
int val = 0;                      

void setup(){
     pinMode(LED,OUTPUT);         
     Serial.begin(9600);        
}

void loop(){
     val = analogRead(0);         // read voltage value 
     Serial.println(val);        
     if(val<1000){                // if the value is less than 1000，LED turns off
          digitalWrite(LED,LOW);
     }else{                        // if the value is more than 1000，LED turns on
          digitalWrite(LED,HIGH);
     }
     delay(10);                   
}

