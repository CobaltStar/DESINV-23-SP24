// Include the library
#include <L298N.h>

// Pin definition
const unsigned int IN1 = 7;
const unsigned int IN2 = 8;
const unsigned int EN = 9;

// Create one motor instance
L298N motor(EN, IN1, IN2);

void setup()
{
  // Set initial speed
  motor.setSpeed(70);
}

// Function prototypes
void moveForward();
void moveBackward();

void loop() {
  // Move forward
  moveForward();
  delay(random(200, 1000)); // Random delay between 1 and 3 seconds

  // Move backward
  moveBackward();
  delay(random(200, 1000)); // Random delay between 1 and 3 seconds
}

// function for forward locomotion
void moveForward() {
  motor.forward();
  motor.setSpeed(120);
  
}

// function for backward locomotion
void moveBackward() {
  motor.backward();
  motor.setSpeed(120);
}
