#include <SoftwareSerial.h>

SoftwareSerial BT (10, 11);// 定義第10腳位接收// 第11腳位傳
String str = "";

void setup () {
  Serial.begin (9600);
  BT.begin(9600);
}

void loop() {
  if(Serial.available()){
    char c = Serial.read();
    BT.write(c);
  }
  if(BT.available()){
    char c = BT.read();
    str = str + c;
    Serial.print(c);
  } 
}
