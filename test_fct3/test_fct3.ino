int lumG;
int lumC;
int lumD;

int lumHigh;
int lumLow;

void setup() {
  Serial.begin(9600);
}

void loop() {
  lumG = analogRead(A0);
  lumC = analogRead(A2);
  lumD = analogRead(A1);
  Serial.print("lumG: ");
  Serial.print(lumG);
  Serial.print(" - lumC: ");
  Serial.print(lumC);
  Serial.print(" - lumD: ");
  Serial.println(lumD);
  delay(1000);
}
