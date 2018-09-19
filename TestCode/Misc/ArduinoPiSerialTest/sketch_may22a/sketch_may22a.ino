#include "Time.h"

void setup() {
 
   Serial.begin(9600);
   while(!Serial);
 
   setTime(11, 15, 0, 22, 5, 2018);
  
}

void loop(){

  Serial.print("Arduino time is ");
  Serial.print(hour());
  print2digits(minute());
  print2digits(second());
  
  Serial.print(" ");
  
  Serial.print(day());
  Serial.print("/");
  Serial.print(month());
  Serial.print("/");
  Serial.print(year());
  
  Serial.println();
  
  delay(1000);
  

}


void print2digits(int number) {

    Serial.print(":");
    
    if (number >= 0 && number <10) {
      Serial.print('0');
    }
    
    Serial.print(number);
}
