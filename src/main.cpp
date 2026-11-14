#include <Arduino.h>

constexpr uint8_t START = 0x7E;
constexpr uint8_t MAX_PAYLOAD = 16;

enum State { WAIT_START, WAIT_LEN, WAIT_PAYLOAD };

State state = WAIT_START;

uint8_t payload[MAX_PAYLOAD];
uint8_t len = 0;
uint8_t idx = 0;

void handleBytes(uint8_t b) {
    switch (state) {
        case WAIT_START:
            if (b == START) {
                state = WAIT_LEN;
            }
            break;
        case WAIT_LEN:
            break;
        case WAIT_PAYLOAD:
            break;
    }
}

void setup() {
    Serial.begin(9600);
}

void loop() {
    while (Serial.available() > 0) {
        handleBytes(Serial.read());
    }
}