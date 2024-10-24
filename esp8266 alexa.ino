#include <ESP8266WiFi.h>
#define RELAY_PIN_1 D1
#define RELAY_PIN_2 D2
#define RELAY_PIN_3 D5
#define RELAY_PIN_4 D6
#define RELAY_PIN_5 D7

#include "fauxmoESP.h"

#define SERIAL_BAUDRATE 115200

#define WIFI_SSID "NOME DO WIFI"
#define WIFI_PASS "SENHA DO WIFI"

#define LAMP_1 "LED 1"
#define LAMP_2 "LED 2"
#define LAMP_3 "LED 3"
#define LAMP_4 "LED 4"
#define LAMP_5 "LED 5"

fauxmoESP fauxmo;

void wifiSetup() {
  WiFi.mode(WIFI_STA);
  Serial.printf("[WIFI] Conectado ao %s ", WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }
  Serial.println();
  Serial.printf("[WIFI] STATION Mode, SSID: %s, IP address: %s\n", WiFi.SSID().c_str(), WiFi.localIP().toString().c_str());
}

void setup() {
  Serial.begin(SERIAL_BAUDRATE);
  Serial.println();

  wifiSetup();

  pinMode(RELAY_PIN_1, OUTPUT);
  digitalWrite(RELAY_PIN_1, LOW);
  pinMode(RELAY_PIN_2, OUTPUT);
  digitalWrite(RELAY_PIN_2, LOW);
  pinMode(RELAY_PIN_3, OUTPUT);
  digitalWrite(RELAY_PIN_3, LOW);
  pinMode(RELAY_PIN_4, OUTPUT);
  digitalWrite(RELAY_PIN_4, LOW);
  pinMode(RELAY_PIN_5, OUTPUT);
  digitalWrite(RELAY_PIN_5, LOW);

  fauxmo.createServer(true);
  fauxmo.setPort(80);
  fauxmo.enable(true);

  fauxmo.addDevice(LAMP_1);
  fauxmo.addDevice(LAMP_2);
  fauxmo.addDevice(LAMP_3);
  fauxmo.addDevice(LAMP_4);
  fauxmo.addDevice(LAMP_5);

  fauxmo.onSetState([](unsigned char device_id, const char * device_name, bool state, unsigned char value) {
    Serial.printf("[MAIN] Device #%d (%s) state: %s value: %d\n", device_id, device_name, state ? "ON" : "OFF", value);
    
    if (strcmp(device_name, LAMP_1) == 0) {
      digitalWrite(RELAY_PIN_1, state ? HIGH : LOW);
    }
    if (strcmp(device_name, LAMP_2) == 0) {
      digitalWrite(RELAY_PIN_2, state ? HIGH : LOW);
    }
    if (strcmp(device_name, LAMP_3) == 0) {
      digitalWrite(RELAY_PIN_3, state ? HIGH : LOW);
    }
    if (strcmp(device_name, LAMP_4) == 0) {
      digitalWrite(RELAY_PIN_4, state ? HIGH : LOW);
    }
    if (strcmp(device_name, LAMP_5) == 0) {
      digitalWrite(RELAY_PIN_5, state ? HIGH : LOW);
    }
  });
}

void loop() {
  fauxmo.handle();

  static unsigned long last = millis();
  if (millis() - last > 5000) {
    last = millis();
    Serial.printf("[MAIN] Free heap: %d bytes\n", ESP.getFreeHeap());
  }
}
