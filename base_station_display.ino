
#include <SPI.h>
#include <LoRa.h>

// LoRa module connections
#define LORA_SCK 18
#define LORA_MISO 19
#define LORA_MOSI 23
#define LORA_SS 5
#define LORA_RST 14
#define LORA_DIO0 26

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Soldier Monitoring Base Station");

  SPI.begin(LORA_SCK, LORA_MISO, LORA_MOSI, LORA_SS);

  LoRa.setPins(LORA_SS, LORA_RST, LORA_DIO0);

  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa initialization failed!");
    while (true) {
      delay(1000);
    }
  }

  Serial.println("LoRa Receiver Ready");
}

void loop() {
  int packetSize = LoRa.parsePacket();

  if (packetSize) {
    Serial.print("Received Soldier Data: ");

    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }

    Serial.println();
    Serial.print("Signal Strength (RSSI): ");
    Serial.println(LoRa.packetRssi());
  }
}
