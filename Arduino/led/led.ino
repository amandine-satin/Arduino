/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground through 220 ohm resistor
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button
*/

// constants won't change. They're used here to set pin numbers:
// Constants won't change. They're used here to set pin numbers:
// Constants won't change. They're used here to set pin numbers:
// constants won't change. They're used here to set pin numbers:
// constants won't change. They're used here to set pin numbers:
// constants won't change. They're used here to set pin numbers:
// constants won't change. They're used here to set pin numbers:

//(À l'appui du bouton, la LED s’allume)
//const int buttonPin = 34;  // the number of the pushbutton pin
//const int ledPin = 2;    // the number of the LED pin

// variables will change:

//int buttonState = 0;  // variable for reading the pushbutton status

//void setup() {
  // initialize the LED pin as an output:
  //pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  //pinMode(buttonPin, INPUT_PULLUP);
//}

//void loop() {
  // read the state of the pushbutton value:
  //buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  //if (buttonState == LOW) {
    // turn LED on:
    //digitalWrite(ledPin, HIGH);
  //} else {
    // turn LED off:
    //digitalWrite(ledPin, LOW);
  //}
//}

//(En appuyant deux fois sur le bouton, la LED reste allumée)
//const int buttonPin = 34;
//const int ledPin = 2;

//int buttonState = 0;
//int lastButtonState = 0;
//int buttonPresses = 0;
//bool ledState = false;

//void setup() {
  //pinMode(ledPin, OUTPUT);
  //pinMode(buttonPin, INPUT_PULLUP);
//}

//void loop() {
  //buttonState = digitalRead(buttonPin);

  // check for button press
  //if (lastButtonState == HIGH && buttonState == LOW) {
    //buttonPresses++;
    //delay(80); // debounce delay
  //}

  // check if button was pressed twice or three times
  //if (buttonPresses % 3 == 0) {
    //ledState = !ledState; // toggle LED state
    //digitalWrite(ledPin, ledState);
  //}

  //lastButtonState = buttonState; // save the current state as the last state, for next time through the loop
//}


//(En appuyant trois fois sur le bouton, la LED clignote)
//const int buttonPin = 34;
//const int ledPin = 2;

//int buttonState = 0;
//int lastButtonState = 0;
//int buttonPresses = 0;

//void setup() {
  //pinMode(ledPin, OUTPUT);
  //pinMode(buttonPin, INPUT_PULLUP);
//}

//void loop() {
  //buttonState = digitalRead(buttonPin);

   //check for button press
  //if (lastButtonState == HIGH && buttonState == LOW) {
    //buttonPresses++;
    //delay(80); // debounce delay
  //}

  // check if button was pressed three times
  //if (buttonPresses % 3 == 0 && buttonPresses != 0) {
    //blink the LED
    //digitalWrite(ledPin, HIGH);
    //delay(500); // wait for half a second
    //digitalWrite(ledPin, LOW);
    //delay(500); // wait for half a second
  //}

  //lastButtonState = buttonState; // save the current state as the last state, for next time through the loop
//}
//(En cas d'appui prolongé sur le bouton, la LED s'éteint)

const int buttonPin = 34;
const int ledPin = 2;

int buttonState = 0;
unsigned long buttonPressTime = 0;
bool ledState = true;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  digitalWrite(ledPin, ledState);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  // check for button press
  if (buttonState == LOW) {
    if (buttonPressTime == 0) { // if it's the start of the press
      buttonPressTime = millis(); // record the time
    } else if ((millis() - buttonPressTime) > 1000) { // if the button has been pressed for more than 1 second
      ledState = false; // turn off the LED
      digitalWrite(ledPin, ledState);
    }
  } else {
    buttonPressTime = 0; // reset the timer
    ledState = true; // turn on the LED
    digitalWrite(ledPin, ledState);
  }
}
