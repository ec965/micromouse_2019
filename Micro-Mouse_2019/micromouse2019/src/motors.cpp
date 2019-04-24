#include <Arduino.h>
#include "../inc/macros.h"
#include "../inc/encoders.h"
#include "../inc/motors.h"
#include "../inc/sensors.h"

// void turn_right(int speed_M1,int speed_M2){
//   analogWrite(M1en, speed_M1);
//   analogWrite(M2en, speed_M2);
//   digitalWrite(M1forward, HIGH);
//   digitalWrite(M1reverse, LOW);
//   digitalWrite(M2forward, LOW);
//   digitalWrite(M2reverse, HIGH);
// }
void forward(int speed){
  stop();
  analogWrite(M1en, speed);
  analogWrite(M2en, speed);
  digitalWrite(M1forward, HIGH);
  digitalWrite(M1reverse, LOW);
  digitalWrite(M2forward, HIGH);
  digitalWrite(M2reverse, LOW);
}

void reverse(int speed){
  stop();
  analogWrite(M1en, speed);
  analogWrite(M2en, speed);
  digitalWrite(M1forward, LOW);
  digitalWrite(M1reverse, HIGH);
  digitalWrite(M2forward, LOW);
  digitalWrite(M2reverse, HIGH);
}
void stop(){
  analogWrite(M1en, 0);
  analogWrite(M2en, 0);
  digitalWrite(M1forward, LOW);
  digitalWrite(M1reverse, LOW);
  digitalWrite(M2forward, LOW);
  digitalWrite(M2reverse, LOW);
}

void right_turn(int speed){
  stop();
  analogWrite(M1en, speed);
  analogWrite(M2en, speed);
  digitalWrite(M1forward, HIGH);
  digitalWrite(M1reverse, LOW);
  digitalWrite(M2forward, LOW);
  digitalWrite(M2reverse, HIGH);
}

void left_turn(int speed){
  stop();
  analogWrite(M1en, speed);
  analogWrite(M2en, speed);
  digitalWrite(M1forward, LOW);
  digitalWrite(M1reverse, HIGH);
  digitalWrite(M2forward, HIGH);
  digitalWrite(M2reverse, LOW);
}

void speedup(int speed, int direction){
  int speed_up = correct_direction();//correct direction is in sensors.cpp
  if (direction == 1){
    if (speed_up == 2){
      analogWrite(M2en, speed+10);
      Serial.print("speed_up_M2: ");
      Serial.println(speed);
    }
    if (speed_up ==4){
      analogWrite(M1en, speed+10);
      Serial.print("speed_up_M1: ");
      Serial.println(speed);
    }
  }
}

void drive(int direction,int speed){
  if(direction == 0){
    stop();
  }
  if(direction != 0){
    forward(speed);
  }
}
