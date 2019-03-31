//global variables
int R_1 = A5;
int R_2 = A4;
int R_3 = A3;
int R_4 = A2;
int value;

void setup() {
  Serial.begin(9600);
  pinMode(R_1,INPUT);
  pinMode(R_2,INPUT);
  pinMode(R_3,INPUT);
  pinMode(R_4,INPUT);
}

void loop() {
  value = analogRead(R_1);
  Serial.print("R1: ");
  Serial.println(value);
  value = analogRead(R_2);
  Serial.print("R2: ");
  Serial.println(value);
  value = analogRead(R_3);
  Serial.print("R3: ");
  Serial.println(value);
  value = analogRead(R_4);
  Serial.print("R4: ");
  Serial.println(value);
  Serial.println("----------------");
  delay(1000);
}
