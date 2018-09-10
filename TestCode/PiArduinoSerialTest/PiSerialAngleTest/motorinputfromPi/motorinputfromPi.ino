//To DO: remove the motor data lines 
//Test with just Ready! and Complete! messages

const byte maxSerial = 24;
char fromPi[maxSerial];

int motor[6];

int index[5];


boolean finished = false;

void setup(){
  Serial.begin(9600);

}

void loop(){

  static byte readind = 0;
  char currentRead;
  char ending = ';';
  char separator = ',';
 
  Serial.println("Ready!");

  
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

    /*
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
    */
  }

  finished = false;
  //delay(1000);
}

