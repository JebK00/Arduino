int lumG;
int lumC;
int lumD;

int lumSol = 0;
int lumTrait = 1023;

int calibVal;

const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  while (millis() < 5000){
    calibVal = max(max(analogRead(A0), analogRead(A1)), max(analogRead(A0), analogRead(A2)));
    if (calibVal > lumSol)
      lumSol = calibVal;
  }
  
  digitalWrite(ledPin, LOW);
  delay(500);
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);

  digitalWrite(ledPin, HIGH);

  while (millis() > 6500 && millis() < 11500){
    calibVal = min(min(analogRead(A0), analogRead(A1)), min(analogRead(A0), analogRead(A2)));
    if (calibVal < lumTrait)
      lumTrait = calibVal;
  }

  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
  Serial.print("Sol: ");
  Serial.print(lumSol);
  Serial.print(" - Trait: ");
  Serial.println(lumTrait);
}

void loop() {
  
}
