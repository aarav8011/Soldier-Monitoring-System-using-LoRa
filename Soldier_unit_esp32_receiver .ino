#include <SPI.h>
#include <LoRa.h>

#define SCK 5
#define MISO 19
#define MOSI 27
#define SS 18
#define RST 14
#define DIO0 26

void setup() {
  Serial.begin(115200);

  SPI.begin(SCK, MISO, MOSI, SS);
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa Initialization Failed!");
    while (true) {
      delay(1000);
    }
  }

  Serial.println("================================");
  Serial.println(" SOLDIER MONITORING BASE STATION");
  Serial.println("================================");
  Serial.println("Waiting for soldier data...");
}

void loop() {
  int packetSize = LoRa.parsePacket();

  if (packetSize > 0) {
    String receivedData = "";

    while (LoRa.available()) {
      receivedData += (char)LoRa.read();
    }

    Serial.println("\n--- SOLDIER STATUS ---");
    Serial.println(receivedData);

    if (receivedData.indexOf("SOS:PRESSED") >= 0) {
      Serial.println("!!! EMERGENCY SOS ALERT !!!");
    } else if (receivedData.indexOf("SOS:NORMAL") >= 0) {
      Serial.println("Status: Normal");
    }

    if (receivedData.indexOf("LAT:") >= 0 &&
        receivedData.indexOf("LON:") >= 0) {
      Serial.println("GPS coordinates received.");
    } else {
      Serial.println("GPS location unavailable.");
    }

    Serial.print("Signal Strength (RSSI): ");
    Serial.print(LoRa.packetRssi());
    Serial.println(" dBm");

    Serial.println("----------------------");
  }
}

