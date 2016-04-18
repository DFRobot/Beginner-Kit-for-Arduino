/*
   Traffic Light
   This code copied from the book Beginning-Arduino.
*/
int carRed = 12; //assign the car lights
int carYellow = 11;
int carGreen = 10;
int button = 9; //button pin
int pedRed = 8; //assign the pedestrian lights
int pedGreen = 7;
int crossTime =5000; //time for pedestrian to cross
unsigned long changeTime;//time since button pressed

void setup() {
  	pinMode(carRed, OUTPUT);
  	pinMode(carYellow, OUTPUT);
  	pinMode(carGreen, OUTPUT);
  	pinMode(pedRed, OUTPUT);
        pinMode(pedGreen, OUTPUT);
        pinMode(button, INPUT); 
        digitalWrite(carGreen, HIGH); //turn on the green lights
	digitalWrite(pedRed, HIGH); 
}

void loop() {
	int state = digitalRead(button);
        //check if button is pressed and it is over 5 seconds since last button press
        if(state == HIGH && (millis() - changeTime)> 5000){
               //call the function to change the lights
               changeLights();
        }
}

void changeLights() {
	digitalWrite(carGreen, LOW); //green off
	digitalWrite(carYellow, HIGH); //yellow on
	delay(2000); //wait 2 seconds
		
	digitalWrite(carYellow, LOW); //yellow off
	digitalWrite(carRed, HIGH); //red on
        delay(1000); //wait 1 second till its safe
		
	digitalWrite(pedRed, LOW); //ped red off
	digitalWrite(pedGreen, HIGH); //ped green on

	delay(crossTime); //wait for preset time period
		
	//flash the ped green
        for (int x=0; x<10; x++) {
	        digitalWrite(pedGreen, HIGH);
		delay(250);
		digitalWrite(pedGreen, LOW);
		delay(250);
         }
 	  			
        digitalWrite(pedRed, HIGH);//turn ped red on
	delay(500);

	digitalWrite(carRed, LOW); //red off
	digitalWrite(carYellow, HIGH); //yellow on	
	delay(1000);
	digitalWrite(carYellow, LOW); //yellow off
        digitalWrite(carGreen, HIGH); 

	changeTime = millis(); //record the time since last change of lights
	//then return to the main program loop
}

