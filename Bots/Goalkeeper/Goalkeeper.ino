#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

// Define Pins for BTS7960 Motor Driver
int frontRightEnablePin = 7;  // R_EN for front right motor
int frontLeftEnablePin = 8;   // L_EN for front left motor
int frontRightPWMPin = 5;     // RPWM for front right motor
int frontLeftPWMPin = 6;      // LPWM for front left motor

int backRightEnablePin = 9;   // R_EN for back right motor
int backLeftEnablePin = 10;   // L_EN for back left motor
int backRightPWMPin = 3;      // RPWM for back right motor
int backLeftPWMPin = 11;      // LPWM for back left motor

const int speedLimit = 60;  // PWM Speed Limit (0-255)

// Function Prototypes
void rotateMotors(int frontRightSpeed, int frontLeftSpeed, int backRightSpeed, int backLeftSpeed);

void setup() {
  // Motor Control Pins Setup
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

  // Bluetooth Setup
  Dabble.begin(9600, 2, 3);  // Baud rate and pins for serial communication
}

void loop() {
  int frontRightSpeed = 0;
  int frontLeftSpeed = 0;
  int backRightSpeed = 0;
  int backLeftSpeed = 0;

  // Process Bluetooth Input
  Dabble.processInput();

  // Forward Motion
  if (GamePad.isUpPressed()) {
    frontRightSpeed = speedLimit;
    frontLeftSpeed = speedLimit;
    backRightSpeed = speedLimit;
    backLeftSpeed = speedLimit;
  }
  
  // Backward Motion
  if (GamePad.isDownPressed()) {
    frontRightSpeed = -speedLimit;
    frontLeftSpeed = -speedLimit;
    backRightSpeed = -speedLimit;
    backLeftSpeed = -speedLimit;
  }

  // Left Turn
  if (GamePad.isLeftPressed()) {
    frontRightSpeed = speedLimit;
    frontLeftSpeed = 0;
    backRightSpeed = speedLimit;
    backLeftSpeed = 0;
  }

  // Right Turn
  if (GamePad.isRightPressed()) {
    frontRightSpeed = 0;
    frontLeftSpeed = speedLimit;
    backRightSpeed = 0;
    backLeftSpeed = speedLimit;
  }

  // Update Motor Directions and Speeds
  rotateMotors(frontRightSpeed, frontLeftSpeed, backRightSpeed, backLeftSpeed);
}

void rotateMotors(int frontRightSpeed, int frontLeftSpeed, int backRightSpeed, int backLeftSpeed) {
  // Front Right Motor Control
  analogWrite(frontRightPWMPin, abs(frontRightSpeed));
  digitalWrite(frontRightEnablePin, frontRightSpeed > 0);

  // Front Left Motor Control
  analogWrite(frontLeftPWMPin, abs(frontLeftSpeed));
  digitalWrite(frontLeftEnablePin, frontLeftSpeed > 0);

  // Back Right Motor Control
  analogWrite(backRightPWMPin, abs(backRightSpeed));
  digitalWrite(backRightEnablePin, backRightSpeed > 0);

  // Back Left Motor Control
  analogWrite(backLeftPWMPin, abs(backLeftSpeed));
  digitalWrite(backLeftEnablePin, backLeftSpeed > 0);
}
