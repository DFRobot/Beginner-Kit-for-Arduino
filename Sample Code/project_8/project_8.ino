/*
  Detecting vibration
*/

int SensorLED = 13;       //LED PIN
int SensorINPUT = 3;      //Connect the sensor to digital Pin 3 which is Interrupts 1
unsigned char state = 0;

void setup() { 
  pinMode(SensorLED, OUTPUT);        
  pinMode(SensorINPUT, INPUT);     

  // Trigger the blink function when the falling edge is detected
  attachInterrupt(1, blink, RISING);   
 }

void loop(){
      if(state!=0){              
        state = 0;              
        digitalWrite(SensorLED,HIGH);   
        delay(500);        
      }  
      else 
        digitalWrite(SensorLED,LOW);     
} 

void blink(){               //Interrupts function
    state++;            
}

