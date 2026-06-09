/// Initialisation des constantes pour le moteur droit
const int MD_controlPin1 = 2;
const int MD_controlPin2 = 3;
const int MD_enablePin = 4;

/// Initialisation des constantes pour le moteur gauche
const int MG_controlPin1 = 8;
const int MG_controlPin2 = 9;
const int MG_enablePin = 10;

/// Initialisation de la broche du bouton
const int buttonPin = A3;

/// Variables d'état pour le système On/Off
int buttonState = 0;
int previousButtonState = 0;
int robotEnabled = 0;

int a = 0;

void setup() {
  // Configuration des broches des moteurs en sortie
  pinMode(MD_controlPin1, OUTPUT);
  pinMode(MD_controlPin2, OUTPUT);
  pinMode(MD_enablePin, OUTPUT);
  pinMode(MG_controlPin1, OUTPUT);
  pinMode(MG_controlPin2, OUTPUT);
  pinMode(MG_enablePin, OUTPUT);
  
  // Configuration du bouton en entrée (nécessite une résistance de pull-down matérielle)
  pinMode(buttonPin, INPUT); 
}

void loop() {
  // Lecture de l'état du bouton et anti-rebond temporel
  buttonState = digitalRead(buttonPin);
  delay(1); 
  
  // Détection du front montant (changement d'état de LOW à HIGH)
  if (buttonState != previousButtonState) {
    if (buttonState == HIGH) {
      robotEnabled = !robotEnabled; // Inversion de l'état (0 -> 1 ou 1 -> 0)
      
      // Réinitialisation de l'itérateur si le robot est activé
      if (robotEnabled == 1) {
        a = 0; 
      }
    }
  }
  
  // Exécution conditionnelle en fonction de l'état du robot
  if (robotEnabled == 1) {
    digitalWrite(MD_controlPin1, HIGH);
    digitalWrite(MD_controlPin2, LOW);
    digitalWrite(MG_controlPin1, HIGH);
    digitalWrite(MG_controlPin2, LOW);
    analogWrite(MD_enablePin, 250);
    analogWrite(MG_enablePin, 250);

    delay(1000);

    digitalWrite(MD_controlPin1, HIGH);
    digitalWrite(MD_controlPin2, LOW);
    digitalWrite(MG_controlPin1, LOW);
    digitalWrite(MG_controlPin2, HIGH);
    analogWrite(MD_enablePin, 250);
    analogWrite(MG_enablePin, 250);

    delay(350);

    while (a <= 4) {
      digitalWrite(MD_controlPin1, HIGH);
      digitalWrite(MD_controlPin2, LOW);
      digitalWrite(MG_controlPin1, HIGH);
      digitalWrite(MG_controlPin2, LOW);
      analogWrite(MD_enablePin, 250);
      analogWrite(MG_enablePin, 250);

      delay(3000);

      digitalWrite(MD_controlPin1, LOW);
      digitalWrite(MD_controlPin2, HIGH);
      digitalWrite(MG_controlPin1, HIGH);
      digitalWrite(MG_controlPin2, LOW);
      analogWrite(MD_enablePin, 200);
      analogWrite(MG_enablePin, 200);

      delay(3000);

      digitalWrite(MD_controlPin1, HIGH);
      digitalWrite(MD_controlPin2, LOW);
      digitalWrite(MG_controlPin1, LOW);
      digitalWrite(MG_controlPin2, HIGH);
      analogWrite(MD_enablePin, 200);
      analogWrite(MG_enablePin, 200);

      delay(100);

      digitalWrite(MD_controlPin1, HIGH);
      digitalWrite(MD_controlPin2, LOW);
      digitalWrite(MG_controlPin1, HIGH);
      digitalWrite(MG_controlPin2, LOW);
      analogWrite(MD_enablePin, 250);
      analogWrite(MG_enablePin, 250);

      delay(3000);

      digitalWrite(MD_controlPin1, HIGH);
      digitalWrite(MD_controlPin2, LOW);
      digitalWrite(MG_controlPin1, LOW);
      digitalWrite(MG_controlPin2, HIGH);
      analogWrite(MD_enablePin, 200);
      analogWrite(MG_enablePin, 200);

      delay(3000);

      digitalWrite(MD_controlPin1, LOW);
      digitalWrite(MD_controlPin2, HIGH);
      digitalWrite(MG_controlPin1, HIGH);
      digitalWrite(MG_controlPin2, LOW);
      analogWrite(MD_enablePin, 200);
      analogWrite(MG_enablePin, 200);

      delay(100);
      a = a + 1;
    }
  } else {
    // Phase de désactivation : coupure de l'alimentation PWM et mise à zéro des contrôles
    analogWrite(MD_enablePin, 0);
    analogWrite(MG_enablePin, 0);
    digitalWrite(MD_controlPin1, LOW);
    digitalWrite(MD_controlPin2, LOW);
    digitalWrite(MG_controlPin1, LOW);
    digitalWrite(MG_controlPin2, LOW);
  }
  
  // Sauvegarde de l'état actuel pour la prochaine itération
  previousButtonState = buttonState;
}