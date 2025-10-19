// LDR + LED + Buzzer Alarm System

const int ldrPin = A0;
const int buzzerPin = 8;
const int ledPin = 9;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightValue = analogRead(ldrPin); 
  Serial.println(lightValue);

 
  if (lightValue < 400) { 
    
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  } else {
  
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  delay(200);
}
