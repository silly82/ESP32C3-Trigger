#include <BleKeyboard.h>
#include <Arduino.h>

// BLE-Tastatur Instanz
BleKeyboard bleKeyboard("ESP32-C3 Keyboard", "RedButton", 100); // Name, Hersteller, maximale Verbindungen

const int triggerPin = 10; // GPIO 10 als Trigger-Pin (geeignet für ESP32-C3)

void setup() {
  pinMode(triggerPin, INPUT_PULLUP); // Konfiguriert den Pin mit internem Pull-Up
  Serial.begin(115200);
  
  Serial.println("Starte BLE-Tastatur...");
  bleKeyboard.begin(); // BLE starten
}

void loop() {
  if (bleKeyboard.isConnected()) { // Prüft, ob BLE verbunden ist
    if (digitalRead(triggerPin) == LOW) { // Taster gedrückt
      Serial.println("Trigger aktiviert! Lautstärke erhöhen...");
      bleKeyboard.write(KEY_MEDIA_VOLUME_UP); // Lautstärketaste senden
      delay(500); // Entprellen
    }
  } else {
    Serial.println("Warte auf BLE-Verbindung...");
  }
  delay(10); // CPU schonen
}
