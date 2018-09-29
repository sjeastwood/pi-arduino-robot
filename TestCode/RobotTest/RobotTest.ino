#include <Servo.h>

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

void setup(){
  Serial.begin(9600);
  servo1.attach(servo1pin);
  servo2.attach(servo2pin);
  servo3.attach(servo3pin);
  servo4.attach(servo4pin);
  servo5.attach(servo5pin);
  servo6.attach(servo6pin);
  
  /*
  motorReset(servo1);
  motorReset(servo2);
  motorReset(servo3);
  motorReset(servo4);
  motorReset(servo5);
  motorReset(servo6);
*/
}

void loop(){

  moveServo(servo1,90);
  moveServo(servo2,90);
  moveServo(servo3,20);
  moveServo(servo4,0);
  moveServo(servo5,90);
  moveServo(servo6,0);
  delay(10000);

/*
  moveServo(servo1,0);
  moveServo(servo2,180);
  moveServo(servo3,0);
  moveServo(servo4,0);
  moveServo(servo5,0);
  moveServo(servo6,0);
  delay(10000);

  moveServo(servo1,0);
  moveServo(servo2,45);
  moveServo(servo3,0);
  moveServo(servo4,0);
  moveServo(servo5,0);
  moveServo(servo6,0);
  delay(10000);
 
*/
  

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
