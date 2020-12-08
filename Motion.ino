#define STRAIGHT_SPEED 127
#define TURN_SPEED 100
#define STRAIGHT_DELAY 75
#define TURN_DELAY 75
#define TURN_CORRECTION_SPEED 127
#define CORRECTION_DELAY 25
#define PUSH_DELAY 50
#define PUSH_SPEED 127 
#define TURN_PUSH_SPEED 100
#define TURN_PUSH_DELAY 30
#define REST_DELAY 20

void push(){
  AW(RF_PIN,100);
  AW(LF_PIN,100);
  AW(RB_PIN,0);
  AW(LB_PIN,0);
  delay(20);
  stoop();
  delay(REST_DELAY);
}

void moveStraight(){
  AW(RF_PIN,STRAIGHT_SPEED);
  AW(LF_PIN,STRAIGHT_SPEED);
  AW(RB_PIN,0);
  AW(LB_PIN,0);
  /*while(DR(SL_PIN) != LINE && DR(SCL_PIN) == LINE && DR(SCR_PIN) == LINE && DR(SR_PIN) != LINE){
    if(DR(SCL_PIN) == LINE && DR(SCR_PIN) != LINE){
      correctionErrorToLeft();
    }else if(DR(SCL_PIN) != LINE && DR(SCR_PIN) == LINE){
      correctionErrorToRight();
    }
  }*/
  while (DR(SL_PIN) != LINE && DR(SCL_PIN) == LINE && DR(SCR_PIN) == LINE && DR(SR_PIN) != LINE){}
  stoop();
}


void moveRight(){
  /*
   * s1 right sensor out of line
   * s2 right sensor in the line
   * s3 sensor center right and left in line
   */
  bool s1,s2,s3,s4;
  s1=s2=s3=s4=false;
  //the push
  AW (RF_PIN,TURN_PUSH_SPEED);
  AW (LF_PIN,TURN_PUSH_SPEED);
  AW (RB_PIN,0);
  AW (LB_PIN,0);
  while (DR(SR_PIN)==LINE){};
  stoop();
  delay(REST_DELAY);
  AW (RF_PIN,0);
  AW (LF_PIN,TURN_SPEED);
  AW (RB_PIN,0);
  AW (LB_PIN,0);
  do {
    if (!s1){
      if (DR( SR_PIN )!= LINE)
        s1=true;
    }
    if (s1 && !s2){
      if ( DR(SR_PIN)==LINE )
        s2=true;
    }
    if (s1 && s2 && !s3){
      if (DR(SCR_PIN)==LINE )
        s3=true;
    }
    if (s1 && s2 && s3 &&!s4){
      if (DR(SCL_PIN)==LINE )
        s4=true;
    }
  }while( !(s1 &&s2&&s3 &&s4) );
  stoop();
  delay(REST_DELAY);
}

void moveLeft(){
  /*
   * s1 right sensor out of line
   * s2 right sensor in the line
   * s3 sensor center right and left in line
   */
  bool s1,s2,s3,s4;
  s1=s2=s3=s4=false;
  //the push
  AW (RF_PIN,TURN_PUSH_SPEED);
  AW (LF_PIN,TURN_PUSH_SPEED);
  AW (RB_PIN,0);
  AW (LB_PIN,0);
  while (DR(SL_PIN)==LINE){};
  stoop();
  delay(REST_DELAY);
  AW (RF_PIN,TURN_SPEED);
  AW (LF_PIN,0);
  AW (RB_PIN,0);
  AW (LB_PIN,0);
  do {
    if (!s1){
      if (DR( SL_PIN )!= LINE)
        s1=true;
    }
    if (s1 && !s2){
      if ( DR(SL_PIN)==LINE )
        s2=true;
    }
    if (s1 && s2 &&!s3){
      if (DR(SCL_PIN)==LINE )
        s3=true;
    }
    if (s1 && s2 && s3 && !s4){
      if (DR(SCR_PIN)==LINE )
        s4=true;
    }
  }while( !(s1 &&s2&&s3 &&s4) );
  stoop();
  delay(REST_DELAY);
}

void stoop(){
  AW(RB_PIN,0);
  AW(RF_PIN,0);
  AW(LB_PIN,0);
  AW(LF_PIN,0);
}

void move180(){
 /* bool s1,s2,s3,s4;
  s1=s2=s3=s4=false;
  analogWrite(RB_PIN,TURN_SPEED);
  analogWrite(LF_PIN,TURN_SPEED);
  analogWrite(RF_PIN,0);
  analogWrite(LB_PIN,0); 
  do {
    if (!s1){
      if (digitalRead(SR_PIN)!=LINE )
        s1=true;
    }
    if (s1&&!s2){
      if (digitalRead(SR_PIN)==LINE)
        s2=true;
    }
    if (s1&&s2&&!s3){
      if (digitalRead(SCR_PIN)==LINE){
        s3=true;
      }
    }
    if (s1&&s2&&s3&&!s4){
      if (digitalRead(SCL_PIN)==LINE){
        s4=true;
      }
    }
  }while(! ( s1 && s2 && s3 && s4 ));
  stoop();
  delay(REST_DELAY);
  */
  bool s1,s2,s3,s4;
  s1=s2=s3=s4=false;
  do {
    analogWrite(RB_PIN,TURN_SPEED);
    analogWrite(RF_PIN,0);
    analogWrite(LB_PIN,0);
    analogWrite(LF_PIN,TURN_SPEED);
    delay(TURN_DELAY);
    if (!s1){
      if (digitalRead(SR_PIN)==LINE )
        s1=true;
    }
    if (s1&&!s2){
      if (digitalRead(SR_PIN)!=LINE)
        s2=true;
    }
    if (s1&&s2&&!s3){
      if (digitalRead(SCR_PIN)==LINE){
        s3=true;
      }
    }
    if (s1&&s2&&s3&&!s4){
      if (digitalRead(SCL_PIN)==LINE){
        s4=true;
      }
    }
    stoop();
    delay(50);
    /*Serial.print("s1");
    Serial.print(s1);
    Serial.print("s2");
    Serial.print(s2);
    Serial.print("s3");
    Serial.print(s3);
    Serial.print("s4");
    Serial.print(s4);
    Serial.println("");*/
  }while(!s1||!s2||!s3||!s4);
  stoop();
  delay(20);







  
}
