String fromPi = "120,90,60,45,180,32;";

char separator = ',';
char ending = ';';

String first;
String second;
String third;
String fourth;
String fifth;
String sixth;

int one;
int two;
int three;
int four;
int five;
int six;

int ind1;
int ind2;
int ind3;
int ind4;
int ind5;
int ind6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  ind1 = fromPi.indexOf(separator);
  ind2 = fromPi.indexOf(separator, ind1 + 1);
  ind3 = fromPi.indexOf(separator, ind2 + 1);
  ind4 = fromPi.indexOf(separator, ind3 + 1);
  ind5 = fromPi.indexOf(separator, ind4 + 1);
  ind6 = fromPi.indexOf(ending);


  first = fromPi.substring(0, ind1);
  second = fromPi.substring(ind1 + 1, ind2);
  third = fromPi.substring(ind2+1 , ind3);
  fourth = fromPi.substring(ind3+1 , ind4);
  fifth = fromPi.substring(ind4+1 , ind5);  
  sixth = fromPi.substring(ind5+1 , ind6);

  Serial.print("For troubleshooting....\n");
  Serial.print("The first substring is: ");
  Serial.print(first);
  Serial.print("\n");

  Serial.print("The second substring is: ");
  Serial.print(second);
  Serial.print("\n");

  Serial.print("The third substring is: ");
  Serial.print(third);
  Serial.print("\n");

  Serial.print("The fourth substring is: ");
  Serial.print(fourth);
  Serial.print("\n");

  Serial.print("The fifth substring is: ");
  Serial.print(fifth);
  Serial.print("\n");

  Serial.print("The sixth substring is: ");
  Serial.print(sixth);
  Serial.print("\n");


  one = first.toInt();
  two = second.toInt();
  three = third.toInt();
  four = fourth.toInt();
  five = fifth.toInt();
  six = sixth.toInt();

  Serial.print("Recovered angles that would be sent from the rPi serial data to Arduino for motor control.\n");
  Serial.print("The first angle is: ");
  Serial.print(one);
  Serial.print("\n");
  
  Serial.print("The second angle is: ");
  Serial.print(two);
  Serial.print("\n");
  
  Serial.print("The third angle is: ");
  Serial.print(three);
  Serial.print("\n");
  
  Serial.print("The fourth angle is: ");
  Serial.print(four);
  Serial.print("\n");

  Serial.print("The fifth angle is: ");
  Serial.print(five);
  Serial.print("\n");

  Serial.print("The sixth angle is: ");
  Serial.print(six);
  Serial.print("\n");

  
  delay(5000);

  
}
