/* Documentation: 
  - https://github.com/esp8266/Arduino
  - https://docs.arduino.cc/
      - https://docs.arduino.cc/programming/
      - https://docs.arduino.cc/libraries/ 
*/
#include <ESP8266WebServer.h>  // For setting up a simple web server
#include <ESP8266WiFi.h>       // For enabling ESP8266 to create a Wi-Fi network
#include <Servo.h>             // For controlling servomotor

// GPIO pins definition for the servo and LED diode
#define SERVO_PIN D1 
#define LED_PIN D5    

// Wi-Fi credentials for Access Point mode
const char* WIFI_SSID = "ESP8266-WiFi-Name";         // Set custom ESP8266 Wi-Fi name  
const char* WIFI_PASSWORD = "ESP8266-WiFi-Password"; // Set custom and strong ESP8266 Wi-Fi password

Servo servoMotor;               // Create a servo object
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

// Function to control the servomotor based on received signal
void controlServo() {
  String signal = webServer.arg("action"); // Get the "action" parameter from the HTTP request

  if (signal == "on") {         // If the signal says "on"
    blinkLed();                 // Blink LED diode to indicate action
    servoMotor.write(90);       // Move servo to 90 degrees
    delay(500);                 // Wait 500ms
    servoMotor.write(120);      // Move servo to 120 degrees (or 60 degrees)
    delay(500);                 // Wait 500ms
    servoMotor.write(90);       // Return to 90 degrees
  } 
  else if (signal == "off") {   // If the signal says "off"
    blinkLed();                 // Blink LED diode to indicate action
    servoMotor.write(90);       // Move servo to 90 degrees
    delay(500);                 // Wait 500ms
    servoMotor.write(60);       // Move servo to 60 degrees (or 120 degrees)
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
  servoMotor.attach(SERVO_PIN); // Attach the servomotor to its pin
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
