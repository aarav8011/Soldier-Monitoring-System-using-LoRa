
# System Flowchart
## Soldier Monitoring System Using LoRa

```text
          +------------------+
          |       START      |
          +--------+---------+
                   |
                   v
          +------------------+
          | Initialize ESP32 |
          +--------+---------+
                   |
                   v
          +------------------+
          | Read GPS Data    |
          +--------+---------+
                   |
                   v
          +------------------+
          | Read Heart Rate  |
          +--------+---------+
                   |
                   v
          +------------------+
          | Check SOS Button |
          +--------+---------+
                   |
                   v
          +------------------+
          | Prepare Data     |
          +--------+---------+
                   |
                   v
          +------------------+
          | Send Data via    |
          | LoRa Transmitter |
          +--------+---------+
                   |
                   v
          +------------------+
          | LoRa Receiver    |
          +--------+---------+
                   |
                   v
          +------------------+
          | Display Received |
          | Data             |
          +--------+---------+
                   |
                   v
          +------------------+
          | Repeat Process   |
          +------------------+
