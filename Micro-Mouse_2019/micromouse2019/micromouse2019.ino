#include <Arduino.h>
#include "inc/macros.h"
#include "inc/encoders.h"
#include "inc/sensors.h"
#include "inc/setup.h"
#include "inc/motors.h"
#include "inc/PID.h"

IntervalTimer sys_update_timer;
IntervalTimer led_timer;
int ledState = LOW;
void led_blink(){
  if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(ledPin, ledState);
}

int speed_M1 = 50;
int speed_M2 = 50;
int error = 0;
void sys_update(){
  drive(check_sensors(),speed_M1);
  error = setspeed(speed_M1,speed_M2,error);
  //add more stuff that needs to be periodically updated
}

void setup() {
  Serial.begin(9600);
  setup_pinModes();
  attachInterrupts();
  sys_update_timer.begin(sys_update, 5000);
  led_timer.begin(led_blink,1000000);
  delay (3000);
}

void loop() {
}
