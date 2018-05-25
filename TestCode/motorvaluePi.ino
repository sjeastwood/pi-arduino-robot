

char fromPi[] = "120,90,60,135,75,25";

int motor[6];

int index[5];




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
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


  
//  for (int i = 0; i < sizeof(fromPi) - 1; i++){
//
//      if (fromPi[i] == separator) {
//        index[j] = i;
//        j++;
//      }         
//  }

  delay(5000);

}
