
#include <SPI.h>
#include <LoRa.h>

#define LORA_CS 18
#define LORA_RST 14
#define LORA_DIO0 26

void setup() {
  Serial.begin(115200);

  LoRa.setPins(LORA_CS, LORA_RST, LORA_DIO0);

  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa initialization failed!");
    while (true) {
      delay(1000);
    }
  }

  Serial.println("Base Station Ready");
}

void loop() {
  int packetSize = LoRa.parsePacket();

  if (packetSize) {
    while (LoRa.available()) {
      Serial.write(LoRa.read());
    }
    Serial.println();
  }
}
