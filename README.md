## Temperature / Humidity sensor based on ESP8266

Components required:
  
 - ESP8266 module (NodeMcu Development Board ESP8266 12E WIFI CH340 v3 USB ESP12 ESP-12)
 - DHT11 temperature/humidity sensor (Temperature and Relative Humidity Sensor Module 2016 1 PCS for arduino DHT11)
 - micro USB cable
 
Software:
 
 - Adruino IDE [sample guide to configure IDE to support ESP8266 module](http://www.instructables.com/id/Quick-Start-Guide-to-Arduino-IDE-With-NodeMCU-ESP8/)
 - Adafruit_Sensor library [https://github.com/adafruit/Adafruit_Sensor](https://github.com/adafruit/Adafruit_Sensor)
 - DHT library Andruino library required to read data from DHT11 sensor[https://github.com/adafruit/DHT-sensor-library](https://github.com/adafruit/DHT-sensor-library)
 
Run:
1. Configure Adruino IDE connect ESP8266 board
1. copy libraries to libraries dir in your adruino workspace
1. Upload code from ESP8266_DHT11.ino file 
1. go to the browser and GET http://YOUR_IP:1234/temp
1. go to the browser and GET http://YOUR_IP:1234/humidity

[![humidity temperature server](https://img.youtube.com/vi/myAJym105Ew/0.jpg)](https://youtu.be/myAJym105Ew)

