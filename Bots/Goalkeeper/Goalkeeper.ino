#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

// Right Motor
int RPWM_RightMotor = 5; // Right motor PWM for clockwise (forward) rotation
int LPWM_RightMotor = 6; // Right motor PWM for counterclockwise (reverse) rotation

// Left Motor
int RPWM_LeftMotor = 9;  // Left motor PWM for clockwise (forward) rotation
int LPWM_LeftMotor = 10; // Left motor PWM for counterclockwise (reverse) rotation

int motorSpeed = 60; // Set initial speed to 60 out of 255

void setup()
{
  // Define motor control pins as outputs
  pinMode(RPWM_RightMotor, OUTPUT);
  pinMode(LPWM_RightMotor, OUTPUT);
  pinMode(RPWM_LeftMotor, OUTPUT);
  pinMode(LPWM_LeftMotor, OUTPUT);

  // Initialize Dabble with Bluetooth communication at 9600 baud rate
  Dabble.begin(9600, 2, 3);
}

void loop()
{
  Dabble.processInput(); // Process input from Dabble Gamepad module

  // Initialize motor speeds to zero for each loop cycle
  int rightMotorSpeed = 0;
  int leftMotorSpeed = 0;

  // Process gamepad inputs and set motor speeds accordingly
  if (GamePad.isUpPressed())
  {
    rightMotorSpeed = motorSpeed;
    leftMotorSpeed = motorSpeed;
  }
  
  if (GamePad.isDownPressed())
  {
    rightMotorSpeed = -motorSpeed;
    leftMotorSpeed = -motorSpeed;
  }

  if (GamePad.isLeftPressed())
  {
    rightMotorSpeed = motorSpeed;
    leftMotorSpeed = 0;
  }
  
  if (GamePad.isRightPressed())
  {
    rightMotorSpeed = 0;
    leftMotorSpeed = motorSpeed;
  }

  // Rotate motors based on calculated speed values
  rotateMotor(rightMotorSpeed, leftMotorSpeed);
}

void rotateMotor(int rightMotorSpeed, int leftMotorSpeed)
{
  // Right Motor Control
  if (rightMotorSpeed > 0) // Forward
  {
    analogWrite(RPWM_RightMotor, rightMotorSpeed);
    analogWrite(LPWM_RightMotor, 0);
  }
  else if (rightMotorSpeed < 0) // Reverse
  {
    analogWrite(RPWM_RightMotor, 0);
    analogWrite(LPWM_RightMotor, abs(rightMotorSpeed));
  }
  else // Stop
  {
    analogWrite(RPWM_RightMotor, 0);
    analogWrite(LPWM_RightMotor, 0);
  }

  // Left Motor Control
  if (leftMotorSpeed > 0) // Forward
  {
    analogWrite(RPWM_LeftMotor, leftMotorSpeed);
    analogWrite(LPWM_LeftMotor, 0);
  }
  else if (leftMotorSpeed < 0) // Reverse
  {
    analogWrite(RPWM_LeftMotor, 0);
    analogWrite(LPWM_LeftMotor, abs(leftMotorSpeed));
  }
  else // Stop
  {
    analogWrite(RPWM_LeftMotor, 0);
    analogWrite(LPWM_LeftMotor, 0);
  }
}
