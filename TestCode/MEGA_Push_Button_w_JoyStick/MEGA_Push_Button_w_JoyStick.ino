//Shane Eastwood
//The following project is built on a MEGA
//This code is designed to test the use of push buttons to increment LEDs
//Goal is to allow it to register a single push to allow for a selection of motor
//This will be represented by a single click moving up and down the line of LEDs 
//Integrating the Pushbutton code with a joystick to mimic course/fine adjustments of the motor
//4 Push buttons = selecting motors: UP and DOWN and motor movement: COARSE and FINE 
//


const int led1 = 22;
const int led2 = 24;
const int led3 = 26;
const int led4 = 28;
const int led5 = 30;
const int led6 = 32;

const int gLED1 = 48;
const int gLED2 = 46;
const int gLED3 = 44;
const int gLED4 = 42;
const int gLED5 = 40;
const int gLED6 = 38;

const int buttonUp = 34;
const int buttonDown = 36;

const int buttonCoarse = 35;
const int buttonFine = 37;

int ledCount = 1;
int ledSelect = 0;

int buttonUpState; // current reading of up button
int lastButtonUpState = HIGH; //previous reading of up button - at start of program it is high due to pullup
int buttonDownState; // current reading of down button
int lastButtonDownState = HIGH; //previous reading of down button - at start of program it is high due to pullup
int buttonCoarseState; // current reading of coarse button
int lastButtonCoarseState = HIGH; //previous reading of coarse button - at start of program it is high due to pullup
int buttonFineState; // current reading of fine button
int lastButtonFineState = HIGH; //previous reading of fine button - at start of program it is high due to pullup

bool motorCoarse = true; //a flag to determine if motor control will be coarse or fine

unsigned long lastDebounceUpTime = 0;
unsigned long lastDebounceDownTime = 0;
unsigned long lastDebounceCoarseTime = 0;
unsigned long lastDebounceFineTime = 0;
unsigned long debounceDelay = 50;



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

void setup() {
  Serial.begin(9600);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);

  pinMode(gLED1, OUTPUT);
  pinMode(gLED2, OUTPUT);
  pinMode(gLED3, OUTPUT);
  pinMode(gLED4, OUTPUT);
  pinMode(gLED5, OUTPUT);
  pinMode(gLED6, OUTPUT);
  

  //button press == LOW so set input pin to be always high
  pinMode(buttonUp, INPUT_PULLUP);
  pinMode(buttonDown, INPUT_PULLUP);
  pinMode(buttonCoarse, INPUT_PULLUP);
  pinMode(buttonFine, INPUT_PULLUP);

}

void loop() {

  //illuminate the current selected LED
  //At the start of this program it is the first LED
  ledSelect = SelectLED(ledCount);
  digitalWrite(ledSelect,HIGH);

  int readingButtonUp = digitalRead(buttonUp);
  int readingButtonDown = digitalRead(buttonDown);
  int readingButtonCoarse = digitalRead(buttonCoarse);
  int readingButtonFine = digitalRead(buttonFine);

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
    
      if (ledCount == 7){
        ledCount = 1; //resets back to the first LED once the count reaches the sixth
      }
    
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
            //turn off previous selected LED
            digitalWrite(ledSelect, LOW);
        
            ledCount--;
        
            if (ledCount == 0){
              ledCount = 6; //resets back to the sixth LED once the count reaches the first
            }
            
            ledSelect = SelectLED(ledCount); //takes the incremented ledCount to the switch function
            //once the correct LED is selected, the LED is then illuminated
            digitalWrite(ledSelect, HIGH);     
          }  
    }
    
  }
  
  //debounce logic for Coarse Button
  if (readingButtonCoarse != lastButtonCoarseState) {
    //reset debouncing timer
    lastDebounceCoarseTime = millis();
  }

  if ((millis() - lastDebounceCoarseTime) > debounceDelay){
    //if enough time has passed since the last change of state, then the reading will be true
    if (readingButtonCoarse != buttonCoarseState){
      buttonCoarseState = readingButtonCoarse;

      
      if (buttonCoarseState == LOW){
            motorCoarse = true;
            Serial.print("Motor Control: Coarse\n");
          }  
    }
    
  }


  //debounce logic for Fine Button
  if (readingButtonFine != lastButtonFineState) {
    //reset debouncing timer
    lastDebounceFineTime = millis();
  }

  if ((millis() - lastDebounceFineTime) > debounceDelay){
    //if enough time has passed since the last change of state, then the reading will be true
    if (readingButtonFine != buttonFineState){
      buttonFineState = readingButtonFine;

      
      if (buttonFineState == LOW){
            motorCoarse = false; //allows the fine turning of the motor
            Serial.print("Motor Control: Fine\n");
          }  
    }
    
  }


//store the last button state
lastButtonUpState = readingButtonUp;
lastButtonDownState = readingButtonDown;
lastButtonCoarseState = readingButtonCoarse;
lastButtonFineState = readingButtonFine;
 
}



