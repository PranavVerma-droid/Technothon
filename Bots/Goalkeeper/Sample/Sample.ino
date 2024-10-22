/*FOR TWO MOTORS*/

/* Motor 1 (First BTS7960 Module) */
int R1PWM = 6;  // RPWM pin for Motor 1
int L1PWM = 5;  // LPWM pin for Motor 1

/* Motor 2 (Second BTS7960 Module) */
int R2PWM = 10; // RPWM pin for Motor 2
int L2PWM = 9;  // LPWM pin for Motor 2

const int motorSpeed = 100;  // PWM speed (0-255)

void setup() {
  // Set Motor 1 control pins as outputs
  pinMode(R1PWM, OUTPUT);
  pinMode(L1PWM, OUTPUT);

  // Set Motor 2 control pins as outputs
  pinMode(R2PWM, OUTPUT);
  pinMode(L2PWM, OUTPUT);

  // Initialize Motor 1 to move forward
  analogWrite(R1PWM, motorSpeed);  // Set forward speed for Motor 1
  analogWrite(L1PWM, 0);           // Disable reverse for Motor 1

  // Initialize Motor 2 to move forward
  analogWrite(R2PWM, motorSpeed);  // Set forward speed for Motor 2
  analogWrite(L2PWM, 0);           // Disable reverse for Motor 2
}

void loop() {
  // Both motors will continue to run forward at PWM 60 indefinitely
}
