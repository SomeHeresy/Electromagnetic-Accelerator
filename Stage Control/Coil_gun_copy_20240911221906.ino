// This is the code for a 2 Staged Time Sequenced Coil-gun.
// Where LP are the buttons that controls when to open and close the circuit for each stage.
#define LP1 8 // Stage1 button
#define BUTTON_PIN 7  // The general button that fires the coil-gun

void setup() {
  pinMode(LP1, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == HIGH) {
    digitalWrite(LP1, HIGH);
    delay(500);     // Stage1 open time
    digitalWrite(LP1, LOW);
    delay(500);     // Time to wait for the projectile to enter stage2
  }
  else {
    digitalWrite(LP1, LOW);
  }
}