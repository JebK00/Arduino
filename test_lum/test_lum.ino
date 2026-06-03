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

const int bouton = 13;
const int LEDpin = A2;

int boutonStatus = 0;
int boutonPreviousStatus = 0;

void setup() {
  pinMode(MD_controlPin1, OUTPUT);
  pinMode(MD_controlPin2, OUTPUT);
  pinMode(MD_enablePin, OUTPUT);
  
  pinMode(MG_controlPin1, OUTPUT);
  pinMode(MG_controlPin2, OUTPUT);
  pinMode(MG_enablePin, OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  boutonStatus = digitalRead(bouton);
  if (boutonStatus != boutonPreviousStatus){
    boutonPreviousStatus = boutonPrevious
    if (boutonStatus = HIGH){
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
      analogWrite(MD_enablePin, 250);
      analogWrite(MG_enablePin, 250);
      if (lumG<10 & (min(lumG, lumD) == lumG)){
        Serial.println("Gauche");
        digitalWrite(MD_controlPin1, HIGH);
        digitalWrite(MD_controlPin2, LOW);
        digitalWrite(MG_controlPin1, LOW);
        digitalWrite(MG_controlPin2, HIGH);
        analogWrite(MD_enablePin, 250);
        analogWrite(MG_enablePin, 250);
      }
      if (lumD<10 & (min(lumG, lumD) == lumD)){
        Serial.println("Droite");
        digitalWrite(MD_controlPin1, LOW);
        digitalWrite(MD_controlPin2, HIGH);
        digitalWrite(MG_controlPin1, HIGH);
        digitalWrite(MG_controlPin2, LOW);
        analogWrite(MD_enablePin, 250);
        analogWrite(MG_enablePin, 250);
      }
      delay(500);
    }
    if (boutonStatus = LOW){
      analogWrite(MD_enablePin, 0);
      analogWrite(MG_enablePin, 0);
    }
  }
}
