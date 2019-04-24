#include "../inc/macros.h"
#include "../inc/setup.h"
#include<Arduino.h>

void ledSetup(){
  pinMode(ledPin, OUTPUT);
}

void motorSetup(){
  pinMode(M1en,OUTPUT);
  pinMode(M1forward,OUTPUT);
  pinMode(M1reverse,OUTPUT);
  pinMode(M2en,OUTPUT);
  pinMode(M1forward,OUTPUT);
  pinMode(M2reverse,OUTPUT);
}

void encoderSetup(){
  pinMode(encA_M1, INPUT);
  pinMode(encB_M1, INPUT);
  pinMode(encA_M2, INPUT);
  pinMode(encB_M2, INPUT);
}

void recieverSetup(){
  pinMode(reciever_L, INPUT);
  pinMode(reciever_FL, INPUT);
  pinMode(reciever_FR, INPUT);
  pinMode(reciever_R, INPUT);
}

void setup_pinModes(){
  ledSetup();
  motorSetup();
  encoderSetup();
  recieverSetup();
}
