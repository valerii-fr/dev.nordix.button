#include <Arduino.h>
#include "WiFiManager.h" // https://github.com/tzapu/WiFiManager
#include "SButton.h"

#define BUTTON_PIN 0
 
int led = 15;        // the PWM pin the LED is attached to
int brightness = 0;  // how bright the LED is
int fadeAmount = 5;  // how many points to fade the LED by

Sbutton btn (BUTTON_PIN, 0);

void setup() {
    WiFi.mode(WIFI_STA);
    Serial.begin(115200);
    
    pinMode(led, OUTPUT);

    WiFiManager wm;
    // wm.resetSettings();
    bool res;Serial.println("initializing AP")
    res = wm.autoConnect("Button Connect"); // anonymous ap
    Serial.println("Waiting for setup")
 
    if(!res) {
        Serial.println("Failed to connect, restarting");
    } 
    else {
        Serial.println("connected:)");
    }
 
}

// the loop routine runs over and over again forever:
void loop() {
  btn.tick();
  analogWrite(led, brightness);
  brightness = brightness + fadeAmount;
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  delay(30); 
}