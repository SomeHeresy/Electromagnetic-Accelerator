// This is the code for a 2 Staged Time Sequenced Coil-gun.
// Where LP are the buttons that controls when to open and close the circuit for each stage.
#define LP1 2 // Opto1 upper
#define LP2 8 // Opto2 upper
#define LP3 7 // Opto4 lower
#define LP4 4 // Opto3 lower
#define BUTTON_PIN 12  // The general button that fires the coil-gun

void setup() {
  pinMode(LP1, OUTPUT);
  pinMode(LP2, OUTPUT);
  pinMode(LP3, OUTPUT);
  pinMode(LP4, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == HIGH) {
    digitalWrite(LP1, HIGH);
    digitalWrite(LP4, HIGH);
    delay(300);     // Time to wait for the projectile to enter stage2
    digitalWrite(LP1, LOW);
    digitalWrite(LP4, LOW);
    //digitalWrite(LP2, HIGH);
    //digitalWrite(LP3, HIGH);
    //delayMicroseconds(40000);
    //digitalWrite(LP2, LOW);
    //digitalWrite(LP3, LOW);
    delay(1000);  // Cut off stage connection
  }
  else {
    digitalWrite(LP1, LOW);
    digitalWrite(LP2, LOW);
    digitalWrite(LP3, LOW);
    digitalWrite(LP4, LOW);
  }
}