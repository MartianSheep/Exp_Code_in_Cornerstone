#include <SoftwareSerial.h>

#define ENA 14 // right
#define IN1 15 // front
#define IN2 16
#define IN3 17
#define IN4 18 // front
#define ENB 19 // left

#define right_motor ENA
#define left_motor ENB

#define right_para 200
#define left_para 200

#define delay_time 50

SoftwareSerial BT (8, 2);// 定義第8腳位接收// 第2腳位傳 // 沒有要傳的意思

void setup() {
  // put your setup code here, to run once:
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin (9600);
  BT.begin(9600);
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
  right_stop();
  left_stop();
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

void back(int t){
  motor_init();
  right_back();
  left_back();
  delay(t);
  stopping();
}

void loop() {
  // put your main code here, to run repeatedly:
  

  if(BT.available()){
    char c = BT.read();
    Serial.print(c);
    if(c == 'W' || c == 'w'){
      front(delay_time);
    }
    else if(c == 'A' || c == 'a'){
      left(delay_time);
    }
    else if(c == 'D' || c == 'd'){
      right(delay_time);
    }
    else if(c == 'S' || c == 's'){
      back(delay_time);
    }
  } 

}
