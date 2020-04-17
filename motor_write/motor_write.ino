#define ENA 6 // right
#define IN1 8 // front
#define IN2 7
#define IN3 4
#define IN4 3 // front
#define ENB 5 // left

#define R1 19
#define R2 18
#define R3 17
#define L1 16
#define L2 15
#define L3 14

#define right_motor ENA
#define left_motor ENB

#define right_para 76
#define left_para 65

// error related
#define error_multi 5
// weight
#define Largest 12
#define Midium 3
#define Smallest 1

bool left_flag = 0;
bool right_flag = 0;

int error = 0;
int error_past = 0;

bool rl[6];

void Motor_Writing(int vR, int vL){
  // front and back
  if(vR >= 0){ // Right front
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  }
  else{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    vR = -vR;
  }

  if(vL >= 0){ // Right front
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }
  else{
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    vL = -vL;
  }

  analogWrite(right_motor, vR);
  analogWrite(left_motor, vL);
}

void Tracking(){
  
  rl[0] = digitalRead(R1);
  rl[1] = digitalRead(R2);
  rl[2] = digitalRead(R3);
  rl[3] = digitalRead(L1);
  rl[4] = digitalRead(L2);
  rl[5] = digitalRead(L3);

  int highs = 0;
  for(int i = 0; i < 6; i++){
    highs += rl[i];
  }

/*
  if(highs !=0){
    // flag out
    right_flag = 0;
    left_flag = 0;
  }
*/
  
  error = (1 * rl[3]) + (3 * rl[4]) + (5 * rl[5]) - (1 * rl[0]) - (3 * rl[1]) - (5 * rl[2]);
  /*
  if(rl[2]){
    right_flag = 1;
  }
  if(rl[5]){
    left_flag = 1;
  }
  if(highs >= 3){
    right_flag = 0;
    left_flag = 0;
  }

  if(right_flag){
    Motor_Writing(0, 0);
    while(digitalRead(R3)){
      Motor_Writing(right_para, 0);
    }
    Motor_Writing(0, 0);
    return;
  }
  else if(left_flag){
    Motor_Writing(0, 0);
    while(digitalRead(L3)){
      Motor_Writing(0, left_para);
    }
    Motor_Writing(0, 0);
    return;
  }
  */

/*
  if(highs == 0){
    if(right_flag){
      // direct right
      Motor_Writing(0, left_para + left_para/4);
      delay(500);
      right_flag = 0;
      Motor_Writing(0, 0);
      delay(500);
    }
    if(left_flag){
      // direct left
      Motor_Writing(right_para + right_para/4, 0);
      delay(500);
      left_flag = 0;
      Motor_Writing(0, 0);
      delay(500);
    }
    return;
  }
*/
  if (highs == 1){
    error *= 2;
  }

  int R = right_para + error * error_multi;
  int L = left_para - error * error_multi;

  Motor_Writing(R,L);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Motor_Writing(right_para, left_para);
  Tracking();
}
