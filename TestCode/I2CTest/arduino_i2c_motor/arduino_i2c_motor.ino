#include <Wire.h>

const int slave_addr = 0x04;
const int LED = 13;

int number = 0;


void setup() {
  // put your setup code here, to run once:

  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Wire.begin(slave_addr);
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);

  Serial.println("Ready!");


}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
}

void receiveData(int byteCount) {

  Serial.print("receiveData");
  while (Wire.available()) {
    number = Wire.read();
    Serial.print("data received: ");
    Serial.println(number);

    if (number == 1) {
      Serial.println(" LED ON");
      digitalWrite(LED, HIGH);
    } else {
      Serial.println(" LED OFF");
      digitalWrite(LED, LOW);
    }
  }
}

void sendData() {
  Wire.write(number);
}
