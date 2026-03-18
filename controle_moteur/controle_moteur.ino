/// initiate constant variable for control of right motor
const int MD_controlPin1 = 2;
const int MD_controlPin2 = 3;
const int MD_enablePin = 5;

/// initiate constant variable for control of left motor
const int MG_controlPin1 = 8;
const int MG_controlPin2 = 9;
const int MG_enablePin = 10;

/// initiate motors status; 0 = off   1 = on 
int MD_status = 0;
int MG_status = 0;

/// initiate motors direction; 0 = forward   1 = rearward
int MD_direction = 0;
int MG_direction = 0;

void setup() {
  pinMode(MD_controlPin1, OUTPUT);
  pinMode(MD_controlPin2, OUTPUT);
  pinMode(MD_enablePin, OUTPUT);
  
  pinMode(MG_controlPin1, OUTPUT);
  pinMode(MG_controlPin2, OUTPUT);
  pinMode(MG_enablePin, OUTPUT);
}

void loop() {
  digitalWrite(MD_controlPin1, HIGH);
  digitalWrite(MD_controlPin2, LOW);
  digitalWrite(MG_controlPin1, HIGH);
  digitalWrite(MG_controlPin2, LOW);
  while (millis() < 5000){
    analogWrite(MD_enablePin, HIGH);
    analogWrite(MG_enablePin, HIGH);
  }
  while (millis() < 10000 && millis() >= 5000){
    analogWrite(MD_enablePin, 191);
    analogWrite(MG_enablePin, 191);
  }
  while (millis() < 15000 && millis() >= 10000){
    analogWrite(MD_enablePin, 127);
    analogWrite(MG_enablePin, 127);
  }
  while (millis() < 20000 && millis() >= 15000){
    analogWrite(MD_enablePin, 64);
    analogWrite(MG_enablePin, 64);
  }
  delay(5000);
}
