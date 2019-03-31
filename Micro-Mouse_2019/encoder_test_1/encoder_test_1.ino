//Pins
int motor1[] = {3,2,1}; //en3,forward2,reverse1
int motor2[] = {4,5,6};//en4,forward5,reverse6
int encoderA_M1 = A7;
int encoderB_M1 = A6;
int encoderA_M2 = A8;
int encoderB_M2 = A9;
int ledPin = 13;

//motor variables and functions
int speed = 0;
void forward();
void reverse();
void off();

//encoder varibles and functions
//variables to track pulses
int pulses_M1 = 0;
int pulses_M2 = 0;
//variable to print pulses when pulse changes
int pulsesChanged_M1 = 0;
int pulsesChanged_M2 = 0;
//function to print pulses to serial monitor
void pulsePrint(int,int);
//encoder change code (x4)
void A_CHANGE_M1();
void B_CHANGE_M1();
void A_CHANGE_M2();
void B_CHANGE_M2();

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
  pinMode(encoderB_M1, INPUT);
  pinMode(encoderA_M2, INPUT);
  pinMode(encoderB_M2, INPUT);
  //encoder interrupt code
  attachInterrupt(digitalPinToInterrupt(encoderA_M1),A_CHANGE_M1,CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderB_M1),B_CHANGE_M1,CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderA_M2),A_CHANGE_M2,CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderB_M2),B_CHANGE_M2,CHANGE);
}

void loop() {
  pulsePrint(pulsesChanged_M1,pulses_M1);
  pulsePrint(pulsesChanged_M2,pulses_M2);
  digitalWrite(ledPin,HIGH);
  forward();
  delay(3000);
  digitalWrite(ledPin,LOW);
  off();
  delay(2000);
  digitalWrite(ledPin,HIGH);
  reverse();
  delay(3000);
  digitalWrite(ledPin,LOW);
  off();
  delay(2000);
}

void forward(){
   Serial.println("forward");
   speed = 255;
   analogWrite(motor1[0], speed);
   digitalWrite(motor1[1], HIGH);
   digitalWrite(motor1[2], LOW);
   analogWrite(motor2[0], speed);
   digitalWrite(motor2[1], HIGH);
   digitalWrite(motor2[2], LOW);
}

void reverse(){
  Serial.println("reverse");
  speed = 255;
  analogWrite(motor1[0], speed);
  digitalWrite(motor1[1], LOW);
  digitalWrite(motor1[2], HIGH);
  analogWrite(motor2[0], speed);
  digitalWrite(motor2[1], LOW);
  digitalWrite(motor2[2], HIGH);
}

void off(){
  Serial.println("off");
  speed = 0;
  analogWrite(motor1[0],speed);
  digitalWrite(motor1[1], LOW);
  digitalWrite(motor1[2], LOW);
  analogWrite(motor2[0],speed);
  digitalWrite(motor2[1], LOW);
  digitalWrite(motor2[2], LOW);
}

void A_CHANGE_M1(){
  if( digitalRead(encoderB_M1) == 0 ) {
    if ( digitalRead(encoderA_M1) == 0 ) {
      // A fell, B is low
      pulses_M1--; // moving reverse
    } 
    else {
      // A rose, B is low
      pulses_M1++; // moving forward
    }
  }
  else {
    if ( digitalRead(encoderA_M1) == 0 ) {
      // B fell, A is high
      pulses_M1++; // moving reverse
    } else {
      // B rose, A is high
      pulses_M1--; // moving forward
    }
  }
  pulsesChanged_M1 = 1;
}

void B_CHANGE_M1(){
  if ( digitalRead(encoderA_M1) == 0 ) {
    if ( digitalRead(encoderB_M1) == 0 ) {
      // B fell, A is low
      pulses_M1++; // moving forward
    } else {
      // B rose, A is low
      pulses_M1--; // moving reverse
    }
 } 
 else {
    if ( digitalRead(encoderB_M1) == 0 ) {
      // B fell, A is high
      pulses_M1--; // moving reverse
    } else {
      // B rose, A is high
      pulses_M1++; // moving forward
    }
  }
  pulsesChanged_M1 = 1;
}

void A_CHANGE_M2(){
  if( digitalRead(encoderB_M2) == 0 ) {
    if ( digitalRead(encoderA_M2) == 0 ) {
      // A fell, B is low
      pulses_M2--; // moving reverse
    } 
    else {
      // A rose, B is low
      pulses_M2++; // moving forward
    }
  }
  else {
    if ( digitalRead(encoderA_M2) == 0 ) {
      // B fell, A is high
      pulses_M2++; // moving reverse
    } else {
      // B rose, A is high
      pulses_M2--; // moving forward
    }
  }
  pulsesChanged_M2 = 1;
}

void B_CHANGE_M2(){
  if ( digitalRead(encoderA_M2) == 0 ) {
    if ( digitalRead(encoderB_M2) == 0 ) {
      // B fell, A is low
      pulses_M2++; // moving forward
    } else {
      // B rose, A is low
      pulses_M2--; // moving reverse
    }
 } 
 else {
    if ( digitalRead(encoderB_M2) == 0 ) {
      // B fell, A is high
      pulses_M2--; // moving reverse
    } else {
      // B rose, A is high
      pulses_M2++; // moving forward
    }
  }
  pulsesChanged_M2 = 1;
}

void pulsePrint(int pulsesChanged,int pulses){ //prints pulses
    if (pulsesChanged != 0) {
    pulsesChanged = 0;
    Serial.println(pulses);
  }
}
