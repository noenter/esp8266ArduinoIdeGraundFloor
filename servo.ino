void servo_init(){
  servo.attach(13);
  String st = "OFF";
  jsonWrite(configJson, "s1_Name", st);
  jsonWrite(configJson, "s2_Name", st);
  servo.write(s1);
  servo.write(s2);
  
}

void servo1open(){
  s1 = 116;
  s1_Name = (String)s1;
  SoketData ("s1_Name", s1_Name, jsonRead(configJson,"s1_Name"));
  jsonWrite(configJson, "s1_Name", s1_Name);
  Serial.println(s1_Name);
servo.write(s1);}

void servo1close(){
  s1 = 0;
  s1_Name = (String)s1;
  SoketData ("s1_Name", s1_Name, jsonRead(configJson,"s1_Name"));
  jsonWrite(configJson, "s1_Name", s1_Name);
  Serial.println(s1_Name);
servo.write(s1);}

void servo2open(){
 s2 = 116;
servo.write(s2);}

void servo2close(){
 s2 = 0;
servo.write(s2);}
