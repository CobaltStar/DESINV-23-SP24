
int red_LED_pin = 9;
int green_LED_pin = 10;
int blue_LED_pin = 11;

int red_button_pin = 2;
int green_button_pin = 3;
int blue_button_pin = 4;

int red_button_old = 0;
int green_button_old = 0;
int blue_button_old = 0;

int red_state = 0;
int green_state = 0;
int blue_state = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(red_LED_pin, OUTPUT);
  pinMode(red_button_pin, INPUT);

  pinMode(green_LED_pin, OUTPUT);
  pinMode(green_button_pin, INPUT);

  pinMode(blue_LED_pin, OUTPUT);
  pinMode(blue_button_pin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
//  analogWrite(red_LED_pin, 127);
//  analogWrite(blue_LED_pin, 127);
//  analogWrite(green_LED_pin, 127);

     int red_button_new = digitalRead(red_button_pin);
     int green_button_new = digitalRead(green_button_pin);
     int blue_button_new = digitalRead(blue_button_pin);

     // todo: use a for loop for this, or use a function

     if (red_button_old == 0 && red_button_new == 1) {
      if (red_state == 0) { 
        analogWrite(red_LED_pin, 0);
        red_state = 1;
      }
      else {
        analogWrite(red_LED_pin, 127);
        red_state = 0;
      }
     }

     if (green_button_old == 0 && green_button_new == 1) {
      if (green_state == 0) { 
        analogWrite(green_LED_pin, 0);
        green_state = 1;
      }
      else {
        analogWrite(green_LED_pin, 127);
        green_state = 0;
      }
     }

     if (blue_button_old == 0 && blue_button_new == 1) {
      if (blue_state == 0) { 
        analogWrite(blue_LED_pin, 0);
        blue_state = 1;
      }
      else {
        analogWrite(blue_LED_pin, 127);
        blue_state = 0;
      }
     }
     
     red_button_old = red_button_new;
     green_button_old = green_button_new;
     blue_button_old = blue_button_new;
     
   delay(100);
}
