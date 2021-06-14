#include <Arduino.h>

// LED_BUILTIN => Pin 2;
int controlLED = 4; // ADC2
int reedSwitch = 16; // UART2 RX
int doorState = 0;

void setup() {
  Serial.begin(115200);
  pinMode (LED_BUILTIN, OUTPUT);

  pinMode (controlLED, OUTPUT);
  pinMode (reedSwitch, INPUT);
  digitalWrite(controlLED, LOW);
  digitalWrite(LED_BUILTIN, LOW);
}
void loop() {
  
  digitalWrite(controlLED, LOW);
  doorState = digitalRead(reedSwitch);
  digitalWrite(LED_BUILTIN, (doorState==1 ? HIGH : LOW));
  Serial.print("Status:");
  Serial.println(doorState);
  delay(2000);

  
  digitalWrite(controlLED, HIGH);
  doorState = digitalRead(reedSwitch);
  digitalWrite(LED_BUILTIN, (doorState==1 ? HIGH : LOW));
  Serial.print("Status:");
  Serial.println(doorState);
  delay(2000);
}