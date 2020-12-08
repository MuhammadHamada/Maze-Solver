
void testSensors(){
  int cr=digitalRead(SCR_PIN);
  int cl=digitalRead(SCL_PIN);
  int r=digitalRead(SR_PIN);
  int l=digitalRead(SL_PIN);
  Serial.print ("the sensors output CL ");
  Serial.print ( cl );
  Serial.print (" CR ");
  Serial.print ( cr );
  Serial.print (" R ");
  Serial.print ( (r)?'1':'0' );
  Serial.print (" L ");
  Serial.print ( (l)?'1':'0' );
  Serial.println("");
}
