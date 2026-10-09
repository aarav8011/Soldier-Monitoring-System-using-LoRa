
#include <SPI.h>
#include <LoRa.h>
#include <TinyGPSPlus.h>

#define SCK 5
#define MISO 19
#define MOSI 27
#define SS 18
#define RST 14
#define DIO0 26

#define SOS_BUTTON 25

#define GPS_RX 16
#define GPS_TX 17

TinyGPSPlus gps;
HardwareSerial gpsSerial(2);

void setup() {
  Serial.begin(115200);
  gpsSerial.begin(9600, SERIAL_8N1, GPS_RX, GPS_TX);

  pinMode(SOS_BUTTON, INPUT_PULLUP);

  SPI.begin(SCK, MISO, MOSI, SS);
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa initialization failed!");
    while (true) {
      delay(1000);
    }
  }

  Serial.println("GPS + SOS Transmitter Ready");
}

void loop() {
  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());
  }

  bool sosPressed = (digitalRead(SOS_BUTTON) == LOW);

  String message = "SOS:";
  message += sosPressed ? "PRESSED" : "NORMAL";

  if (gps.location.isValid()) {
    message += ",LAT:";
    message += String(gps.location.lat(), 6);
    message += ",LON:";
    message += String(gps.location.lng(), 6);
  } else {
    message += ",GPS:WAITING";
  }

  LoRa.beginPacket();
  LoRa.print(message);
  LoRa.endPacket();

  Serial.println(message);
  delay(2000);
}