// --- Pins ---
const int pumpPin    = 7;    // MOSFET gate
const int sensorPin  = A0;   // water level sensor
const int buzzerPin  = 8;    // buzzer
const int enablePin  = 3;    // switch (INPUT_PULLUP)
const int ledOnPin   = 9;    // Pump ON LED
const int ledOffPin  = 10;   // Pump OFF LED

// --- Thresholds (tuned for sensor) ---
const int DRY_THRESHOLD  = 120;
const int WET_THRESHOLD  = 560;

bool pumpOn = false;
bool sensorWet = false;

void setup() {
pinMode(pumpPin, OUTPUT);
pinMode(buzzerPin, OUTPUT);
pinMode(enablePin, INPUT_PULLUP);
pinMode(ledOnPin, OUTPUT);
pinMode(ledOffPin, OUTPUT);

Serial.begin(9600);
}

void setPump(bool on) {
digitalWrite(pumpPin, on ? HIGH : LOW);
digitalWrite(ledOnPin, on ? HIGH : LOW);
digitalWrite(ledOffPin, on ? LOW : HIGH);
pumpOn = on;
}

void loop() {
bool enabled = (digitalRead(enablePin) == LOW);
int adc = analogRead(sensorPin);

if (!sensorWet && adc > WET_THRESHOLD) sensorWet = true;
if (sensorWet && adc < DRY_THRESHOLD) sensorWet = false;

if (!enabled) {
setPump(false);
digitalWrite(buzzerPin, LOW);
} else {
if (sensorWet) {
setPump(true);
digitalWrite(buzzerPin, LOW);
} else {
setPump(false);
digitalWrite(buzzerPin, HIGH);
}
}

Serial.print("EN="); Serial.print(enabled ? "ON" : "OFF");
Serial.print("  ADC="); Serial.print(adc);
Serial.print("  Wet="); Serial.print(sensorWet ? "Yes" : "No");
Serial.print("  Pump="); Serial.println(pumpOn ? "ON" : "OFF");
}
