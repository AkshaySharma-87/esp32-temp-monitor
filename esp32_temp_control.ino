//Header Files
#include <WiFi.h>
#include <HTTPClient.h>
#include <WebServer.h>
//WIFI SETUP 
const char* ssid = "YOUR_WIFI_NAME;
const char* password = "YOUR_WIFI_PASSWORD";

String apiKey = "YOUR_WRITE_API_KEY";

// Pins
const int tempPin = 34;
const int fanPin = 18;

// Variables
float temperature = 0;

// Web server
WebServer server(80);

// -------------------- WEB HANDLERS --------------------

void handleRoot() {
  String html = "<!DOCTYPE html><html>";
  
  html += "<head><title>ESP32 Temp Control</title></head>";
  html += "<body style='font-family: Arial; text-align:center;'>";

  html += "<h1>ESP32 Temperature Dashboard</h1>";
  html += "<h2>Temperature: " + String(temperature) + " °C</h2>";

  html += "<p><a href='/on'><button style='padding:10px'>Fan ON</button></a></p>";
  html += "<p><a href='/off'><button style='padding:10px'>Fan OFF</button></a></p>";

  // ThingSpeak graph embed (REPLACE CHANNEL ID)
  html += "<iframe width='450' height='260' style='border:1px solid #ccc;' ";
html += "src='https://thingspeak.com/channels/YOUR_CHANNEL_ID/charts/1'></iframe>";

  html += "</body></html>";

  server.send(200, "text/html", html);
}

void handleOn() {
  digitalWrite(fanPin, HIGH);
  server.send(200, "text/html", "<h2>Fan ON</h2><a href='/'>Back</a>");
}

void handleOff() {
  digitalWrite(fanPin, LOW);
  server.send(200, "text/html", "<h2>Fan OFF</h2><a href='/'>Back</a>");
}

// -------------------- SETUP --------------------

void setup() {
  Serial.begin(115200);

  pinMode(fanPin, OUTPUT);

  // WiFi Setup
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Routes
  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);

  server.begin();
}


void loop() {
  server.handleClient();

  // Read sensor (potentiometer simulation)
  int sensorValue = analogRead(tempPin);

  // Convert to temperature
  temperature = (sensorValue / 4095.0) * 100.0;

  Serial.print("Temperature: ");
  Serial.println(temperature);


  if (temperature > 30) {
    digitalWrite(fanPin, HIGH);
  } else {
    digitalWrite(fanPin, LOW);
  }

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

String url = "http://api.thingspeak.com/update?api_key=" + apiKey +
             "&field1=" + String(temperature);

    http.begin(url);
    int httpResponseCode = http.GET();

    Serial.print("HTTP Response: ");
    Serial.println(httpResponseCode);

    http.end();
  }

  delay(15000); 
}
