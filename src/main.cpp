#include <Arduino.h>

void setup() {
    Serial.begin(9600);
}

void loop() {
    while (Serial.available() > 0) {
        uint8_t b = Serial.read();
        uint8_t antwort = b + 1;
        Serial.write(antwort);
    }
}