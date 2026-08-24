# 🌡️ ESP32 Temperature Monitoring & Fan Control
## 🚀 Overview

This project uses an ESP32 to monitor temperature and control a fan based on a threshold. 
It also provides a simple web interface and logs data to ThingSpeak.

## 🔧 Features
- 🌡️ Real-time temperature monitoring
- 🌀 Automatic fan control (threshold-based)
- 🌐 Web interface to control fan manually
- ☁️ Cloud data logging using ThingSpeak
- 📊 Live graph visualization

## 🛠️ Technologies Used
ESP32 (WiFi-enabled microcontroller)
Arduino framework
HTTP Client (for API communication)
WebServer (for local UI)
ThingSpeak (IoT cloud platform)

## ⚙️ How It Works
ESP32 connects to WiFi
Reads analog value from temperature sensor (or potentiometer in simulation)
Converts it into temperature
If temperature > 30°C → Fan ON
Else → Fan OFF
Sends temperature data to ThingSpeak every 15 seconds
Hosts a local web server for manual control

## 🌐 Web Interface
Access via:
http://<ESP32_IP>
Features:
View current temperature
Turn fan ON/OFF manually
View ThingSpeak graph (embedded)

## ☁️ ThingSpeak Integration
Data is sent using:
http://api.thingspeak.com/update?api_key=YOUR_WRITE_API_KEY&field1=value
View data:
https://thingspeak.com/channels/YOUR_CHANNEL_ID

## 🔑 Setup Instructions
1. Clone Repository
git clone https://github.com/your-username/your-repo-name.git
2. Configure WiFi
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";
3. Setup ThingSpeak
Create account on ThingSpeak
Create a new channel
Copy:
Write API Key
Channel ID
4. Update Code
String apiKey = "YOUR_WRITE_API_KEY";
Also update iframe:
https://thingspeak.com/channels/YOUR_CHANNEL_ID/charts/1

## 🔌 Hardware Requirements
- ESP32
- LED (Fan simulation)
- Resistor (220Ω)
- Potentiometer (optional)

## 🧪 Simulation
This project can be tested using:
Wokwi Simulator (used in this project)

## 📸 Screenshots
<img width="786" height="617" alt="image" src="https://github.com/user-attachments/assets/217cc2d3-6b64-4024-82c3-881b3ce5722f" />

Include:
ESP32 simulation setup
Serial Monitor output
Connected!
IP Address: 10.80.143.245
Temperature: 0.00
HTTP Response: 200

Web interface page
<img src="https://github.com/user-attachments/assets/96288689-083b-40e9-a6a9-76bf0ccb7af9" width="800"/>

## 🧠 What I Learned
- How ESP32 connects and communicates over WiFi
- Building a simple web server using WebServer library
- Sending HTTP requests to cloud APIs (ThingSpeak)
- Converting analog values into usable data

## ⚡ Challenges Faced
- COM port busy issues during ESP32 upload
- Understanding ThingSpeak API format
- Debugging WiFi connection loops

## 📈 Future Improvements
Add humidity sensor
Mobile app integration
Alerts when temperature exceeds threshold
Multiple sensors support

## ⚠️ Important Notes
Do NOT upload your real API key publicly

## 👨‍💻 Author
Akshay Sharma
B.Tech ECE, NIT Srinagar
