# Smart Single-Light Switch 1.0
This project aims to create a simple Smart Single-Light Switch controlled via phone/computer/tablet using wifi.
<p align="center"><img src="../../img/smart-single-light-switch-1.0.jpg" alt="Presentation" width="100%"/></p>

## YouTube tutorial
<a href="https://youtu.be/bshRV9Qr4Ys">Click here</a> to see video tutorial

## Sketch
<p align="center"><img src="../../img/general-version.jpg" alt="Photo sketch" width="100%"/></p>

Sketch made using <a href="https://fritzing.org/">Fritzing Software</a>

Download sketch here [(.fzz)](https://github.com/cyber-kinga/Smart-Light-Switch/tree/main/1.x%20Smart%20Single-Light%20Switch/1.1%20Smart%20Single-Light%20Switch/sketches)

<p align="center"><img src="../../img/General-sketch.png" alt="General sketch" width="100%"/></p>

## Used Hardware
- [WiFi Module ESP8266 + NodeMCU v3](https://botland.store/esp8266-wifi-modules/8241-esp8266-wifi-module-nodemcu-v3-5904422300630.html)

<p align="center"><img src="../../img/wifi-esp8266-nodemcu-v3.webp" alt="NodeMCUv3" width="60%"/></p>

<p align="center"><img src="../../img/Introduction-to-NodeMCU-V3.png.webp" alt="NodeMCUv3" width="60%"/></p>

<p align="center"><img src="../../img/esp8266-wifi-nodemcu-v3.webp" alt="NodeMCUv3" width="30%"/></p>

- [Serwo SG-90 - micro - 180 degrees](https://botland.store/micro-servos/13128-servo-sg-90-micro-180-5904422350338.html)

<p align="center"><img src="../../img/serwo-sg-90-micro-180.webp" alt="Servo" width="40%"/></p>

<p>*we will use double-arm servo horn</p>

<p align="center"><img src="../../img/1-serwo-sg-90-micro-180.webp" alt="Servo" width="40%"/></p>

- [LED Diode 5mm](https://botland.store/withdrawn-products/13606-led-5mm-yellow-10pcs-5903351244244.html)

<p align="center"><img src="../../img/led-5mm-yellow.webp" alt="LED" width="40%"/></p>

- [Wires (male-to-male, female-to-female and men-to-female)](https://botland.store/various-wires/19946-connecting-cables-set-justpi-20cm-3-x-40pcs-m-m-f-f-m-f-120pcs-5904422328702.html)

<p align="center"><img src="../../img/wires-justpi-20cm-3x40szt-m-m-f-f-m-f-120szt.webp" alt="Wires" width="40%"/></p>

- [2 x Breadboard](https://botland.store/breadoards/19942-breadboard-justpi-400-holes-5904422328627.html)

<p align="center"><img src="../../img/breadboard-justpi-400-holes.webp" alt="Breadboard" width="40%"/></p>

- Micro USB cable

<p align="center"><img src="../../img/micro-usb-cable.jpg" alt="Micro USB" width="40%"/></p>

## Power
### Version with charger
<p align="center"><img src="../../img/version-with-charger.jpg" alt="Version with charger" width="80%"/></p>

- Charger

<p align="center"><img src="../../img/charger.jpg" alt="Charger" width="40%"/></p>

### Version with powerbank
<p align="center"><img src="../../img/version-with-powerbank.jpg" alt="Version with powerbank" width="80%"/></p>

- Standard powerbank

<p align="center"><img src="../../img/powerbank.jpg" alt="Long wires" width="40%"/></p>

### Version with batteries
<p align="center"><img src="../../img/version-with-batteries.jpg" alt="Version with batteries" width="100%"/></p>

Download sketch here [(.fzz)](https://github.com/cyber-kinga/Smart-Light-Switch/tree/main/1.x%20Smart%20Single-Light%20Switch/1.1%20Smart%20Single-Light%20Switch/sketches)

<p align="center"><img src="../../img/Batteries-sketch.png" alt="Sketch with batteries" width="100%"/></p>

- [4 x AA (R6 LR6) alkaline battery](https://botland.store/batteries/9343-everactive-pro-aa-r6-lr6-alkaline-battery-4pcs-5903205770974.html)

<p align="center"><img src="../../img/everactive-pro-aa-r6-lr6-alkaline-battery-4pcs.webp" alt="4 Baterries" width="40%"/></p>

- [Battery holder - 4 x AA (R6)](https://botland.store/battery-holders/173-battery-holder-4-x-aa-r6-5904422329389.html)

<p align="center"><img src="../../img/battery-holder-4-x-aa-r6.webp" alt="Baterry holder" width="40%"/></p>

If you're using a battery basket, it can be delivered without pre-installed connectors (like above) — in that case you can use male pin rasters and BLS connectors to create the connectors yourself.

- [Male Pin Raster](https://botland.store/bls-connectors/4776-male-pin-for-case-socket-raster-25mm-10pcs-5904422303181.html)

<p align="center"><img src="../../img/pin-male-raster-254mm.webp" alt="Female Pin Raster" width="40%"/></p>
  
- [BLS connectors](https://botland.com.pl/zlacza-bls/5204-zlacze-typu-bls-gniazdo-1x1-5szt-5904422353599.html)

<p align="center"><img src="../../img/bls-connector.webp" alt="BLS" width="40%"/></p>

### Version without diode
You can delete the ```blinkLed()``` function along with its calls, as well as the following lines:
```c
#define LED_PIN D5  
```
```c
pinMode(LED_PIN, OUTPUT);
```

<p align="center"><img src="../../img/version-without-diode.jpg" alt="Version without diode" width="80%"/></p>

### Version without breadboard
<p align="center"><img src="../../img/version-without-breadboard.jpg" alt="Version without breadboard" width="80%"/></p>

## Accesing the web page
Type 192.168.4.1 address in you browser to control your device.

## Hardware Documentation
- [NodeMCU](https://github.com/nodemcu)

- [Servo](http://www.datasheet-pdf.com/PDF/SG90-Datasheet-TowerPro-791970)

## Software Documentation
- [github.com/esp8266/Arduino](https://github.com/esp8266/Arduino)

- [docs.arduino.cc](https://docs.arduino.cc/)
  - [docs.arduino.cc/programming](https://docs.arduino.cc/programming/)
  - [docs.arduino.cc/libraries](https://docs.arduino.cc/libraries/) 

## Used Tools
- <a href="https://fritzing.org/">Fritzing Software</a>
    - <a href="https://github.com/roman-miniailov/nodemcu-v3-fritzing">NodeMCUv3 Wifi ESP86266</a> component
    - <a href="https://robdomo.com/ressources/fritzing-parts/tower-pro-sg90-servo/">Serwo SG-90</a> component
- <a href="https://cloud.arduino.cc/">Arduino Cloud - Online Editor</a>
    - <a href="https://docs.arduino.cc/arduino-cloud/hardware/cloud-agent/">Arduino Cloud Agent</a> - it is a required plugin that enables serial communication between your board and the Arduino Cloud accessed via your web browser

## My recommendations and tips
1. Make sure to install the appropriate driver for your microcontroller — in this case, the CH340G driver.
You can usually find the driver name printed on the microcontroller chip itself.
<p align="center"><img src="../../img/esp8266-wifi-nodemcu-v3.webp" alt="NodeMCUv3" width="30%"/></p>
2. The angles in the following code assume that the servo motor is mounted with its sticker facing the breadboard. If the mounting orientation is different, the movement directions may need to be adjusted (possibly requiring swapping 60 and 120 degrees).

```c
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
```
3. Keep in mind that if you plan to power your device using a ```powerbank```, it won’t work without the LED diode. That’s because the microcontroller and servo together don’t draw enough power, causing a standard powerbank to quickly shut off, assuming there’s nothing to power.
To make the powerbank solution work, we need to make one small adjustment in our code: the LED diode should stay on continuously to create enough power demand and only blink when a signal is received. I’ve already implemented this solution in the code (you can find it within comments) so you don’t have to write it yourself.

```TIP: You can trick the powerbank in a different way by making the LED diode blink every x seconds. Give it a try!```

4. If the upload fails, the issue might be an old micro USB cable. Even if the cable looks fine, it could be damaged internally. I had this issue before so I bought a completely new micro USB cable and it solved all of my problems.
5. If you get a port busy error, you can open a Device Manager, find Ports (COM & LPT), locate your device, and disable & enable the driver. This should solve the issue.


## Resources and Inspiration
<a href="https://electechoz.blogspot.com/2022/01/esp8266-webserver-controller-servo-motor.html">Eleco Techoz</a>


