#include <Event.h>
#include <Timer.h>

//aat speed 64 and delay 50 it covers 10 cm in 9 steps
#include <Arduino.h>
#include <EEPROM.h>

Timer t1;
Timer t2;
int event1;
int event2;
#define DR(x) digitalRead(x)
#define AW(x,y) analogWrite(x,y)

#define RF_PIN 6 
#define RB_PIN 5 
#define LF_PIN 9 
#define LB_PIN 10  
 
#define SCL_PIN 8
#define SCR_PIN 11
#define SR_PIN 12
#define SL_PIN 4

#define POWER_PIN 2

#define LINE 0

#define START_ADDRESS 700

int index;

void setup(){
  Serial.begin(9600);
  pinMode(RF_PIN,OUTPUT);
  pinMode(RB_PIN,OUTPUT);
  pinMode(LF_PIN,OUTPUT);
  pinMode(LB_PIN,OUTPUT);
  pinMode(13,OUTPUT);

  pinMode(SCL_PIN,INPUT);
  pinMode(SCR_PIN,INPUT);
  pinMode(SR_PIN,INPUT);
  pinMode(SL_PIN,INPUT);

  index = START_ADDRESS ;
}

void loop(){
  delay(5000);
  /*while (Serial.available()==0){}
  Serial.read();*/
  while(digitalRead(POWER_PIN)){
    //end point
    if (DR(SL_PIN) != LINE && DR(SCL_PIN) != LINE && DR(SCR_PIN) != LINE && DR(SR_PIN) != LINE){
      move180();  
    }
    //correction
    if ((DR(SCL_PIN) == LINE && DR(SCR_PIN) != LINE)){
      push();
      if (DR(SL_PIN) != LINE && DR(SCL_PIN) != LINE && DR(SCR_PIN) != LINE && DR(SR_PIN) != LINE){
        move180();  
      }else if (DR(SL_PIN) == LINE && DR(SCL_PIN) != LINE && DR(SCR_PIN) != LINE && DR(SR_PIN) == LINE){
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        stoop();
        Serial.println("finsih");
        while(1){}
      }else{
        correctionErrorToLeft();
      }
    }
    if (DR(SCL_PIN) != LINE && DR(SCR_PIN) == LINE){
      push();
      if (DR(SL_PIN) != LINE && DR(SCL_PIN) != LINE && DR(SCR_PIN) != LINE && DR(SR_PIN) != LINE){
        move180();  
      }else if (DR(SL_PIN) == LINE && DR(SCL_PIN) != LINE && DR(SCR_PIN) != LINE && DR(SR_PIN) == LINE){
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        stoop();
        Serial.println("finsih");
        while(1){}
      }else{
        correctionErrorToRight();
      }
    }
    if(DR(SCL_PIN) != LINE && DR(SCR_PIN) != LINE && DR(SR_PIN) != LINE && DR(SL_PIN) == LINE){
      correctionErrorToLeft();
    }    
    if(DR(SCL_PIN) != LINE && DR(SCR_PIN) != LINE && DR(SR_PIN) == LINE && DR(SL_PIN) != LINE){
      correctionErrorToRight();
    }
    //moving right
    if (DR(SCL_PIN) == LINE && DR(SCR_PIN) == LINE && DR(SR_PIN) == LINE){
      moveRight();
    }
    //moving straight
    if (DR(SL_PIN) != LINE && DR(SCL_PIN) == LINE && DR(SCR_PIN) == LINE && DR(SR_PIN) != LINE){
      moveStraight();  
    }
    //moving left
    if (DR(SCL_PIN) == LINE && DR(SCR_PIN) == LINE && DR(SL_PIN) == LINE){
      push();
      if ( DR(SCL_PIN) == LINE && DR(SCR_PIN) == LINE ){
        moveStraight(); 
      }else{
        moveLeft();  
      }
    }
  }
  /*while(digitalRead(SCR_PIN) == LINE && digitalRead(SCL_PIN)==LINE ){
    moveStraight();
    stoop();
    steep++;
    Serial.println(steep);
    delay(200);
  }*/
}



