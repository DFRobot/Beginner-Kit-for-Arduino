#include <IRremote.h>      
int RECV_PIN = 11;         
IRrecv irrecv(RECV_PIN);   
decode_results results;   
int currentNumber = 0;     

long codes[12]=             // this array is used to store infrared codes
{
   0xFD30CF,0xFD08F7,               // 0 ,1
   0xFD8877,0xFD48B7,               // 2 ,3
   0xFD28D7,0xFDA857,               // 4 ,5
   0xFD6897,0xFD18E7,               // 6 ,7
   0xFD9867,0xFD58A7,               // 8 ,9
   0xFD20DF,0xFD609F,               // advance, move back
};

int number[10][8] =            //the array is used to store the number 0~9
{
  {0,0,0,1,0,0,0,1},//0
  {0,1,1,1,1,1,0,1},//1
  {0,0,1,0,0,0,1,1},//2
  {0,0,1,0,1,0,0,1},//3
  {0,1,0,0,1,1,0,1},//4
  {1,0,0,0,1,0,0,1},//5
  {1,0,0,0,0,0,0,1},//6
  {0,0,1,1,1,1,0,1},//7
  {0,0,0,0,0,0,0,1},//8
  {0,0,0,0,1,1,0,1} //9
};

void numberShow(int i) {                  //this function is used to display numbers
  for(int pin = 2; pin <= 9 ; pin++){
     digitalWrite(pin, number[i][pin - 2]);
  }
}

void setup(){
  Serial.begin(9600);            
  irrecv.enableIRIn();          
  
  for(int pin = 2 ; pin <= 9 ; pin++){   
      pinMode(pin, OUTPUT);
      digitalWrite(pin, HIGH);
  }
}

void loop() {
  if (irrecv.decode(&results)) {
      for(int i = 0; i <= 11; i++){
         
         if(results.value == codes[i]&& i <= 9){
               numberShow(i);  // display number 0~9 on the digital control
               currentNumber = i;  
               Serial.println(i);
               break;        
         }
         
         else if(results.value == codes[10]&& currentNumber != 0){
               currentNumber--;                 
               numberShow(currentNumber);       
               Serial.println(currentNumber);  
               break;        
         }
         
         //
         else if(results.value == codes[11]&& currentNumber != 9){
               currentNumber++;                 
               numberShow(currentNumber);      
               Serial.println(currentNumber); 
               break;            
         }
    } 
    
   Serial.println(results.value, HEX); 
   irrecv.resume();   
  }
}

