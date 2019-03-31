//global variables
int receiver = A0;
int value;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(receiver,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(receiver);
  Serial.println(value);
  delay(1000);
}
