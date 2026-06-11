#include <ESP32Servo.h>

Servo servo1;
Servo servo2;

int openPos1  = 0;
int closePos1 = 90;

int openPos2  = 90;
int closePos2 = 0;

const int buttonPin = 4;

bool grabbed = false;        // current state
bool lastButtonState = HIGH;

void setup() {
  servo1.attach(18);
  servo2.attach(19);

  pinMode(buttonPin, INPUT_PULLUP);

  // Start OPEN
  //servo1.write(openPos1);
  servo2.write(openPos2);
}

void loop() {

  bool buttonState = digitalRead(buttonPin);

  // Detect button press
  if (lastButtonState == HIGH && buttonState == LOW) {

    grabbed = !grabbed;   // toggle state

    if (grabbed) {
      // CLOSE (grab)
      //servo1.write(closePos1);
      servo2.write(closePos2);
    }
    else {
      // OPEN (release)
      //servo1.write(openPos1);
      servo2.write(openPos2);
    }

    delay(200); // debounce
  }

  lastButtonState = buttonState;
}