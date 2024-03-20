#include <MozziGuts.h>
#include <Oscil.h>
#include <mozzi_analog.h>
#include <mozzi_rand.h>

// Pin definitions
#define SPEAKER_PIN 9
#define TRIGGER_PIN_1 10
#define ECHO_PIN_1 11
#define TRIGGER_PIN_2 5
#define ECHO_PIN_2 6


#define AUDIO_OUT 9

#include <tables/sin1024_int8.h> // sine table for oscillator

// Initialize sine wave oscillator
Oscil<SIN1024_NUM_CELLS, AUDIO_RATE> sineWave;

void setup() {
  startMozzi(CONTROL_RATE); // Start Mozzi
  sineWave.setFreq(440);    // Set initial frequency of the sine wave (440 Hz)
  pinMode(TRIGGER_PIN_1, OUTPUT);
  pinMode(ECHO_PIN_1, INPUT);
  pinMode(TRIGGER_PIN_2, OUTPUT);
  pinMode(ECHO_PIN_2, INPUT);

  // Set up audio output pin
  audioHook();
}

// to convey the volume level from updateControl() to updateAudio()
byte volume;

void updateControl() {
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
//  int pitch = map(distance1, 0, 200, 20, 2000);
  int pitch = map(distance1, 0, 200, 80, 600);
  

  // Map distance to amplitude for volume control
  int volume = map(distance2, 0, 200, 0, 255);

  // Update sine wave parameters
  sineWave.setFreq(pitch);
}

int updateAudio(){
// TODO: Code for amplitude modulation
//  return ((int) sineWave.next() * volume)>>8;

  return ((int) sineWave.next()); 
} 

void loop() {
  audioHook();
}
