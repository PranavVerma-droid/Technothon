#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>
#include <Arduino.h>


// Motor control pins
int R1PWM = 19;  // Right Motor Forward
int R2PWM = 21;  // Right Motor Backward
int L1PWM = 23;  // Left Motor Forward
int L2PWM = 22;  // Left Motor Backward

int Speed = 100;  // Initial speed of the motors

// PWM Channels for ESP32
int channelR1 = 0;
int channelR2 = 1;
int channelL1 = 2;
int channelL2 = 3;

// PWM frequency and resolution
int pwmFreq = 1000;
int pwmResolution = 8;

void setup() {
  Serial.begin(115200);

  // Initialize Dabble with a Bluetooth device name
  Dabble.begin("AttackerBot");

  // Setup PWM channels
  ledcSetup(channelR1, pwmFreq, pwmResolution);
  ledcSetup(channelR2, pwmFreq, pwmResolution);
  ledcSetup(channelL1, pwmFreq, pwmResolution);
  ledcSetup(channelL2, pwmFreq, pwmResolution);

  // Attach PWM channels to motor pins
  ledcAttachPin(R1PWM, channelR1);
  ledcAttachPin(R2PWM, channelR2);
  ledcAttachPin(L1PWM, channelL1);
  ledcAttachPin(L2PWM, channelL2);
}

void loop() {
  // Process input from Dabble
  Dabble.processInput();

  if (GamePad.isUpPressed()) {
    // Move forward
    ledcWrite(channelR1, Speed);
    ledcWrite(channelR2, 0);
    ledcWrite(channelL1, Speed);
    ledcWrite(channelL2, 0);
  }
  else if (GamePad.isDownPressed()) {
    // Move backward
    ledcWrite(channelR1, 0);
    ledcWrite(channelR2, Speed);
    ledcWrite(channelL1, 0);
    ledcWrite(channelL2, Speed);
  }
  else if (GamePad.isLeftPressed()) {
    // Turn left
    ledcWrite(channelR1, 0);
    ledcWrite(channelR2, Speed);
    ledcWrite(channelL1, Speed);
    ledcWrite(channelL2, 0);
  }
  else if (GamePad.isRightPressed()) {
    // Turn right
    ledcWrite(channelR1, Speed);
    ledcWrite(channelR2, 0);
    ledcWrite(channelL1, 0);
    ledcWrite(channelL2, Speed);
  }
  else {
    // Stop motors
    ledcWrite(channelR1, 0);
    ledcWrite(channelR2, 0);
    ledcWrite(channelL1, 0);
    ledcWrite(channelL2, 0);
  }
}
