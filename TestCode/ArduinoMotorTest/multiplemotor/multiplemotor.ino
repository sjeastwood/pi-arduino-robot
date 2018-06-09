//testing 2 motors - OK w/ power supply
//testing 3 motors - OK w/ power supply
//testing 4 motors - OK w/ power supply
//testing 5 motors - need a separate source
//testing 6 motors - need a separate source

//do a test with battery packs 3 motor to each pack


#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

int servo1pin = 3;
int servo2pin = 5;
int servo3pin = 6; 
int servo4pin = 9;
int servo5pin = 10;
int servo6pin = 11;

const byte maxSerial = 24;
char fromPi[maxSerial];

int motor[6];

boolean finished = false;

void setup(){
  Serial.begin(9600);
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
}

void loop(){

  Serial.println("Ready!");
  while (Serial.available() == 0) {} //do nothing while waiting for input
  
  readSerial();
  parseSerial();

  moveServo(servo1,motor[0]);
  moveServo(servo2,motor[0]);
  moveServo(servo3,motor[0]);
  moveServo(servo4,motor[0]);
  moveServo(servo5,motor[0]);
  moveServo(servo6,motor[0]);
  delay(1000);
  
  moveServo(servo1,motor[1]);
  moveServo(servo2,motor[1]);
  moveServo(servo3,motor[1]);
  moveServo(servo4,motor[1]);
  moveServo(servo5,motor[1]);
  moveServo(servo6,motor[1]);
  delay(1000);
  
  moveServo(servo1,motor[2]);
  moveServo(servo2,motor[2]);
  moveServo(servo3,motor[2]);
  moveServo(servo4,motor[2]);
  moveServo(servo5,motor[2]);
  moveServo(servo6,motor[2]);
  delay(1000);
  
  moveServo(servo1,motor[3]);
  moveServo(servo2,motor[3]);
  moveServo(servo3,motor[3]);
  moveServo(servo4,motor[3]);
  moveServo(servo5,motor[3]);
  moveServo(servo6,motor[3]);
  delay(1000);
  
  moveServo(servo1,motor[4]);
  moveServo(servo2,motor[4]);
  moveServo(servo3,motor[4]);
  moveServo(servo4,motor[4]);
  moveServo(servo5,motor[4]);
  moveServo(servo6,motor[4]);
  delay(1000);
  
  moveServo(servo1,motor[5]);
  moveServo(servo2,motor[5]);
  moveServo(servo3,motor[5]);
  moveServo(servo4,motor[5]);
  moveServo(servo5,motor[5]);
  moveServo(servo6,motor[5]);
  delay(1000);

  
  
  //delay(1000);
}

void readSerial(){

          static byte readind = 0;
          char currentRead;
          char ending = ';';
          char separator = ',';
         
          
            while (Serial.available() > 0 && finished == false){
            currentRead = Serial.read();
        
            if (currentRead != ending) {
        
              fromPi[readind] = currentRead;
              readind++;
        
              if (readind >= maxSerial) {
                readind = maxSerial - 1;
              } 
        
            }
        
            else {
              fromPi[readind] = currentRead;
              fromPi[readind] = '\0';
              //change the previous lines to store the final index instead for string parsing
              //and motor co-ordination
              readind = 0;
              finished = true;
        
            }
        
          }
  
  }



  void parseSerial() {

  
        if (finished) {
          Serial.print("Transfer complete!\n");
          Serial.print("The received angles are: ");
          Serial.println(fromPi);
      
          int j = 0;
          int ip = 0;
          char *p = strtok(fromPi,",");
      
          while (p) {
      
            if(ip < 6){
      
              motor[ip++] = atoi(p);
            
            }
      
            p = strtok(NULL,",");
          
          }
      
          
    Serial.print("First motor angle: ");
    Serial.print(motor[0]);
    Serial.print("\n");

    Serial.print("Second motor angle: ");
    Serial.print(motor[1]);
    Serial.print("\n");

    Serial.print("Third motor angle: ");
    Serial.print(motor[2]);
    Serial.print("\n");

    Serial.print("Fourth motor angle: ");
    Serial.print(motor[3]);
    Serial.print("\n");

    Serial.print("Fifth motor angle: ");
    Serial.print(motor[4]);
    Serial.print("\n");

    Serial.print("Sixth motor angle: ");
    Serial.print(motor[5]);
    Serial.print("\n");
          
        }
      
        finished = false;
  
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
