const int switchPin = 2;
const int motorPin = 9;
int motorState = LOW;
int buttonState;
int lastButtonState = LOW;
void setup(){
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
}
void loop() {
  buttonState = digitalRead(switchPin);
  if (buttonState == HIGH && lastButtonState == LOW){
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