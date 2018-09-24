#include <Wire.h>
#include <Servo.h>

#define SLAVE_ADDR 0x04
const int LED = 13;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

const int servo1pin = 3;
const int servo2pin = 5;
const int servo3pin = 6; 
const int servo4pin = 9;
const int servo5pin = 10;
const int servo6pin = 11;

int number = 0;
int motorCount = 0;
int motor[5];

void setup() {
  // put your setup code here, to run once:

  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Wire.begin(SLAVE_ADDR);
  Wire.onRequest(sendData);
  Wire.onReceive(receiveData);
  
  servo1.attach(servo1pin);
  servo2.attach(servo2pin);
  servo3.attach(servo3pin);
  servo4.attach(servo4pin);
  servo5.attach(servo5pin);
  servo6.attach(servo6pin);

  motorReset(servo1);
  motorReset(servo2);
  motorReset(servo3);
  motorReset(servo4);
  motorReset(servo5);
  motorReset(servo6);

  Serial.println("Ready!");


}

void loop() {
  // put your main code here, to run repeatedly:
  

  if (motorCount > 5) {
  motors();
  /*
  moveServo(servo1,motor[0]);
  moveServo(servo2,motor[0]);
  moveServo(servo3,motor[0]);
  moveServo(servo4,motor[0]);
  moveServo(servo5,motor[0]);
  moveServo(servo6,motor[0]);
*/
  }
  number = 1;
  
  
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

void sendData() {
  Wire.write(number);
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

void moveServo(Servo servomotor, int input) {
  
  Serial.print("Moving servo ");
  Serial.print(input);
  Serial.print(" degrees...");
  servomotor.write(input);
  Serial.print("Done!\n");
}

void motorReset(Servo servomotor) {

    Serial.print("Resetting Servo to 0 degrees.\n");
    servomotor.write(0);
}
