#include <Keyboard.h>

// Define the pins for the buttons
const int BUTTON_PINS[] = {2, 3, 5, 6, 21, 20, 19, 18, 15, 14, 16, 10}; 
const char KEY_BINDINGS[] = {'s', 'a', 'd', 'w', 'j', 'k', 'u', 'i', 'o', 'l', ';', 'p'}; // Corresponding key bindings

// Number of buttons
#define NUM_BUTTONS 12

// Struct to hold button information
struct Button {
  int pin;
  char key;
  bool state;
};

// Array of Button structs
Button buttons[NUM_BUTTONS];

void setup() {
  // Initialize the Keyboard library
  Keyboard.begin();

  // Initialize each button pin as input with pull-up resistor
  for (int i = 0; i < NUM_BUTTONS; i++) {
    buttons[i].pin = BUTTON_PINS[i];
    buttons[i].key = KEY_BINDINGS[i];
    buttons[i].state = false;
    pinMode(buttons[i].pin, INPUT_PULLUP);
  }  
}

void loop() {
  // Check the state of each button
  for (int i = 0; i < NUM_BUTTONS; i++) {
    bool currentState = digitalRead(buttons[i].pin);
    if (currentState != buttons[i].state) {
      // Button state changed, update and send corresponding key press/release
      buttons[i].state = currentState;
      if (currentState == LOW) {
        Keyboard.press(buttons[i].key); // Press the key
      } else {
        Keyboard.release(buttons[i].key); // Release the key
      }
    }
  }
}
