#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Servo.h>  
#include "Index.h";

#define ServoPin D1
#define LedPin D5

const char* ssid = "Light"; 
const char* password = "Set-Up-Strong-Password-Here"; 

Servo servo1;  
ESP8266WebServer server(80);

void handleRequests() { 
  server.send(200, "text/html", Index); 
}

void blinkLed() {
  digitalWrite(LedPin, HIGH);
  delay(100);
  digitalWrite(LedPin, LOW);
  delay(100);
}

void handleLight() {
  String state = server.arg("state");
  if (state == "on") {
    blinkLed();
    servo1.write(90);
    delay(500);
    servo1.write(120);
    delay(500);
    servo1.write(90);
  } else if (state == "off") {
    blinkLed();
    servo1.write(90);
    delay(500);
    servo1.write(60);
    delay(500);
    servo1.write(90);
  }
  server.send(200, "text/plain", "");
}

void setup() {
  servo1.attach(ServoPin); 
  pinMode(LedPin, OUTPUT);
  
  WiFi.softAP(ssid, password);

  server.on("/", handleRequests); 
  server.on("/setLight", handleLight); 

  server.begin();
}

void loop() {
  server.handleClient();
}
