int motor1[] = {3,1,2}; //en3,forward1,reverse2
int motor2[] = {4,5,6};//en4,forward5,reverse6
int speed = 0;
void forward();
void reverse();
void off();
//LED
int ledPin = 13;


void setup() {
  int i;
  for (i = 0; i<3; i++){
    pinMode (motor1[i], OUTPUT);
    pinMode (motor2[i],OUTPUT);
  }
  //LED
  pinMode(ledPin,OUTPUT);
}

void loop() {
  //LED
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
   speed = 50;
   analogWrite(motor1[0], speed);
   digitalWrite(motor1[1], HIGH);
   digitalWrite(motor1[2], LOW);
   analogWrite(motor2[0], speed);
   digitalWrite(motor2[1], HIGH);
   digitalWrite(motor2[2], LOW);
}

void reverse(){
  Serial.println("reverse");
  speed = 50;
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
