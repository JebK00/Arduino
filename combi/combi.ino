const int MD_controlPin1 = 2;
const int MD_controlPin2 = 3;
const int MD_enablePin = 4;

const int MG_controlPin1 = 8;
const int MG_controlPin2 = 9;
const int MG_enablePin = 10;

int MD_status = 0;
int MG_status = 0;

int MD_direction = 0;
int MG_direction = 0;

const int lumGPin = A0;
const int lumDPin = A1;

int lumG;
int lumD;

const int controlPin1 = 5;
const int controlPin2 = 7;
const int enablePin = 6;
const int directionSwitchPin = 11;
const int onOffSwitchStateSwitchPin = 12;

int onOffSwitchState = 0;
int previousOnOffSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

int buttonState = 0;
int previousButtonState = 0;
int robotEnabled = 0;

int embobState = 0;
bool temp = LOW;

int a = 0;

void setup() {
  pinMode(MD_controlPin1, OUTPUT);
  pinMode(MD_controlPin2, OUTPUT);
  pinMode(MD_enablePin, OUTPUT);
  
  pinMode(MG_controlPin1, OUTPUT);
  pinMode(MG_controlPin2, OUTPUT);
  pinMode(MG_enablePin, OUTPUT);

  pinMode(directionSwitchPin, INPUT);
  pinMode(onOffSwitchStateSwitchPin, INPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW);

  Serial.begin(9600);
}

void loop() {
  embobState = digitalRead(embobPin);
  if(embobState == HIGH){
    temp = HIGH;
  }
  buttonState = digitalRead(buttonPin);
  delay(1);
  if (buttonState != previousButtonState) {
    if (buttonState == HIGH) {
      robotEnabled = !robotEnabled;
      if (robotEnabled == 1) {
        a = 0; 
      }
    }
  }
  if (robotEnabled == 1) {
    lumG = analogRead(lumGPin);
    lumD = analogRead(lumDPin);
    Serial.print("lumG: ");
    Serial.print(lumG);
    Serial.print(" - lumD: ");
    Serial.println(lumD);
    digitalWrite(MD_controlPin1, HIGH);
    digitalWrite(MD_controlPin2, LOW);
    digitalWrite(MG_controlPin1, HIGH);
    digitalWrite(MG_controlPin2, LOW);
    analogWrite(MD_enablePin, 150);
    analogWrite(MG_enablePin, 150);
    if (lumG<100 & (min(lumG, lumD) == lumG)){
      Serial.println("Gauche");
      digitalWrite(MD_controlPin1, HIGH);
      digitalWrite(MD_controlPin2, LOW);
      digitalWrite(MG_controlPin1, LOW);
      digitalWrite(MG_controlPin2, HIGH);
      analogWrite(MD_enablePin, 120);
      analogWrite(MG_enablePin, 120);
    }
    if (lumD<100 & (min(lumG, lumD) == lumD)){
      Serial.println("Droite");
      digitalWrite(MD_controlPin1, LOW);
      digitalWrite(MD_controlPin2, HIGH);
      digitalWrite(MG_controlPin1, HIGH);
      digitalWrite(MG_controlPin2, LOW);
      analogWrite(MD_enablePin, 120);
      analogWrite(MG_enablePin, 120);
    }
    delay(500);
  }
  else {
    analogWrite(MD_enablePin, 0);
    analogWrite(MG_enablePin, 0);
    digitalWrite(MD_controlPin1, LOW);
    digitalWrite(MD_controlPin2, LOW);
    digitalWrite(MG_controlPin1, LOW);
    digitalWrite(MG_controlPin2, LOW);
  }
  if (temp = HIGH){
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
    analogWrite(enablePin, HIGH);
    delay(5000);
    temp = LOW;
  }
  previousButtonState = buttonState;
}
