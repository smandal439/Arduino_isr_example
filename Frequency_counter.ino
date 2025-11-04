volatile unsigned long pulseCount = 0;
unsigned long lastTime = 0;
unsigned long interval = 1000;  // Measure over 1000 ms (1 second)
float frequency = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);            // Input signal to pin 2
  attachInterrupt(digitalPinToInterrupt(2), countPulse, RISING);  // Count rising edges
  lastTime = millis();
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - lastTime >= interval) {
    detachInterrupt(digitalPinToInterrupt(2));  // Stop counting during calculation

    frequency = (pulseCount * (1000.0 / interval));  // Pulses per second (Hz)
    
    Serial.print("Frequency: ");
    Serial.print(frequency);
    Serial.println(" Hz");

    pulseCount = 0;  // Reset pulse count for next interval
    lastTime = currentTime;

    attachInterrupt(digitalPinToInterrupt(2), countPulse, RISING);  // Resume counting
  }
}

void countPulse() {
  pulseCount++;  // Increment pulse count on each rising edge
}
