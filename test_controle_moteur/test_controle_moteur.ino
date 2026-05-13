// Broches Moteur Droit (MD) et Gauche (MG)
const int MD_controlPin1 = 2; const int MD_controlPin2 = 3; const int MD_enablePin = 5;
const int MG_controlPin1 = 8; const int MG_controlPin2 = 9; const int MG_enablePin = 10;

// Broches Capteurs (LDR)
const int lumGPin = A0; const int lumDPin = A1; const int lumCPin = A2;

int lumG; int lumD; int lumC;
int lumMin = 1023; int lumMax = 0; int seuilDetection = 0;

void setup() {
  pinMode(MD_controlPin1, OUTPUT); pinMode(MD_controlPin2, OUTPUT); pinMode(MD_enablePin, OUTPUT);
  pinMode(MG_controlPin1, OUTPUT); pinMode(MG_controlPin2, OUTPUT); pinMode(MG_enablePin, OUTPUT);
  Serial.begin(9600);

  // Début de la rotation sur place (MG recule, MD avance)
  digitalWrite(MG_controlPin1, LOW); digitalWrite(MG_controlPin2, HIGH);
  digitalWrite(MD_controlPin1, HIGH); digitalWrite(MD_controlPin2, LOW);
  analogWrite(MG_enablePin, 200); analogWrite(MD_enablePin, 200);

  unsigned long startTime = millis();
  // Échantillonnage pendant 3000 ms
  while (millis() - startTime < 3000) {
    lumG = analogRead(lumGPin); lumD = analogRead(lumDPin); lumC = analogRead(lumCPin);
    
    int maxActuel = max(lumG, max(lumD, lumC));
    int minActuel = min(lumG, min(lumD, lumC));
    
    if (maxActuel > lumMax) lumMax = maxActuel;
    if (minActuel < lumMin) lumMin = minActuel;
  }
  seuilDetection = (lumMax + lumMin) / 2;

  // Réalignement : baisse de la vitesse de rotation pour minimiser l'inertie
  analogWrite(MG_enablePin, 120); analogWrite(MD_enablePin, 120);
  
  // Boucle d'attente jusqu'à détection de la ligne par le capteur central
  while (analogRead(lumCPin) > seuilDetection) {
    // Le robot continue de tourner lentement
  }

  // Arrêt (freinage inactif, les moteurs sont en roue libre)
  digitalWrite(MG_controlPin1, LOW); digitalWrite(MG_controlPin2, LOW);
  digitalWrite(MD_controlPin1, LOW); digitalWrite(MD_controlPin2, LOW);
  analogWrite(MG_enablePin, 0); analogWrite(MD_enablePin, 0);
  delay(1000); // Pause avant de démarrer la boucle principale
}

void loop() {
  lumG = analogRead(lumGPin); lumD = analogRead(lumDPin); lumC = analogRead(lumCPin);
  
  if (lumC < seuilDetection) {
    digitalWrite(MD_controlPin1, HIGH); digitalWrite(MD_controlPin2, LOW);
    digitalWrite(MG_controlPin1, HIGH); digitalWrite(MG_controlPin2, LOW);
    analogWrite(MD_enablePin, 200); analogWrite(MG_enablePin, 200);
  } else if (lumG < seuilDetection) {
    digitalWrite(MD_controlPin1, HIGH); digitalWrite(MD_controlPin2, LOW);
    digitalWrite(MG_controlPin1, LOW); digitalWrite(MG_controlPin2, HIGH);
    analogWrite(MD_enablePin, 255); analogWrite(MG_enablePin, 255);
  } else if (lumD < seuilDetection) {
    digitalWrite(MD_controlPin1, LOW); digitalWrite(MD_controlPin2, HIGH);
    digitalWrite(MG_controlPin1, HIGH); digitalWrite(MG_controlPin2, LOW);
    analogWrite(MD_enablePin, 255); analogWrite(MG_enablePin, 255);
  } else {
    digitalWrite(MD_controlPin1, LOW); digitalWrite(MD_controlPin2, LOW);
    digitalWrite(MG_controlPin1, LOW); digitalWrite(MG_controlPin2, LOW);
    analogWrite(MD_enablePin, 0); analogWrite(MG_enablePin, 0);
  }
}