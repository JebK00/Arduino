/// initiate constant variable for control of right motor
const int MD_controlPin1 = 2;
const int MD_controlPin2 = 3;
const int MD_enablePin = 5;

/// initiate constant variable for control of left motor
const int MG_controlPin1 = 8;
const int MG_controlPin2 = 9;
const int MG_enablePin = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(MD_controlPin1, OUTPUT);
  pinMode(MD_controlPin2, OUTPUT);
  pinMode(MD_enablePin, OUTPUT);
  
  pinMode(MG_controlPin1, OUTPUT);
  pinMode(MG_controlPin2, OUTPUT);
  pinMode(MG_enablePin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  analogWrite(MD_enablePin, LOW);
  analogWrite(MG_enablePin, LOW);
  delay(5000);
  digitalWrite(MD_controlPin1, HIGH);
  digitalWrite(MD_controlPin2, LOW);
  digitalWrite(MG_controlPin1, LOW);
  digitalWrite(MG_controlPin2, HIGH);
  analogWrite(MD_enablePin, 255);
  analogWrite(MG_enablePin, 255);
  
  delay(1000);
  analogWrite(MD_enablePin, LOW);
  analogWrite(MG_enablePin, LOW);
  delay(5000);
  digitalWrite(MD_controlPin1, LOW);
  digitalWrite(MD_controlPin2, HIGH);
  digitalWrite(MG_controlPin1, HIGH);
  digitalWrite(MG_controlPin2, LOW);
  analogWrite(MD_enablePin, 255);
  analogWrite(MG_enablePin, 255);
  
}
