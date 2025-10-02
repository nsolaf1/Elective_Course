// Simple Sound & Light Alarm

const int ledPin = 9;      // LED
const int buzzerPin = 8;   // Buzzer
const int armBtn = 10;      // Arm/Disarm button
const int sensorBtn = 11;   // Sensor button
const int potPin = A0;     // Potentiometer

bool armed = false;        

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(armBtn, INPUT_PULLUP);    
  pinMode(sensorBtn, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(armBtn) == LOW) {
    armed = !armed;          
    delay(300);              
  }

 
  if (armed && digitalRead(sensorBtn) == LOW) {
    int timeMs = map(analogRead(potPin), 0, 1023, 1000, 5000); 
    runAlarm(timeMs);
  }
}

void runAlarm(int duration) {
  unsigned long start = millis();
  while (millis() - start < duration) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    delay(200);
  }
}


