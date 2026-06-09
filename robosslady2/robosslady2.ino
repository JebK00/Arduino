/// Broche dédiée au bouton (doit supporter les interruptions, ex: D2 sur Uno)
const int buttonPin = 2; 

/// Initialisation des constantes pour le moteur droit
const int MD_controlPin1 = 5; // Déplacé de 2 à 5 pour libérer l'interruption
const int MD_controlPin2 = 3;
const int MD_enablePin = 4;

/// Initialisation des constantes pour le moteur gauche
const int MG_controlPin1 = 8;
const int MG_controlPin2 = 9;
const int MG_enablePin = 10;

int a = 0;

// Variables volatiles requises pour le partage entre l'interruption et le code principal
volatile bool robotActif = false;
volatile unsigned long dernierTempsAppui = 0;

void setup() {
  pinMode(MD_controlPin1, OUTPUT);
  pinMode(MD_controlPin2, OUTPUT);
  pinMode(MD_enablePin, OUTPUT);
  pinMode(MG_controlPin1, OUTPUT);
  pinMode(MG_controlPin2, OUTPUT);
  pinMode(MG_enablePin, OUTPUT);

  // Configuration du bouton avec résistance de tirage interne (pull-up)
  pinMode(buttonPin, INPUT_PULLUP);
  
  // Déclenchement de l'interruption lorsque la broche passe de HIGH à LOW (appui)
  attachInterrupt(digitalPinToInterrupt(buttonPin), basculerEtat, FALLING);
  
  stopperMoteurs();
}

// Fonction d'interruption appelée automatiquement lors de l'appui sur le bouton
void basculerEtat() {
  unsigned long tempsActuel = millis();
  
  // Anti-rebond logiciel de 200 ms
  if (tempsActuel - dernierTempsAppui > 200) {
    robotActif = !robotActif;
    dernierTempsAppui = tempsActuel;
    
    // Arrêt immédiat des moteurs si le robot est désactivé
    if (!robotActif) {
      digitalWrite(MD_enablePin, LOW);
      digitalWrite(MG_enablePin, LOW);
    }
  }
}

// Fonction utilitaire pour garantir l'arrêt physique
void stopperMoteurs() {
  digitalWrite(MD_enablePin, LOW);
  digitalWrite(MG_enablePin, LOW);
  digitalWrite(MD_controlPin1, LOW);
  digitalWrite(MD_controlPin2, LOW);
  digitalWrite(MG_controlPin1, LOW);
  digitalWrite(MG_controlPin2, LOW);
}

void loop() {
  // Si le robot est éteint, on réinitialise les compteurs et on bloque l'exécution
  if (!robotActif) {
    stopperMoteurs();
    a = 0; 
    return; 
  }

  digitalWrite(MD_controlPin1, HIGH);
  digitalWrite(MD_controlPin2, LOW);
  digitalWrite(MG_controlPin1, HIGH);
  digitalWrite(MG_controlPin2, LOW);
  analogWrite(MD_enablePin, 250);
  analogWrite(MG_enablePin, 250);

  delay(1000);
  if (!robotActif) return; // Interruption de la séquence si bascule d'état

  digitalWrite(MD_controlPin1, HIGH);
  digitalWrite(MD_controlPin2, LOW);
  digitalWrite(MG_controlPin1, LOW);
  digitalWrite(MG_controlPin2, HIGH);
  analogWrite(MD_enablePin, 250);
  analogWrite(MG_enablePin, 250);

  delay(350);
  if (!robotActif) return;

  while (a <= 4) {
    if (!robotActif) break; // Sortie immédiate de la boucle while si désactivé

    digitalWrite(MD_controlPin1, HIGH);
    digitalWrite(MD_controlPin2, LOW);
    digitalWrite(MG_controlPin1, HIGH);
    digitalWrite(MG_controlPin2, LOW);
    analogWrite(MD_enablePin, 250);
    analogWrite(MG_enablePin, 250);

    delay(3000);
    if (!robotActif) break;

    digitalWrite(MD_controlPin1, LOW);
    digitalWrite(MD_controlPin2, HIGH);
    digitalWrite(MG_controlPin1, HIGH);
    digitalWrite(MG_controlPin2, LOW);
    analogWrite(MD_enablePin, 200);
    analogWrite(MG_enablePin, 200);

    delay(3000);
    if (!robotActif) break;

    digitalWrite(MD_controlPin1, HIGH);
    digitalWrite(MD_controlPin2, LOW);
    digitalWrite(MG_controlPin1, LOW);
    digitalWrite(MG_controlPin2, HIGH);
    analogWrite(MD_enablePin, 200);
    analogWrite(MG_enablePin, 200);

    delay(100);
    if (!robotActif) break;

    digitalWrite(MD_controlPin1, HIGH);
    digitalWrite(MD_controlPin2, LOW);
    digitalWrite(MG_controlPin1, HIGH);
    digitalWrite(MG_controlPin2, LOW);
    analogWrite(MD_enablePin, 250);
    analogWrite(MG_enablePin, 250);

    delay(3000);
    if (!robotActif) break;

    digitalWrite(MD_controlPin1, HIGH);
    digitalWrite(MD_controlPin2, LOW);
    digitalWrite(MG_controlPin1, LOW);
    digitalWrite(MG_controlPin2, HIGH);
    analogWrite(MD_enablePin, 200);
    analogWrite(MG_enablePin, 200);

    delay(3000);
    if (!robotActif) break;

    digitalWrite(MD_controlPin1, LOW);
    digitalWrite(MD_controlPin2, HIGH);
    digitalWrite(MG_controlPin1, HIGH);
    digitalWrite(MG_controlPin2, LOW);
    analogWrite(MD_enablePin, 200);
    analogWrite(MG_enablePin, 200);

    delay(100);
    
    a = a + 1;
  }
}