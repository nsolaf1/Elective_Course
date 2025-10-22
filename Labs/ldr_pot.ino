// LDR + LED + Buzzer with Adjustable Threshold via Potentiometer

const int ldrPin     = A0; 
const int potPin     = A1; 
const int ledPin     = 9;  
const int buzzerPin  = 8;  


const int hysteresis = 15;  

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read sensors
  int lightValue = analogRead(ldrPin); 
  int potValue   = analogRead(potPin);  

  
  int threshold  = potValue;

  // Simple hysteresis: build a small “dead zone” around the threshold
  static bool alarmOn = false;
  int onPoint  = threshold - hysteresis;   // turn ON below this value (darker)
  int offPoint = threshold + hysteresis;   // turn OFF above this value (brighter)

  if (!alarmOn && lightValue < onPoint) {
    alarmOn = true;
  } else if (alarmOn && lightValue > offPoint) {
    alarmOn = false;
  }

  // Drive outputs
  if (alarmOn) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);     // continuous tone; for beeps use tone()
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  // Debug (optional): watch values in Serial Monitor
  // Serial.print("Light="); Serial.print(lightValue);
  // Serial.print("  Thr="); Serial.print(threshold);
  // Serial.print("  Alarm="); Serial.println(alarmOn);

  delay(20);
}
