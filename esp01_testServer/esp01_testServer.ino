#include <ESP8266WiFi.h>

const char *ssid = "Tele2_48b021"; // The SSID (name) of the Wi-Fi network you want to connect to
const char *password = "hdmkvtnh";  // The password of the Wi-Fi network

#define RELAY 0 // relay connected to  GPIO0
WiFiServer server(80);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200); // must be same baudrate with the Serial Monitor
 
  pinMode(RELAY,OUTPUT);
  digitalWrite(RELAY, LOW);
 

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("https://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

}

void loop() {
  // put your main code here, to run repeatedly:

}
