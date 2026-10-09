
# Block Diagram
## Soldier Monitoring System Using LoRa

```text
+---------------------+
|   GPS Module        |
|   NEO-6M            |
+----------+----------+
           |
           v
+---------------------+       +---------------------+
| Heart Rate Sensor   |------>|                     |
+---------------------+       |                     |
                              |     ESP32           |
+---------------------+       | Soldier Unit        |
| Emergency SOS Button|------>|                     |
+---------------------+       +----------+----------+
                                         |
                                         v
                              +---------------------+
                              | LoRa Transmitter    |
                              +----------+----------+
                                         |
                                         | Wireless LoRa
                                         v
                              +---------------------+
                              | LoRa Receiver       |
                              +----------+----------+
                                         |
                                         v
                              +---------------------+
                              | Base Station ESP32  |
                              | Serial Monitor      |
                              +---------------------+
