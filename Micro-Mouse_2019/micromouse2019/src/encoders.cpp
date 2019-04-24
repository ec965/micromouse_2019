#include <Arduino.h>
#include "../inc/macros.h"
#include "../inc/encoders.h"
#include "../inc/motors.h"

int pulsesA_M1 = 0;
int pulsesA_M2 = 0;
int pulsesB_M1 = 0;
int pulsesB_M2 = 0;

void encA_M1_change(){
  pulsesA_M1++;
}

void encB_M1_change(){
  pulsesB_M1++;
}

void encA_M2_change(){
  pulsesA_M2++;
}

void encB_M2_change(){
  pulsesB_M2++;
}

void attachInterrupts(){
  attachInterrupt(digitalPinToInterrupt(encA_M1),encA_M1_change,CHANGE);
  attachInterrupt(digitalPinToInterrupt(encA_M2),encA_M2_change,CHANGE);
  attachInterrupt(digitalPinToInterrupt(encB_M1),encB_M1_change,CHANGE);
  attachInterrupt(digitalPinToInterrupt(encB_M2),encB_M2_change,CHANGE);
}

void encoder_reset(){
  pulsesA_M1 = 0;
  pulsesA_M2 = 0;
  pulsesB_M1 = 0;
  pulsesB_M2 = 0;
}
