#ifndef UNIT_TEST
#include <Arduino.h>
#endif
#include <IRremoteESP8266.h>
#include <IRsend.h>

const uint16_t kIrLed = 4;  // ESP8266 GPIO pin to use. Recommended: 4 (D2).

IRsend irsend(kIrLed);  // Set the GPIO to be used to sending the message.

//开机
uint16_t kaiJi[139] = {8968, 4526,  628, 572,  626, 574,  626, 574,  626, 1694,  624, 576,  624, 574,  624, 1696,  624, 550,  648, 574,  626, 574,  624, 576,  624, 548,  648, 576,  624, 576,  624, 572,  624, 576,  624, 574,  604, 594,  626, 572,  626, 548,  652, 550,  626, 1716,  624, 574,  626, 574,  626, 572,  626, 574,  624, 600,  600, 600,  598, 1694,  624, 574,  626, 1670,  650, 574,  622, 576,  624, 1670,  650, 574,  622, 19990,  628, 1716,  604, 596,  604, 594,  604, 594,  604, 572,  626, 598,  602, 596,  602, 596,  602, 596,  604, 596,  602, 572,  628, 596,  604, 594,  604, 596,  602, 596,  604, 598,  602, 596,  602, 596,  604, 570,  628, 570,  628, 596,  602, 596,  602, 594,  604, 594,  604, 572,  628, 570,  628, 572,  628, 596,  602, 570,  630, 1690,  628, 596,  604, 570,  628};  // GREE

//关机
uint16_t guanJi[139] = {8970, 4498,  652, 548,  652, 572,  626, 574,  626, 576,  624, 572,  626, 574,  624, 1670,  650, 576,  622, 574,  626, 548,  652, 576,  624, 574,  624, 572,  624, 576,  624, 574,  626, 572,  626, 550,  650, 574,  626, 548,  648, 576,  624, 574,  624, 1672,  650, 574,  624, 600,  598, 574,  626, 550,  650, 576,  624, 574,  626, 1694,  626, 572,  624, 1668,  652, 574,  624, 548,  652, 1668,  650, 576,  624, 19990,  628, 1690,  628, 574,  626, 598,  602, 572,  628, 596,  602, 598,  602, 596,  604, 596,  604, 598,  600, 598,  602, 596,  600, 602,  600, 596,  604, 596,  600, 598,  604, 594,  604, 596,  604, 598,  598, 596,  604, 570,  628, 598,  602, 596,  604, 596,  602, 596,  602, 598,  600, 596,  602, 572,  630, 594,  602, 572,  628, 1690,  628, 596,  602, 1690,  630};  // GREE


void setup() {
  irsend.begin();
  Serial.begin(115200, SERIAL_8N1, SERIAL_TX_ONLY);
}

void loop() {
    Serial.println("开机");
    irsend.sendRaw(kaiJi, 139, 38);  // Send a raw data capture at 38kHz.

    delay(3000);
    Serial.println("关机");
    irsend.sendRaw(guanJi, 139, 38);  // Send a raw data capture at 38kHz.
    delay(3000);
}
