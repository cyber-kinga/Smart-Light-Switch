/* Documentation: 
  - https://github.com/esp8266/Arduino
  - https://docs.arduino.cc/libraries/ 
*/
#include <ESP8266WiFi.h>       
#include <WiFiClient.h>        
#include <ESP8266WebServer.h>  
#include <Servo.h>       

// GPIO pins for the servo and LED diode
#define SERVO_PIN D1 
#define LED_PIN D5    

// Wi-Fi credentials for Access Point mode
const char* WIFI_SSID = "Light"; //Wi-Fi name  
const char* WIFI_PASSWORD = "123"; //Wi-Fi password

Servo servoMotor; // Create a Servo object
ESP8266WebServer webServer(80); // Create a web server on port 80

// HTML page stored in program memory (PROGMEM)
const char Index[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
      html {
        font-family: Lato, sans-serif;
        display: inline-block;
        margin: 0 auto;
        text-align: center;
        text-shadow: 2px 2px 5px #fff;
      }
      h1 {
        color: #1cb4fa;
      }
      .btn {
        color: white;
        background-color: #1cb4fa;
        padding: 20px 55px;
        text-align: center;
        text-decoration: none;
        display: inline-block;
        border: 5px solid #fff;
        cursor: pointer;
        font-weight: bold;
      }
      .container {
        margin-top: 50px;
      }
    </style>
  </head>
  <body>
    <div class="container">
      <h1>Control your Single-Light Smart Switch 1.0</h1>
      <br><br>
      <button type="button" onclick="sendSignal('on')" class="btn btn-on">On</button>
      <br><br>
      <button type="button" onclick="sendSignal('off')" class="btn btn-off">Off</button>
    </div>
    
    <script>
      function sendSignal(action) { 
          var httpRequest = new XMLHttpRequest();
          httpRequest.open("GET", "/moveServo?action=" + action, true);   
          httpRequest.send();
      }
    </script>
  </body>
</html>
)=====";

// Function to handle the webpage request
void webApp() { 
  webServer.send(200, "text/html", Index); // Send the HTML page as response
}

// Comment below function when using powerbank
// Function to blink the LED diode to indicate action/signal
void blinkLed() {
  digitalWrite(LED_PIN, HIGH); // Turn LED diode on
  delay(100);                  // Wait 100ms
  digitalWrite(LED_PIN, LOW);  // Turn LED diode off
  delay(100);                  // Wait 100ms
}

// Uncomment below function when using powerbank
// Function to blink the LED diode while keeping it constantly ON
/*void blinkLed() {
  digitalWrite(LED_PIN, LOW);  // Turn LED off (assuming LOW is off)
  delay(100);                  // Wait 100ms
  digitalWrite(LED_PIN, HIGH); // Turn LED back on (assuming HIGH is on)
  delay(100);                  // Wait 100ms
}*/

// Function to control the servo motor based on received signals
void controlServo() {
  String signal = webServer.arg("action"); // Get the "action" parameter from the HTTP request

  if (signal == "on") {         // If the signal says "on"
    blinkLed();                 // Blink LED diode to indicate action
    servoMotor.write(90);       // Move servo to 90 degrees
    delay(500);                 // Wait 500ms
    servoMotor.write(120);      // Move servo to 120 degrees
    delay(500);                 // Wait 500ms
    servoMotor.write(90);       // Return to 90 degrees
  } 
  else if (signal == "off") {   // If the signal says "off"
    blinkLed();                 // Blink LED diode to indicate action
    servoMotor.write(90);       // Move servo to 90 degrees
    delay(500);                 // Wait 500ms
    servoMotor.write(60);       // Move servo to 60 degrees
    delay(500);                 // Wait 500ms
    servoMotor.write(90);       // Return to 90 degrees
  }

  webServer.send(200, "text/plain", "OK"); // Send 200 OK response back to the client
}

/* The setup() function is called when a sketch starts. 
  Use it to initialize variables, pin modes, start using libraries, etc. 
  The setup() function will only run once, after each powerup or reset of the Arduino board. 
*/
void setup() {
  servoMotor.attach(SERVO_PIN); // Attach the servo motor to its pin
  pinMode(LED_PIN, OUTPUT);     // Set the LED diode pin as an output

  // Uncomment below line when using powerbank
  // digitalWrite(LED_PIN, HIGH);  // LED diode stays constantly ON at startup

  // Start the ESP8266 as an Access Point (AP mode)
  WiFi.softAP(WIFI_SSID, WIFI_PASSWORD); 

  // Define web server routes
  webServer.on("/", webApp); // Serve the main webpage
  webServer.on("/moveServo", controlServo); // Handle servo movement requests

  webServer.begin(); // Start the web server
}

//The loop() function does precisely what its name suggests, and loops consecutively, allowing your program to change and respond. 
void loop() {
  webServer.handleClient(); // Process incoming client requests
}
