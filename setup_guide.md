
# Setup Guide
## Soldier Monitoring System Using LoRa

### Hardware Requirements
- ESP32 development boards
- Compatible LoRa modules
- NEO-6M GPS module
- Compatible heart rate sensor
- Emergency SOS push button
- Jumper wires and suitable power supply

### Software Requirements
- Arduino IDE
- ESP32 board support package
- LoRa library
- TinyGPSPlus library

### Setup Steps

1. Install Arduino IDE.
2. Install the ESP32 board package.
3. Install the required libraries.
4. Connect the GPS module to the ESP32.
5. Connect the heart rate sensor according to its specifications.
6. Connect the LoRa module using the verified pin configuration.
7. Upload the transmitter code to the soldier-unit ESP32.
8. Upload the receiver code to the base-station ESP32.
9. Open Serial Monitor to inspect received messages.
10. Test each component individually before testing the complete system.

### Important Notes
- Verify all wiring against the actual code.
- The SX1278/Ra-02 LoRa module requires a suitable 3.3V supply.
- Transmitter and receiver must use compatible LoRa settings.
- GPS requires a valid satellite fix to provide location.
- Do not consider the system fully operational until hardware testing is complete.