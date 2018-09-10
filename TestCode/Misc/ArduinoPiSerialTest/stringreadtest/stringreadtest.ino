String fromPi;
//String test = "test\n";

void setup(){
  Serial.begin(9600);

}


void loop() {     
     
  while(Serial.available() == 0) {}
  
  //Serial.print(test);
  fromPi = Serial.readString();   
 // test = fromPi;  
  Serial.println(fromPi);
  Serial.print("\n");
}
