//Shane Eastwood
//This code is designed to test the use of push buttons to increment LEDs
//Goal is to allow it to register a single push to allow for a selection of motor
//This will be represented by a single click moving up and down the line of LEDs 


const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int led5 = 6;
const int led6 = 7;

const int buttonUp = 11;
const int buttonDown = 13;

int ledCount = 1;
int ledSelect = 0;
int buttonUpState; // current reading of up button
int lastButtonUpState = HIGH; //previous reading of up button - at start of program it is high due to pullup
int buttonDownState; // current reading of down button
int lastButtonDownState = HIGH; //previous reading of down button - at start of program it is high due to pullup

unsigned long lastDebounceUpTime = 0;
unsigned long lastDebounceDownTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);

  //button press == LOW so set input pin to be always high
  pinMode(buttonUp, INPUT_PULLUP);
  pinMode(buttonDown, INPUT_PULLUP);

}

void loop() {

  //illuminate the current selected LED
  //At the start of this program it is the first LED
  ledSelect = SelectLED(ledCount);
  digitalWrite(ledSelect,HIGH);

  int readingButtonUp = digitalRead(buttonUp);
  int readingButtonDown = digitalRead(buttonDown);


//debounce logic for Up Button
  if (readingButtonUp != lastButtonUpState) {
    //reset debouncing timer
    lastDebounceUpTime = millis();
  }

  if ((millis() - lastDebounceUpTime) > debounceDelay){
    //if enough time has passed since the last change of state, then the reading will be true
    if (readingButtonUp != buttonUpState){
      buttonUpState = readingButtonUp;

      if (buttonUpState == LOW){

      //set the current LED to off
      digitalWrite(ledSelect, LOW);
    
      //increase the LED count to the next one

      ledCount++;

    
      Serial.println(ledCount);
    
      if (ledCount == 7){
        ledCount = 1; //resets back to the first LED once the count reaches the sixth
      }
      Serial.println(ledCount);
    
      ledSelect = SelectLED(ledCount); //takes the incremented ledCount to the switch function
      //once the correct LED is selected, the LED is then illuminated
      digitalWrite(ledSelect, HIGH);
      }


      
    }
    
  }


  //debounce logic for Down Button
  if (readingButtonDown != lastButtonDownState) {
    //reset debouncing timer
    lastDebounceDownTime = millis();
  }

  if ((millis() - lastDebounceDownTime) > debounceDelay){
    //if enough time has passed since the last change of state, then the reading will be true
    if (readingButtonDown != buttonDownState){
      buttonDownState = readingButtonDown;

      
      if (buttonDownState == LOW){
            digitalWrite(ledSelect, LOW);
        
            ledCount--;
            Serial.println(ledCount);
        
            if (ledCount == 0){
              ledCount = 6; //resets back to the sixth LED once the count reaches the first
            }
            Serial.println(ledCount);
            
            ledSelect = SelectLED(ledCount); //takes the incremented ledCount to the switch function
            //once the correct LED is selected, the LED is then illuminated
            digitalWrite(ledSelect, HIGH);     
          }  
    }
    
  }
  
//  if (buttonUpState == LOW){
//
//    //set the current LED to off
//    digitalWrite(ledSelect, LOW);
//    
//    //increase the LED count to the next one
//
//    ledCount++;
//
//    
//    Serial.println(ledCount);
//    
//    if (ledCount == 7){
//      ledCount = 1; //resets back to the first LED once the count reaches the sixth
//    }
//    Serial.println(ledCount);
//    
//    ledSelect = SelectLED(ledCount); //takes the incremented ledCount to the switch function
//    //once the correct LED is selected, the LED is then illuminated
//    digitalWrite(ledSelect, HIGH);
//  }

//      if (buttonDownState == LOW){
//        digitalWrite(ledSelect, LOW);
//    
//        ledCount--;
//        Serial.println(ledCount);
//    
//        if (ledCount == 0){
//          ledCount = 6; //resets back to the sixth LED once the count reaches the first
//        }
//        Serial.println(ledCount);
//        
//        ledSelect = SelectLED(ledCount); //takes the incremented ledCount to the switch function
//        //once the correct LED is selected, the LED is then illuminated
//        digitalWrite(ledSelect, HIGH);     
//      }

//store the last button state
lastButtonUpState = readingButtonUp;
lastButtonDownState = readingButtonDown;
 
}

int SelectLED(int select) {

//takes the value incremented by the push buttons and sends the correct pin number for LED to light

  switch (select) {
    case 1:
      return led1;
    case 2:
      return led2;
    case 3:
      return led3;
    case 4:
      return led4;
    case 5:
      return led5;
    case 6:
      return led6;
    default:
      return led1;
  }
  
}

