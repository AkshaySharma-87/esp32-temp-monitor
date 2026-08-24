📌 ESP32 Temperature Monitoring & Fan Control System
🚀 Overview

This project is an IoT-based temperature monitoring and control system using ESP32.
It reads temperature data, controls a fan automatically, provides a web interface, and sends data to the cloud using ThingSpeak.

🔧 Features
🌡️ Real-time temperature monitoring
🌀 Automatic fan control (threshold-based)
🌐 Web interface to control fan manually
☁️ Cloud data logging using ThingSpeak
📊 Live graph visualization (ThingSpeak integration)
🛠️ Technologies Used
ESP32 (WiFi-enabled microcontroller)
Arduino framework
HTTP Client (for API communication)
WebServer (for local UI)
ThingSpeak (IoT cloud platform)
⚙️ How It Works
ESP32 connects to WiFi
Reads analog value from temperature sensor (or potentiometer in simulation)
Converts it into temperature
If temperature > 30°C → Fan ON
Else → Fan OFF
Sends temperature data to ThingSpeak every 15 seconds
Hosts a local web server for manual control
🌐 Web Interface

Access via:

http://<ESP32_IP>

Features:

View current temperature
Turn fan ON/OFF manually
View ThingSpeak graph (embedded)
☁️ ThingSpeak Integration
Data is sent using:
http://api.thingspeak.com/update?api_key=YOUR_WRITE_API_KEY&field1=value
View data:
https://thingspeak.com/channels/YOUR_CHANNEL_ID
🔑 Setup Instructions
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
🔌 Hardware Requirements
ESP32
LED (Fan simulation)
Resistor (220Ω)
Potentiometer (optional, for simulation of temperature)
🧪 Simulation

This project can be tested using:

Wokwi Simulator (used in this project)
📸 Screenshots (Add these before pushing)

Include:

ESP32 simulation setup
Serial Monitor output
ThingSpeak graph
Web interface page
📈 Future Improvements
Add humidity sensor
Mobile app integration
Alerts when temperature exceeds threshold
Multiple sensors support
⚠️ Important Notes
Do NOT upload your real API key publicly
Replace it with:
"YOUR_WRITE_API_KEY"
👨‍💻 Author

Akshay Sharma
B.Tech ECE, NIT Srinagar
