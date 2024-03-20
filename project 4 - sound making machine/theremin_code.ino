
// Pin definitions
#define SPEAKER_PIN 9
#define TRIGGER_PIN_1 10
#define ECHO_PIN_1 11
#define TRIGGER_PIN_2 5
#define ECHO_PIN_2 6


void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER_PIN_1, OUTPUT);
  pinMode(ECHO_PIN_1, INPUT);
  pinMode(TRIGGER_PIN_2, OUTPUT);
  pinMode(ECHO_PIN_2, INPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
}

void loop() {
  long duration1, distance1, duration2, distance2;
  
  // Measure distance from first ultrasonic sensor
  digitalWrite(TRIGGER_PIN_1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN_1, LOW);
  duration1 = pulseIn(ECHO_PIN_1, HIGH);
  distance1 = duration1 * 0.034 / 2;

  // Measure distance from second ultrasonic sensor
  digitalWrite(TRIGGER_PIN_2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN_2, LOW);
  duration2 = pulseIn(ECHO_PIN_2, HIGH);
  distance2 = duration2 * 0.034 / 2;

  // Map distance to frequency for pitch control
  int pitch = map(distance1, 0, 200, 20, 2000);

  // Map distance to amplitude for volume control
  int amplitude = map(distance2, 0, 200, 0, 255);

  // Output pitch and amplitude to serial monitor
  Serial.print("Pitch: ");
  Serial.print(pitch);
  Serial.print(" Hz\t");
  Serial.print("Amplitude: ");
  Serial.println(amplitude);

  // Generate sound based on pitch and amplitude
  tone(SPEAKER_PIN, pitch, amplitude);

  delay(50);
}
