# Single Light Smart Switcher 1.0 with light monitoring
This project aims to create a Single Light Smart Switcher controlled via phone/computer/tablet using wifi with light monitoring.

## YouTube presentation
<a href="https://youtube.com/shorts/5B9hfxMmvcQ?feature=share3">Click here to see video presentation</a>

## YouTube tutorial
<a href="#">#todo Click here to see video tutorial </a>

## Plan
<a href="https://fritzing.org/">(Fritzing Software)</a>

<p align="center"><img src="img/" alt="#" width="90%"/>#todo</p>

## Schematic
<a href="https://fritzing.org/">(Fritzing Software)</a>

<p align="center"><img src="img/" alt="#" width="80%"/>#todo</p>

## Used Hardware
- [WiFi Module ESP8266 + NodeMCU v3](https://botland.com.pl/moduly-wifi-esp8266/8241-modul-wifi-esp8266-nodemcu-v3-5904422300630.html)

<p align="center"><img src="img/wifi-esp8266-nodemcu-v3.webp" alt="NodeMCUv3" width="60%"/></p>

<p align="center"><img src="img/Introduction-to-NodeMCU-V3.png.webp" alt="NodeMCUv3" width="60%"/></p>

<p align="center"><img src="img/esp8266-wifi-nodemcu-v3.webp" alt="NodeMCUv3" width="30%"/></p>

- [Light sensor BH1750](https://botland.com.pl/czujniki-swiatla-i-koloru/2024-czujnik-natezenia-swiatla-bh1750-5904422373283.html)

<p align="center"><img src="img/light-sensor-bh1750.webp" alt="BH1750" width="40%"/></p>

- [Serwo SG-90 - micro - 180 degrees](https://botland.com.pl/serwa-typu-micro/13128-serwo-sg-90-micro-180-5904422350338.html)

<p align="center"><img src="img/serwo-sg-90-micro-180.webp" alt="Servo" width="40%"/></p>

<p>*we will use double-arm servo horn</p>

<p align="center"><img src="img/1-serwo-sg-90-micro-180.webp" alt="Servo" width="40%"/></p>

- [LED Diode 5mm](https://botland.com.pl/diody-led/13606-dioda-led-5mm-zolta-10szt-5903351244244.html)

<p align="center"><img src="img/dioda-led-5mm-zolta-10szt.webp" alt="LED" width="40%"/></p>

- [Wires (male-to-male, female-to-female and men-to-female)](https://botland.com.pl/przewody-polaczeniowe/19946-zestaw-przewodow-polaczeniowych-justpi-20cm-3x40szt-m-m-z-z-m-z-120szt-5904422328702.html)

<p align="center"><img src="img/wires-justpi-20cm-3x40szt-m-m-f-f-m-f-120szt.webp" alt="Wires" width="40%"/></p>

- [2 x Breadboard](https://botland.store/breadoards/19942-breadboard-justpi-400-holes-5904422328627.html)

<p align="center"><img src="img/breadboard-justpi-400-holes.webp" alt="Breadboard" width="40%"/></p>

## Power
### Version with charger

- Charger

<p align="center"><img src="img/charger.jpg" alt="Charger" width="40%"/></p>

- Micro USB cable

<p align="center"><img src="img/micro-usb-cable.jpg" alt="Micro USB" width="40%"/></p>

### Version with powerbank

- Standard powerbank

<p align="center"><img src="img/powerbank.jpg" alt="Long wires" width="40%"/></p>

- Micro USB cable

<p align="center"><img src="img/micro-usb-cable.jpg" alt="Micro USB" width="40%"/></p>

### Version with batteries

- [4 x AA (R6 LR6) alkaline battery](https://botland.store/batteries/9343-everactive-pro-aa-r6-lr6-alkaline-battery-4pcs-5903205770974.html)

<p align="center"><img src="img/everactive-pro-aa-r6-lr6-alkaline-battery-4pcs.webp" alt="4 Baterries" width="40%"/></p>

- [Battery holder - 4 x AA (R6)](https://botland.store/battery-holders/173-battery-holder-4-x-aa-r6-5904422329389.html)

<p align="center"><img src="img/battery-holder-4-x-aa-r6.webp" alt="Baterry holder" width="40%"/></p>

- [Male Pin Raster](https://botland.store/bls-connectors/4776-male-pin-for-case-socket-raster-25mm-10pcs-5904422303181.html)

<p align="center"><img src="img/pin-male-raster-254mm.webp" alt="Female Pin Raster" width="40%"/></p>
  
- [BLS connectors](https://botland.com.pl/zlacza-bls/5204-zlacze-typu-bls-gniazdo-1x1-5szt-5904422353599.html)

<p align="center"><img src="img/bls-connector.webp" alt="BLS" width="40%"/></p>

#### Plan and schematic with batteries

<p align="center"><img src="img/" alt="Plan with batteries" width="80%"/>#todo</p>

<p align="center"><img src="img/" alt="Schematic with batteries" width="40%"/>#todo</p>

## Hardware Documentation
[NodeMCU](https://nodemcu.readthedocs.io/en/release/)

[BH1750 Module](https://nodemcu.readthedocs.io/en/release/lua-modules/bh1750/)

[Servo](http://www.datasheet-pdf.com/PDF/SG90-Datasheet-TowerPro-791970)

## Used Tools
- <a href="https://fritzing.org/">Fritzing Software</a>
    - <a href="https://github.com/roman-miniailov/nodemcu-v3-fritzing">NodeMCUv3 Wifi ESP86266 component</a>
    - <a href="https://github.com/vdemay/fritzing-parts/tree/master/parts">BH1750 component</a>
- <a href="https://cloud.arduino.cc/">Arduino Cloud - Online Editor</a>

## My recommendations
In above video presentation I used PowerBank insted of typical USB-C charger, mainly because of another little experiment I was conducting by the way of this project. Also, my recommendation is to buy 4 long wires to connect BH1750 and NodeMCU v3 insted of using many male-to-female wires since it causes many connecting problems during installation (I was simply too lazy :)).

## Resources and Inspiration
<a href="https://electechoz.blogspot.com/2022/01/esp8266-webserver-controller-servo-motor.html">Eleco Techoz</a>
