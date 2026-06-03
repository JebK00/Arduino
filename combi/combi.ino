/// initiate constant variable for control of right motor
const int MD_controlPin1 = 2;
const int MD_controlPin2 = 3;
const int MD_enablePin = 4;

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

  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
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
