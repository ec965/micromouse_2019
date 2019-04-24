#include <PID_v1.h>
//M1 is right motor, M2 is left motor
//Pins
int motor1[] = {3,1,2}; //en3,forward1,reverse2
int motor2[] = {4,5,6};//en4,forward5,reverse6
int encoderA_M1 = A7;
int encoderB_M1 = A6;
int encoderA_M2 = A8;
int encoderB_M2 = A9;
int ledPin = 13;

//motor variables and functions
void forward();
void reverse();
void off();

//speed variables
double speed_M1;
double speed_M2;
double new_speed_M2;

//encoder varibles and functions
//variables to track pulses for PID
double pulses_M1;
double pulses_M2;
//encoder change code (x1)
void A_CHANGE_M1();
void A_CHANGE_M2();

//trying to match speed of M2 to speed of M1
PID encPID = PID(&pulses_M2, &new_speed_M2, &pulses_M1 , .5, 0, 0,DIRECT);

void setup() {
  Serial.begin(9600);
  //Motors
  int i;
  for (i = 0; i<3; i++){
    pinMode (motor1[i], OUTPUT);
    pinMode (motor2[i],OUTPUT);
  }
  //LED
  pinMode(ledPin,OUTPUT);
  //encoder
  pinMode(encoderA_M1, INPUT);
  pinMode(encoderA_M2, INPUT);
  //encoder interrupt code
  attachInterrupt(digitalPinToInterrupt(encoderA_M1),A_CHANGE_M1,CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderA_M2),A_CHANGE_M2,CHANGE);
  encPID.SetMode(AUTOMATIC);
}

void loop() {
  off();
  digitalWrite(ledPin,LOW);
  Serial.println("off");
  delay(1000);

  digitalWrite(ledPin,HIGH);
  forward();
  delay(3000);

  Serial.print("PulsesM1: "); Serial.println(pulses_M1);
  Serial.print("PulsesM2: "); Serial.println(pulses_M2);
  Serial.print("new_pulses_M2: "); Serial.println(new_pulses_M2);
  Serial.print("---------------------------------------------");
}

void forward(){
   Serial.println("forward");
   speed_M1 = 100;
   speed_M2 = new_speed_M2;
   analogWrite(motor1[0], speed_M1);
   digitalWrite(motor1[1], HIGH);
   digitalWrite(motor1[2], LOW);
   analogWrite(motor2[0], speed_M2);
   digitalWrite(motor2[1], HIGH);
   digitalWrite(motor2[2], LOW);
}

void reverse(){
  Serial.println("reverse");
  speed_M1 = 100;
  speed_M2 = new_speed_M2;
  analogWrite(motor1[0], speed_M1);
  digitalWrite(motor1[1], LOW);
  digitalWrite(motor1[2], HIGH);
  analogWrite(motor2[0], speed_M2);
  digitalWrite(motor2[1], LOW);
  digitalWrite(motor2[2], HIGH);
}

void off(){
  Serial.println("off");
  speed_M1 = speed_M2 = 0;
  analogWrite(motor1[0],speed_M1);
  digitalWrite(motor1[1], LOW);
  digitalWrite(motor1[2], LOW);
  analogWrite(motor2[0],speed_M2);
  digitalWrite(motor2[1], LOW);
  digitalWrite(motor2[2], LOW);
}

void A_CHANGE_M1(){
  pulses_M1++; // moving forward
  encPID.compute();
}

void A_CHANGE_M2(){
  pulses_M2++; // moving forward
}
