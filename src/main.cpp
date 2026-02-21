#include <Arduino.h>
/**
 * @file main.ino
 * @brief Embedded Light Intensity Monitoring using LDR
 * @author UTTAM_SINGH
 * @date 2026-02-21
 *
 * @details
 * Reads analog brightness data from LDR sensor
 * and displays structured output via Serial Monitor.
 */

const int ldrPin = A0;
int ldrValue = 0;
int threshold = 2000;

void setup() {
    Serial.begin(9600);
    while (!Serial);
    analogReadResolution(12);
    Serial.println("LDR Light Intensity Monitoring System (UNO R4 WiFi)");
}
void loop() {
    ldrValue = analogRead(ldrPin);

    Serial.print("LDR Raw Value: ");
    Serial.println(ldrValue);

    if (ldrValue > threshold) {
        Serial.println("Bright Environment");
    } else {
        Serial.println("Dark Environment");
    }
    delay(1000);
}
