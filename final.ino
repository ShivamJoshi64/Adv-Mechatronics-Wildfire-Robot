#include <Servo.h>

#define enPin 8

#define lDir 5
#define lStep 2

#define rDir 6
#define rStep 3

int stepDelay = 700;
bool containerOpen = false;

Servo lid;

void step(bool dir, int dirPin, int stepPin){
  digitalWrite(dirPin, dir);
  
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(stepDelay);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(stepDelay);

}

void front(int distance){
  int steps = 300*distance/23;
  
  for (int i = 0; i<steps; i++){
    step(true, lDir, lStep);
    step(true, rDir, rStep);
  }
}

void back(int distance){
  int steps = 300*distance/23;
  
  for (int i = 0; i<steps; i++){
    step(false, lDir, lStep);
    step(false, rDir, rStep);
  }
}

void left(int angle){
  int steps = 300*angle/23;
  
  for (int i = 0; i<steps; i++){
    step(true, lDir, lStep);
    step(true, rDir, rStep);
  }
}

void right(int angle){
  int steps = 300*angle/23;
  
  for (int i = 0; i<steps; i++){
    step(true, lDir, lStep);
    step(true, rDir, rStep);
  }
}

void openContainer(){
  lid.write(100);
}

void closeContainer(){
  lid.write(10);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  lid.attach(9);
  
  pinMode(enPin, OUTPUT);
  
  pinMode(lStep, OUTPUT);
  pinMode(lDir, OUTPUT);
  pinMode(rStep, OUTPUT);
  pinMode(rDir, OUTPUT);

  digitalWrite(enPin, LOW); //pulled LOW to enable drivers
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    char data = Serial.read();
    if (data == '1') front(40);
    else if (data == '2') left(5);
    else if (data == '3') right(5);
    else if (data == '4') back(40);
    else if (data == '5') openContainer();
    else if (data == '6') closeContainer();
  }
}
