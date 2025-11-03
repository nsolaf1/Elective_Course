// Система сигнализации по температуре и освещённости

const int tempPin   = A0;
const int ldrPin    = A1;
const int ledPin    = 9;
const int buzzerPin = 8;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int tempValue = analogRead(tempPin);
  float voltage = tempValue * 5.0 / 1023.0;

  int lightValue = analogRead(ldrPin);

  Serial.print("Температура: "); Serial.print(tempC); Serial.print(" °C");
  Serial.print("  Свет: "); Serial.println(lightValue);

  if (tempC > 30 || lightValue < 300) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  delay(500);
}
