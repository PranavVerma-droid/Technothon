/* 
FL --- FR
|      |
|      |
BL --- BR

Parts List:
- Lipo 12V Battery
- Double BTS7960 Driver Module x 2
- Arduino Uno
- 775 12V Motors x 4
- HM-10 BLE Module
- Buck Converter (PSU)

Motor Wiring (Parallel):

Module 1 (LEFT SIDE):
- frontLeft and backLeft motors in parallel
- These motors are on the same vertical line (left side)

Module 2 (RIGHT SIDE):
- frontRight and backRight motors in parallel
- These motors are on the same vertical line (right side)

Pin Connections:

BTS7960 Module 1 (LEFT SIDE):
- VCC -> Arduino 3.3V
- L_EN, R_EN -> Arduino 3.3V 
- GND -> Arduino GND
- RPWM -> Arduino Digital Pin 6 (R1PWM)
- LPWM -> Arduino Digital Pin 5 (L1PWM)

BTS7960 Module 2 (RIGHT SIDE):
- VCC -> Arduino 3.3V
- L_EN, R_EN -> Arduino 3.3V
- GND -> Arduino GND
- RPWM -> Arduino Digital Pin 11 (R2PWM)
- LPWM -> Arduino Digital Pin 10 (L2PWM)

Motor Power:
- Both modules M+ and M- terminals connect to respective motors in parallel
- Both modules power terminals (B+, B-) connect to battery (11.1V - 30V)

Bluetooth Module HM-10:
- VCC -> Arduino 5V
- GND -> Arduino GN
- TX -> Arduino Pin 2
- RX -> Arduino Pin 3

Notes:
- R1PWM/R2PWM control forward motion
- L1PWM/L2PWM control backward motion
- When one side moves forward and other backward = turning
- Both modules share the same power source (battery)
- Enable pins are tied to 3.3V for constant enable
*/

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

int Speed = 45;

int R1PWM = 6;
int L1PWM = 5;
int R2PWM = 11;   
int L2PWM = 10;   

void setup() {
  Serial.begin(9600);
  Dabble.begin(9600, 2, 3); 

  pinMode(R1PWM, OUTPUT);
  pinMode(L1PWM, OUTPUT);
  pinMode(R2PWM, OUTPUT);
  pinMode(L2PWM, OUTPUT);

    analogWrite(R1PWM, 0);
    analogWrite(L1PWM, 0);
    analogWrite(R2PWM, 0);
    analogWrite(L2PWM, 0);
}

void loop() {
  Dabble.processInput();

  if (GamePad.isTrianglePressed()) {
    Speed = 255;
  } 
  if (GamePad.isSquarePressed()){
    Speed = 200;
  } 
  if (GamePad.isCrossPressed()) {
    Speed = 90;
  } 
  if (GamePad.isCirclePressed()) {
    Speed = 20;
  }

  if (GamePad.isStartPressed()) {
    Speed = 45;
  }


  if (GamePad.isUpPressed()) {
    analogWrite(R1PWM, Speed);
    analogWrite(L1PWM, 0);
    analogWrite(R2PWM, Speed);
    analogWrite(L2PWM, 0);
    Serial.println("Forward");
  }
  else if (GamePad.isDownPressed()) {
    analogWrite(R1PWM, 0);
    analogWrite(L1PWM, Speed);
    analogWrite(R2PWM, 0);
    analogWrite(L2PWM, Speed);
    Serial.println("Backward");
  }
  else if (GamePad.isLeftPressed()) {
    analogWrite(R1PWM, 0);
    analogWrite(L1PWM, Speed);
    analogWrite(R2PWM, Speed);
    analogWrite(L2PWM, 0);
    Serial.println("Left");
  }
  else if (GamePad.isRightPressed()) {
    analogWrite(R1PWM, Speed);
    analogWrite(L1PWM, 0);
    analogWrite(R2PWM, 0);
    analogWrite(L2PWM, Speed);
    Serial.println("Right");
  }
  else {
    analogWrite(R1PWM, 0);
    analogWrite(L1PWM, 0);
    analogWrite(R2PWM, 0);
    analogWrite(L2PWM, 0);
  }
}