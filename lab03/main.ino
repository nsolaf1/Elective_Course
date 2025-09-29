//led Dimmer Overview Class

const int ledPin = 6;   // LED on PWM pin 9
const int potPin = A0;  // Potentiometer middle pin to A0

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the potentiometer (0..1023)
  int sensorValue = analogRead(potPin);

  // Convert to PWM range (0..255)
  int brightness = map(sensorValue, 0, 1023, 0, 255);

  // Set LED brightness
  analogWrite(ledPin, brightness);

  // Small delay to stabilize reading
  // Optional
  delay(10);
}
