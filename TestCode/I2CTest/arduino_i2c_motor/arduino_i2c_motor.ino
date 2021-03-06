#include <Wire.h>

#define SLAVE_ADDR  0x04

int number = 0;
int motorCount = 0;
int motor[5];

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Wire.begin(SLAVE_ADDR);
  Wire.onRequest(sendData);
  Wire.onReceive(receiveData);
  Serial.println("Ready!");


}

void loop() {
  // put your main code here, to run repeatedly:
  
  number = 1;

  if (motorCount > 5) {
  motors();
  }
  
  delay(100);

}

void receiveData(int byteCount) {

  //Serial.println("receiveData");

  while (Wire.available()) {
    number = Wire.read();
    Serial.print("data received: ");
    Serial.println(number);

 
 
 /*   if (number == 1) {
      Serial.println(" LED ON");
      digitalWrite(LED, HIGH);
    } else {
      Serial.println(" LED OFF");
      digitalWrite(LED, LOW);
    }
 */
      motor[motorCount] = number;
      Serial.print("motor value: ");
      Serial.println(motor[motorCount]);
      motorCount++;
      Serial.print("motorCount : ");
      Serial.println(motorCount);
  }
}

void motors(){
      
      Serial.print("First motor: ");
      Serial.print(motor[0]);
      Serial.print("\n");
      Serial.print("Second motor: ");
      Serial.print(motor[1]);
      Serial.print("\n");
      Serial.print("Third motor: ");
      Serial.print(motor[2]);
      Serial.print("\n");
      Serial.print("Fourth motor: ");
      Serial.print(motor[3]);
      Serial.print("\n");
      Serial.print("Fifth motor: ");
      Serial.print(motor[4]);
      Serial.print("\n");
      Serial.print("Sixth motor: ");
      Serial.print(motor[5]);
      Serial.print("\n");
         
      motorCount = 0;  //resetting the motor Count to zero for more data entry
    
}

void sendData() {
  Wire.write(number);
}
