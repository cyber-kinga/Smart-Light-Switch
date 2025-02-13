/* Documentation: 
  - https://github.com/esp8266/Arduino
  - https://docs.arduino.cc/
      - https://docs.arduino.cc/programming/
      - https://docs.arduino.cc/libraries/ 
*/
#include <ESP8266WebServer.h>  // For setting up a simple web server
#include <ESP8266WiFi.h>       // For enabling ESP8266 to create a Wi-Fi network
#include <Servo.h>             // For controlling servo motors 

// GPIO pins definition for two servos and LED diode
#define SERVO1_PIN D1 
#define SERVO2_PIN D2
#define LED_PIN D5    

// Wi-Fi credentials for Access Point mode
const char* WIFI_SSID = "ESP8266-WiFi-Name";         // Set custom ESP8266 Wi-Fi name  
const char* WIFI_PASSWORD = "ESP8266-WiFi-Password"; // Set custom and strong ESP8266 Wi-Fi password

Servo servoMotor1, servoMotor2; // Create servo objects
ESP8266WebServer webServer(80); // Create a web server object on port 80

// HTML page stored in program memory (PROGMEM) and available at the 192.168.4.1 address
const char Index[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
      html {
        font-family: Lato, sans-serif;
        text-align: center;
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
        border: none;
        cursor: pointer;
        font-weight: bold;
      }
      .container {
        margin-top: 50px;
      }
      .light1 {
        background-color: #1cb4fa;
      }
      .light2 {
        background-color: #048ac8;
        margin-top: 5px;
      }
    </style>
  </head>
  <body>
    <div class="container">
      <h1>Control your Single-Light Smart Switch 1.0</h1>
      <br><br>
      <button onclick="sendSignal('on1')" class="btn btn-on light1">On</button>
      <button onclick="sendSignal('on2')" class="btn btn-on light1">On</button>
      <br>
      <button onclick="sendSignal('off1')" class="btn btn-off light2">Off</button>
      <button onclick="sendSignal('off2')" class="btn btn-off light2">Off</button>
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

// Send the HTML page to the client
void webApp() { 
  webServer.send(200, "text/html", Index); 
}

// Comment or delete below function when using powerbank
// Function to blink the LED diode to indicate signal (action)
void blinkLed() {
  digitalWrite(LED_PIN, HIGH); // Turn LED diode on
  delay(100);                  // Wait 100ms
  digitalWrite(LED_PIN, LOW);  // Turn LED diode off
}

// Uncomment the function below when using a powerbank, otherwise - you can delete it.
// Function to blink the LED diode while keeping it constantly ON
/*void blinkLed() {
  digitalWrite(LED_PIN, LOW);  // Turn LED off
  delay(100);                  // Wait 100ms
  digitalWrite(LED_PIN, HIGH); // Turn LED back on
}*/

// Function to control the servo motor based on received signal
void controlServo() {
  String signal = webServer.arg("action"); // Get the "action" parameter from the HTTP request

  if (signal == "on1") {        // If the signal says "on"
    blinkLed();                 // Blink LED diode to indicate action
    servoMotor1.write(90);      // Move servo1 to 90 degrees
    delay(500);                 // Wait 500ms
    servoMotor1.write(120);     // Move servo1 to 120 degrees (or 60 degrees)
    delay(500);                 // Wait 500ms
    servoMotor1.write(90);      // Return to 90 degrees
  } 
  else if (signal == "off1") {  // If the signal says "off"
    blinkLed();                 // Blink LED diode to indicate action
    servoMotor1.write(90);      // Move servo1 to 90 degrees
    delay(500);                 // Wait 500ms
    servoMotor1.write(60);      // Move servo1 to 60 degrees (or 120 degrees)
    delay(500);                 // Wait 500ms
    servoMotor1.write(90);      // Return to 90 degrees
  } 
  else if (signal == "on2") {   // If the signal says "on"
    blinkLed();                 // Blink LED diode to indicate action
    servoMotor2.write(90);      // Move servo2 to 90 degrees
    delay(500);                 // Wait 500ms
    servoMotor2.write(120);     // Move servo2 to 120 degrees (or 60 degrees)
    delay(500);                 // Wait 500ms
    servoMotor2.write(90);      // Return to 90 degrees
  } 
  else if (signal == "off2") {  // If the signal says "off"
    blinkLed();                 // Blink LED diode to indicate action
    servoMotor2.write(90);      // Move servo2 to 90 degrees
    delay(500);                 // Wait 500ms
    servoMotor2.write(60);      // Move servo2 to 60 degrees (or 120 degrees)
    delay(500);                 // Wait 500ms
    servoMotor2.write(90);      // Return to 90 degrees
  }

  webServer.send(200, "text/plain", "OK"); // Send 200 OK response back to the client
}

/* The setup() function is called when a sketch starts. 
  Use it to initialize variables, pin modes, start using libraries, etc. 
  The setup() function will only run once, after each powerup or reset of the Arduino board. 
*/
void setup() {
  servoMotor1.attach(SERVO1_PIN); // Attach the servo motor 1 to its pin
  servoMotor2.attach(SERVO2_PIN); // Attach the servo motor 2 to its pin
  pinMode(LED_PIN, OUTPUT);     // Set the LED diode pin as an output

  // Uncomment the line below when using a powerbank, otherwise - you can delete it.
  // digitalWrite(LED_PIN, HIGH);  // LED diode stays constantly ON at startup

  // Start the ESP8266 as an Access Point (AP mode)
  WiFi.softAP(WIFI_SSID, WIFI_PASSWORD); 

  // Define web server routes
  webServer.on("/", webApp);                // Handle requests using webApp function for the main webpage "/"
  webServer.on("/moveServo", controlServo); // Handle requests for servo movement

  webServer.begin(); // Start the web server 
}

//The loop() function does precisely what its name suggests, and loops consecutively, allowing your program to change and respond. 
void loop() {
  webServer.handleClient(); // Process incoming client requests
}
