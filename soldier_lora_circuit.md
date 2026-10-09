soldier_lora_circuit_connection.md
# Soldier Monitoring System Using LoRa
## Circuit Connections

### 1. ESP32 to LoRa Module (SX1278 / Ra-02)

| LoRa Module Pin | ESP32 Pin |
|---|---|
| VCC | 3.3V |
| GND | GND |
| SCK | GPIO 18 |
| MISO | GPIO 19 |
| MOSI | GPIO 23 |
| NSS / CS | GPIO 5 |
| RESET | GPIO 14 |
| DIO0 | GPIO 26 |

### 2. ESP32 to GPS Module (NEO-6M)

| GPS Module Pin | ESP32 Pin |
|---|---|
| TX | GPIO 16 |
| RX | GPIO 17 |
| GND | GND |
| VCC | As specified for the GPS module |

### 3. ESP32 to Heart Rate Sensor

| Heart Rate Sensor Pin | ESP32 Pin |
|---|---|
| Signal / OUT | GPIO 34 |
| GND | GND |
| VCC | As specified for the sensor |

### 4. ESP32 to Emergency SOS Button

| Button Connection | ESP32 Pin |
|---|---|
| One terminal | GPIO 32 |
| Other terminal | GND |

Configure GPIO 32 as INPUT_PULLUP in the program.

### Working Principle

1. The GPS module obtains the soldier's geographical location.
2. The heart rate sensor measures heart rate.
3. The ESP32 processes the available sensor data.
4. The LoRa transmitter sends data to the base station.
5. The receiver ESP32 receives the transmitted information.
6. The SOS button can trigger an emergency alert.

### Important Notes

- The SX1278 / Ra-02 LoRa module requires a 3.3V supply. Do not connect it to 5V.
- Check the GPS and heart-rate sensor voltage requirements before connecting.
- Connect all modules to a common GND.
- Use a compatible LoRa antenna.
- The transmitter and receiver must use compatible LoRa settings.
-
