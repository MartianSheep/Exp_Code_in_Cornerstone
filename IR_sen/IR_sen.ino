
#define test_IR 19

void setup() {
  // put your setup code here, to run once:
  pinMode(test_IR, INPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(test_IR));
  delay(500);
}
