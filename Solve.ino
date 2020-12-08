
void correctionErrorToRight(){
  AW(RB_PIN,TURN_CORRECTION_SPEED);
  AW(RF_PIN,0);
  AW(LB_PIN,0);
  AW(LF_PIN,0);
  //event1 =t1.after(10,move180_right);
  while(!(digitalRead(SCR_PIN) == LINE && digitalRead(SCL_PIN) == LINE)){
    //t1.update();
  }
  stoop();
  //t1.stop(event1);
  delay(REST_DELAY);
}

void move180_right(){
  t1.stop(event1);
  bool s1,s2,s3,s4;
  s1=s2=s3=s4=false;
  analogWrite(RB_PIN,TURN_SPEED);
  analogWrite(LF_PIN,TURN_SPEED);
  analogWrite(RF_PIN,0);
  analogWrite(LB_PIN,0); 
  do {
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
  }while(! ( s1 && s2 && s3 && s4 ));
  stoop();
  delay(REST_DELAY);
}

void correctionErrorToLeft(){
  AW(RB_PIN,0);
  AW(RF_PIN,0);
  AW(LB_PIN,TURN_CORRECTION_SPEED);
  AW(LF_PIN,0);
  //Serial.println("t2 ia initializing after");
  //event2=t2.after(10,move180_left);
  //Serial.println("t2 ia initializied after");
  while(!(digitalRead(SCR_PIN) == LINE && digitalRead(SCL_PIN) == LINE)){
    //t2.update();
  }
  stoop();
  //t2.stop(event2);
  delay(REST_DELAY);
}

void move180_left(){
  t2.stop(event2);
  bool s1,s2,s3,s4;
  s1=s2=s3=s4=false;
  analogWrite(RF_PIN,TURN_SPEED);
  analogWrite(LB_PIN,TURN_SPEED);
  analogWrite(RF_PIN,0);
  analogWrite(LB_PIN,0); 
  do {
    if (!s1){
      if (digitalRead(SL_PIN)==LINE )
        s1=true;
    }
    if (s1&&!s2){
      if (digitalRead(SL_PIN)!=LINE)
        s2=true;
    }
    if (s1&&s2&&!s3){
      if (digitalRead(SCL_PIN)==LINE){
        s3=true;
      }
    }
    if (s1&&s2&&s3&&!s4){
      if (digitalRead(SCR_PIN)==LINE){
        s4=true;
      }
    }
  }while(! ( s1 && s2 && s3 && s4 ));
  stoop();
  delay(REST_DELAY);
}
