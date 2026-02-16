#include <ESP8266WiFi.h>
#include <WiFiUDP.h>

#define READ_PIN A0        // external ADC only (or remove if unused)
#define BUTTON_PIN 0       

const char *ssid = "Tele2_48b021"; // The SSID (name) of the Wi-Fi network you want to connect to
const char *password = "hdmkvtnh";  // The password of the Wi-Fi network

WiFiUDP UDP;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  Serial.begin(115200);
  delay(1000);
  //Serial.println("Starting.....");
  //Serial.println();
  //Serial.print("Setting soft-AP ... ");

  // Start Access Point
  WiFi.mode(WIFI_AP);
  WiFi.persistent(false);
  Serial.print("AP IP: ");
  WiFi.softAP(ssid, password);
  Serial.print("Soft-AP IP address = "); //192.168.4.1
  Serial.println(WiFi.softAPIP());

  UDP.begin(7171);
  Serial.println("UDP server started");
}

void loop() {

  // ---- Button test ----
  if(digitalRead(BUTTON_PIN) == LOW){
    Serial.println("Button pressed");
    delay(300);
  }

  // ---- Analog test ----
#ifdef A0
  int val = analogRead(A0);
  Serial.print("Analog: ");
  Serial.println(val);
#endif

  delay(500);
}
