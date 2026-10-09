
# Project Architecture
## Soldier Monitoring System Using LoRa

### 1. Soldier Unit
The soldier unit contains an ESP32 microcontroller, GPS module, heart rate sensor, SOS button, and LoRa transmitter.

### 2. Data Collection
The GPS module obtains latitude and longitude when a valid satellite fix is available. The heart rate sensor provides pulse readings for the prototype.

### 3. Data Processing
The ESP32 reads the available sensor information and prepares it for transmission.

### 4. Wireless Communication
The LoRa module sends the prepared data packets to a compatible receiver.

### 5. Base Station
The base station uses a receiver and ESP32 to receive and display transmitted information.

### 6. Emergency Alert
When the SOS button is pressed, the programmed system can send an emergency message to the base station.

### 7. Data Flow
GPS + Heart Rate Sensor + SOS Button
                  |
                  v
             Soldier ESP32
                  |
                  v
             LoRa Transmitter
                  |
             Wireless Link
                  |
                  v
              LoRa Receiver
                  |
                  v
            Base Station ESP32
                  |
                  v
            Received Data Display

### Note
This architecture describes the intended system design. Actual functionality depends on hardware connections, code integration, and testing.