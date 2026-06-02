const int switchPinB = 1;
const int switchPinRB = 2;
const int enablePin = 7;
const int directionSwitchPin = 7;
int motorState = LOW;
int buttonStateB;
int buttonStateRB;
int lastButtonStateB = LOW;
int lastButtonStateRB = LOW;
int allowRB = 0;

void setup(){
  pinMode(motorPin, OUTPUT);
  pinMode(switchPinB, INPUT);
  pinMode(switchPinRB, INPUT);
}

void loop() {
  buttonStateB = digitalRead(switchPin);
  buttonStateRB = digitalRead(switchPin);
  if (buttonStateB == HIGH && lastButtonState == LOW){
    if (motorState == HIGH){
      motorState = LOW;
    }
    else {
      motorState = HIGH;
    }
    digitalWrite(motorPin, motorState);
    delay(50);
  }
  lastButtonState = buttonState;
}