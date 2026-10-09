
#define HEART_RATE_PIN 34

int sensorValue = 0;
int threshold = 2000;

unsigned long lastBeatTime = 0;
int bpm = 0;
bool beatDetected = false;

void setup() {
  Serial.begin(115200);
  pinMode(HEART_RATE_PIN, INPUT);

  Serial.println("Soldier Heart Rate Monitoring");
  Serial.println("Place finger on the sensor");
}

void loop() {
  sensorValue = analogRead(HEART_RATE_PIN);

  if (sensorValue > threshold && !beatDetected) {
    unsigned long currentTime = millis();
    unsigned long interval = currentTime - lastBeatTime;

    if (lastBeatTime != 0 &&
        interval >= 300 &&
        interval <= 2000) {
      bpm = 60000 / interval;

      Serial.print("Heart Rate: ");
      Serial.print(bpm);
      Serial.println(" BPM");
    }

    lastBeatTime = currentTime;
    beatDetected = true;
  }

  if (sensorValue < threshold) {
    beatDetected = false;
  }

  delay(10);
}
