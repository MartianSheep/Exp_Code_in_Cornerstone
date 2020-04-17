#define ENA 14 // right
#define IN1 15 // front
#define IN2 16
#define IN3 17
#define IN4 18 // front
#define ENB 19 // left

#define right_motor ENA
#define left_motor ENB

#define right_para 255
#define left_para 128

void setup() {
  // put your setup code here, to run once:
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void motor_init(){
  analogWrite(right_motor, right_para);
  analogWrite(left_motor, left_para);
}

void right_front(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}
void right_stop(){
  analogWrite(right_motor, 0);
}
void right_back(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void left_front(){
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void left_stop(){
  analogWrite(left_motor, 0);
}
void left_back(){
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stopping(){
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void front(int t){
  motor_init();
  right_front();
  left_front();
  delay(t);
  stopping();
}

void right(int t){
  motor_init();
  right_stop();
  left_front();
  delay(t);
  stopping();
}

void left(int t){
  motor_init();
  right_front();
  left_stop();
  delay(t);
  stopping();
}

void loop() {
  // put your main code here, to run repeatedly
  
}
