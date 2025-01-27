#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Servo.h>  
#include <Wire.h>
#include <BH1750.h>
#include "PageIndex.h"; 
#define ServoPort D1  

const char* ssid = "Light"; 
const char* password = "nopassword"; 

Servo myservo;  
ESP8266WebServer server(80);  
BH1750 lightMeter;
int ledPin = D5;

void handleRoot() {
  String s = MAIN_page; 
  server.send(200, "text/html", s); 
}

void handleLight() {
  String state = server.arg("state");
  if (state == "on") {
    myservo.write(90);
    delay(500);
    myservo.write(60);
    delay(500);
    myservo.write(90);
  } else if (state == "off") {
    myservo.write(90);
    delay(500);
    myservo.write(120);
    delay(500);
    myservo.write(90);
  }
  server.send(200, "text/plain", "");
}

void handleLightIntensity() {
  float lux = lightMeter.readLightLevel();
  server.send(200, "text/plain", String(lux));
}

void setup() {
  //Serial.begin(115200);
  //delay(500);
  myservo.attach(ServoPort); 
  
  Wire.begin(D3, D2); 
  lightMeter.begin();
  pinMode(ledPin, OUTPUT);
  
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  //Serial.print("AP IP address: ");
  //Serial.println(myIP);

  server.on("/", handleRoot); 
  server.on("/setLight", handleLight);
  server.on("/getLightIntensity", handleLightIntensity);

  server.begin();
}

void loop() {
  server.handleClient();
  
  float lux = lightMeter.readLightLevel();
  int brightness;

  if (lux < 1000) {
    brightness = 250; // 50% jasności
  } else {
    brightness = 1023; // 100% jasności
  }

  analogWrite(ledPin, brightness);
  delay(1000);
}
