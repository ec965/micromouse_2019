#include <Arduino.h>
#include "../inc/macros.h"
#include "../inc/sensors.h"

//directions:
//1 - straight
//2 - right
//4 - left
//6 - can turn either way
//0 - dead end, turn around
//if you end up connecting the emiiters to digital pins then put delays on the recivers here

//closer is a higher number, farther is a lower number
#define Lmax 109
#define Rmax 90
#define FLmax 80
#define FRmax 170

int check_sensors(){
  int direction = 0;
  int value_L;
  int value_FL;
  int value_FR;
  int value_R;
  value_L = analogRead(reciever_L);
  value_FL = analogRead(reciever_FL);
  value_R = analogRead(reciever_R);
  value_FR = analogRead(reciever_FR);

  Serial.print("R_Left: ");
  Serial.println(value_L);
  Serial.print("R_FrontLeft: ");
  Serial.println(value_FL);
  Serial.print("R_Right: ");
  Serial.println(value_R);
  Serial.print("R_FrontRight: ");
  Serial.println(value_FR);

  if (value_L<=Lmax || value_R<=Rmax){
    direction = 1;
  }
  else if (value_FR <= FRmax){
    direction = 2;
    if (value_FL <= FLmax){ //check if can go both ways
      direction = 6;
    }
  }
  else if (value_FL <= FLmax){
    direction = 4;
  }
  Serial.print("direction: ");
  Serial.println(direction);
  return direction;
}

int correct_direction(){
  int value_FL = analogRead(reciever_FL);
  int value_FR = analogRead(reciever_FR);
  int correction = 0;
  if (value_FL > FLmax){
    correction = 2; //2 is rise speed of left wheel
  }
  if (value_FR > FRmax){
    correction = 4; //4 is rise speed of right wheel
  }
  return correction;
}
