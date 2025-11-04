
#define LED_PIN 13
#define BUTTON_PIN 2

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), toggleLED, FALLING);
}

void loop() {
  // Main loop keeps running
}

void toggleLED() {
  digitalWrite(LED_PIN, !digitalRead(LED_PIN)); // Toggle LED state
}
