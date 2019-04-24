#include <Arduino.h>
#include "../inc/encoders.h"
#include "../inc/PID.h"
#include "../inc/macros.h"

extern int pulsesA_M1;
extern int pulsesA_M2;
extern int pulsesB_M1;
extern int pulsesB_M2;


void setspeed(int speed_M1,int speed_M2){
  int next_speed_M2;
  int error1 = PIDerror_A();
  next_speed_M2 = speed_M2 + error1;
  analogWrite(M2en, next_speed_M2);
  Serial.print("speed_M2: ");
  Serial.println(next_speed_M2);
  Serial.print("speed_M1: ");
  Serial.println(speed_M1);
}

int PIDerror_A(){
  int error = pulsesA_M1 - pulsesA_M2;
  Serial.print("plusesA_M1: ");
  Serial.println(pulsesA_M1);
  Serial.print("plusesA_M2: ");
  Serial.println(pulsesA_M2);
  Serial.print("error: ");
  Serial.println(error);
  return error;
}

int PIDerror_B(){
  int error = pulsesB_M2-pulsesB_M1;
  Serial.print("plusesB_M1: ");
  Serial.println(pulsesA_M1);
  Serial.print("plusesB_M2: ");
  Serial.println(pulsesA_M2);
  Serial.print("error: ");
  Serial.println(error);
  // encoder_reset();
  return error;
}
