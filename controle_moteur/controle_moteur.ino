/// initiate constant variable for control of right motor
const int MD_controlPin1 = 2;
const int MD_controlPin2 = 3;
const int MD_enablePin = 5;

/// initiate constant variable for control of left motor
const int MG_controlPin1 = 8;
const int MG_controlPin2 = 9;
const int MG_enablePin = 10;

const int lumGPin = A0;
const int lumDPin = A1;

/// initiate motors status; 0 = off   1 = on 
int MD_status = 0;
int MG_status = 0;

/// initiate motors direction; 0 = forward   1 = rearward
int MD_direction = 0;
int MG_direction = 0;

/// initiate lum data
int lumG;
int lumD;

void setup() {
  pinMode(MD_controlPin1, OUTPUT);
  pinMode(MD_controlPin2, OUTPUT);
  pinMode(MD_enablePin, OUTPUT);
  
  pinMode(MG_controlPin1, OUTPUT);
  pinMode(MG_controlPin2, OUTPUT);
  pinMode(MG_enablePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lumG = analogRead(lumGPin);
  lumD = analogRead(lumDPin);
  Serial.print("lumG: ");
  Serial.print(lumG);
  Serial.print(" - lumD: ");
  Serial.println(lumD);  
  if (abs(lumG-lumD)<200){
    digitalWrite(MD_controlPin1, HIGH);
    digitalWrite(MD_controlPin2, LOW);
    digitalWrite(MG_controlPin1, HIGH);
    digitalWrite(MG_controlPin2, LOW);
    analogWrite(MD_enablePin, 200);
    analogWrite(MG_enablePin, 200);
    Serial.println("For");
  }
  if (abs(lumG-lumD)>100 && min(lumG, lumD) == lumG){
    delay(500);
    digitalWrite(MD_controlPin1, HIGH);
    digitalWrite(MD_controlPin2, LOW);
    digitalWrite(MG_controlPin1, LOW);
    digitalWrite(MG_controlPin2, HIGH);
    analogWrite(MD_enablePin, 255);
    analogWrite(MG_enablePin, 255);
    Serial.println("left");
  }
  if (abs(lumG-lumD)>200 && min(lumG, lumD) == lumD){
    delay(500);
    digitalWrite(MD_controlPin1, LOW);
    digitalWrite(MD_controlPin2, HIGH);
    digitalWrite(MG_controlPin1, HIGH);
    digitalWrite(MG_controlPin2, LOW);
    analogWrite(MD_enablePin, 255);
    analogWrite(MG_enablePin, 255);
    Serial.println("right");
  }
}
