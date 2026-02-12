#define FASTLED_INTERRUPT_RETRY_COUNT 0 
#define FASTLED_ALLOW_INTERRUPTS 0
#include <FastLED.h>
#include <ESP8266WiFi.h>
#include <WiFiUDP.h>
#include "reactive_common.h"

#define LED_PIN 2
#define NUM_LEDS 144

#define MIC_LOW 0
#define MIC_HIGH 644

#define SAMPLE_SIZE 20
#define LONG_TERM_SAMPLES 250
#define BUFFER_DEVIATION 400
#define BUFFER_SIZE 3

#define LAMP_ID 1
WiFiUDP UDP;

const char *ssid = "Tele2_48b021"; // The SSID (name) of the Wi-Fi network you want to connect to
const char *password = "hdmkvtnh";  // The password of the Wi-Fi network


void setup() {
  pinMode(LED_PIN, OUTPUT);

}

void loop() {
  digitalWrite(LED_PIN, LOW);   // ON (ESP is inverted)
  delay(500);

  digitalWrite(LED_PIN, HIGH);  // OFF
  delay(500);

}
