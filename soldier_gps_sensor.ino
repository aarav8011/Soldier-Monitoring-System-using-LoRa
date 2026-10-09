#include <TinyGPSPlus.h>
#include <HardwareSerial.h>

TinyGPSPlus gps;
HardwareSerial gpsSerial(2);

#define GPS_RX 16
#define GPS_TX 17

void setup() {
  Serial.begin(115200);

  gpsSerial.begin(
    9600,
    SERIAL_8N1,
    GPS_RX,
    GPS_TX
  );

  Serial.println("Soldier GPS Monitoring System");
  Serial.println("Waiting for GPS signal...");
}

void loop() {
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
  }

  if (gps.location.isUpdated() &&
      gps.location.isValid()) {

    double latitude = gps.location.lat();
    double longitude = gps.location.lng();

    Serial.print("Latitude: ");
    Serial.println(latitude, 6);

    Serial.print("Longitude: ");
    Serial.println(longitude, 6);

    Serial.print("Google Maps Location: ");
    Serial.print("https://www.google.com/maps?q=");
    Serial.print(latitude, 6);
    Serial.print(",");
    Serial.println(longitude, 6);

    Serial.println("-------------------------");
  }

  delay(1000);
}

