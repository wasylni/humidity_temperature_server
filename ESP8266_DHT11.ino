#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <DHT.h>

#define DHTTYPE DHT11
#define DHTPIN  0 // ATTENTION 0 is pin D3 on my ESP8266 ESP12

const char* ssid     = "YOUR_SSID";
const char* password = "YOUR_PASS";

ESP8266WebServer server(1234);
DHT dht(DHTPIN, DHTTYPE,16); // 16 is only correct value for ESP8266 ESP12 DHT11 if this is set wrong you will get reading like 2147483647

float humidity, temp_f;
String webString="";

unsigned long previousMillis = 0;    
const long interval = 2000;

void handle_root() {
  server.send(200, "text/plain", "ESP8266 running DHT11 sensor, to read data from sensor GET /temp or GET /humidity");
  delay(100);
}

void setup(void)
{
  Serial.begin(115200);  // to get stdout Tools -> Serial Monitor on 115200 baud
  dht.begin();

  // Connect to WiFi network
  WiFi.begin(ssid, password);
  Serial.print("\n\r \n\r connecting to the WI-FI network");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("DHT11 Reading Server");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handle_root);

  server.on("/temp", [](){  // if you add this subdirectory to your webserver call, you get text below :)
    gettemperature();       // read sensor
    webString="Temperature: "+String((int)temp_f)+" C";   // Arduino has a hard time with float to string
    server.send(200, "text/plain", webString);            // send to someones browser when asked
  });

  server.on("/humidity", [](){  // if you add this subdirectory to your webserver call, you get text below :)
    gettemperature();           // read sensor
    webString="Humidity: "+String((int)humidity)+"%";
    server.send(200, "text/plain", webString);               // send to someones browser when asked
  });

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void)
{
  server.handleClient();
}

void gettemperature() {
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    humidity = dht.readHumidity();          // Read humidity (percent)
    temp_f = dht.readTemperature(false);     // Read temperature as Celcius
    if (isnan(humidity) || isnan(temp_f)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }
  }
}