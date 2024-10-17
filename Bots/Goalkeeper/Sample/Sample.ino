// Define Pins for BTS7960 Motor Driver
int frontRightEnablePin = 7;  // R_EN for front right motor
int frontLeftEnablePin = 8;   // L_EN for front left motor
int frontRightPWMPin = 5;     // RPWM for front right motor
int frontLeftPWMPin = 6;      // LPWM for front left motor

int backRightEnablePin = 9;   // R_EN for back right motor
int backLeftEnablePin = 10;   // L_EN for back left motor
int backRightPWMPin = 3;      // RPWM for back right motor
int backLeftPWMPin = 11;      // LPWM for back left motor

const int pwmSpeed = 60;  // Set speed to 60 (out of 255)

void setup() {
  // Set Motor Control Pins as Output
  pinMode(frontRightEnablePin, OUTPUT);
  pinMode(frontLeftEnablePin, OUTPUT);
  pinMode(frontRightPWMPin, OUTPUT);
  pinMode(frontLeftPWMPin, OUTPUT);
  
  pinMode(backRightEnablePin, OUTPUT);
  pinMode(backLeftEnablePin, OUTPUT);
  pinMode(backRightPWMPin, OUTPUT);
  pinMode(backLeftPWMPin, OUTPUT);

  // Enable all motors
  digitalWrite(frontRightEnablePin, HIGH);
  digitalWrite(frontLeftEnablePin, HIGH);
  digitalWrite(backRightEnablePin, HIGH);
  digitalWrite(backLeftEnablePin, HIGH);

  // Set all motors to run at a PWM speed of 60
  analogWrite(frontRightPWMPin, pwmSpeed);
  analogWrite(frontLeftPWMPin, pwmSpeed);
  analogWrite(backRightPWMPin, pwmSpeed);
  analogWrite(backLeftPWMPin, pwmSpeed);
}

void loop() {
  // Motors will keep running at PWM 60
}