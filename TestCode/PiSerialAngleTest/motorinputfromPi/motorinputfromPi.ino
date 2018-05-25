

const byte maxSerial = 24;
char fromPi[maxSerial];

boolean finished = false;

void setup(){
  Serial.begin(9600);

}

void loop(){

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


  Serial.println(fromPi);
  finished = false;
  delay(2000);
}

