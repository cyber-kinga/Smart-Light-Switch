/* Documentation: 
  - https://github.com/esp8266/Arduino
  - https://docs.arduino.cc/
      - https://docs.arduino.cc/programming/
      - https://docs.arduino.cc/libraries/ 
*/
#include <ESP8266WebServer.h>  // For setting up a simple web server
#include <ESP8266WiFi.h>       // For enabling ESP8266 to create a Wi-Fi network
#include <Servo.h>             // For controlling servomotor
#include <BH1750.h>            // For BH1750 light intensity sensor
#include <Wire.h>              // For I2C communication with BH1750

// GPIO pins definition for the servo, LED diode and BH1750 pins
#define SERVO_PIN D1 
#define LED_PIN D5
#define SDA_PIN D3 
#define SCL_PIN D4  

// Wi-Fi credentials for Access Point (AP) mode
const char* WIFI_SSID = "ESP8266-WiFi-Name";         // Set custom ESP8266 Wi-Fi name, for example "Light"  
const char* WIFI_PASSWORD = "ESP8266-WiFi-Password"; // Set custom and strong ESP8266 Wi-Fi password

Servo servoMotor;               // Create a servo object
ESP8266WebServer webServer(80); // Create a web server object on port 80
BH1750 lightIntensitySensor;    // Create a BH1750 object

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
      .active {
        border: 5px solid #b4e6fd;
      }
      .container {
        margin-top: 50px;
      }
    </style>
  </head>
  <body>
    <div class="container">
      <h1>Control your Single-Light Smart Switch 1.1</h1>
      <br><br>
      <button type="button" onclick="sendSignal('on')" class="btn btn-on">On</button>
      <br><br>
      <button type="button" onclick="sendSignal('off')" class="btn btn-off">Off</button>   
    </div>
    
    <script>
      var btnOn = document.querySelector('.btn-on');
      var btnOff = document.querySelector('.btn-off');

      function sendSignal(action) { 
          var httpRequest = new XMLHttpRequest();
          httpRequest.open("GET", "/moveServo?action=" + action, true);   
          httpRequest.send();
      }

      function updateLightIntensity() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            var lux = parseFloat(this.responseText);
            if (lux >= 1000) {
              btnOn.classList.add('active');
              btnOff.classList.remove('active');
            } else {
              btnOn.classList.remove('active');
              btnOff.classList.add('active');
            }
          }
        };
        xhttp.open("GET", "/getLightIntensity", true);
        xhttp.send();
      }
      setInterval(updateLightIntensity, 5000);
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

// Function to read the current light level and send it back to the web client
void handleLightIntensity() {
  float lux = lightIntensitySensor.readLightLevel();    // Read the current light level from the BH1750 sensor (in lux)
  webServer.send(200, "text/plain", String(lux));       // Send the lux value back to the web client as plain text. The web client uses parseFloat() to convert it into a number 
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

  Wire.begin(SDA_PIN, SCL_PIN); // Initialize I2C communication on the defined SDA and SCL pins
  lightIntensitySensor.begin(); // Initialize the BH1750 light inensity sensor so it’s ready to take readings

  // Start the ESP8266 as an Access Point (AP) mode
  WiFi.softAP(WIFI_SSID, WIFI_PASSWORD); 

  // Define web server routes
  webServer.on("/", webApp);                                 // Handle requests using webApp function for the main webpage available at the following address http:/192.168.4.1/
  webServer.on("/moveServo", controlServo);                  // Handle requests for servo movement available at the following address http:/192.168.4.1/moveServo
  webServer.on("/getLightIntensity", handleLightIntensity);  // Handle requests for BH1750 available at the following address http:/192.168.4.1/getLightIntensity --> you can see here the current light level in lux!
  
  webServer.begin(); // Start the web server 
}

//The loop() function does precisely what its name suggests, and loops consecutively, allowing your program to change and respond. 
void loop() {
  webServer.handleClient(); // Process incoming client requests
}
