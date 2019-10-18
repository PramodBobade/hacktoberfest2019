#define m1 2    // right
#define m2 3    //right
#define m3 4    //left
#define m4 5    //left
#define e1 10
#define e2 11


void setup() {
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);
  pinMode(e1,OUTPUT);
  pinMode(e2,OUTPUT);

}

Serial.println("hello world");
// 0 white
// 1 black
int s2,s3,s4,s5;
void loop() {
  
  s2=analogRead(A0);
  s3=analogRead(A1);
  s4=analogRead(A2);
  s5=analogRead(A3);
  if(s2==0 && s3==1 && s4==1 && s5==0){   // forward
   analogWrite(e1,200);
  analogWrite(e2,200);
  digitalWrite(m1,LOW);
  digitalWrite(m2,HIGH);
  digitalWrite(m3,LOW);
  digitalWrite(m4,HIGH);
  }
  else if(s2==0 && s3==1 && s4==1 && s5==1){    // right turn 
  analogWrite(e1,100);
  analogWrite(e2,100);
  digitalWrite(m1,LOW);
  digitalWrite(m2,LOW);
  digitalWrite(m3,LOW);
  digitalWrite(m4,HIGH);
  }
  else if(s2==1 && s3==1 && s4==1 && s5==0){    // left turn 
  analogWrite(e1,100);
  analogWrite(e2,100);
  digitalWrite(m1,LOW);
  digitalWrite(m2,HIGH);
  digitalWrite(m3,LOW);
  digitalWrite(m4,LOW);
  }
  if(s2==0 && s3==0 && s4==0 && s5==0){     // if the bot detects no line ,then it takes left turn till it gets on the track
  analogWrite(e1,100);
  analogWrite(e2,100);
  digitalWrite(m1,LOW);
  digitalWrite(m2,HIGH);
  digitalWrite(m3,HIGH);
  digitalWrite(m4,LOW);
  while(true){
    s2=analogRead(A0);
    s3=analogRead(A1);
    s4=analogRead(A2);
    s5=analogRead(A3);
    if(s2==0 && s3==1 && s4==1 && s5==0){
      break;
    }
   }
  }
  if(s2==1 && s3==1 && s4==1 && s5==1){     // if the 4 sensors detects black line ,then the bot first takes left turn
  analogWrite(e1,100);
  analogWrite(e2,100);
  digitalWrite(m1,LOW);
  digitalWrite(m2,HIGH);
  digitalWrite(m3,LOW);
  digitalWrite(m4,LOW);
  }

}


void forward(){
  analogWrite(e1,200);
  analogWrite(e2,200);
  digitalWrite(m1,LOW);
  digitalWrite(m2,HIGH);
  digitalWrite(m3,LOW);
  digitalWrite(m4,HIGH);
}

/*void right_turn(){
  analogWrite(e1,200);
  analogWrite(e2,200);
  digitalWrite(m1,LOW);
  digitalWrite(m2,LOW);
  digitalWrite(m3,LOW);
  digitalWrite(m4,HIGH);
}

void left_turn(){
  analogWrite(e1,200);
  analogWrite(e2,200);
  digitalWrite(m1,LOW);
  digitalWrite(m2,HIGH);
  digitalWrite(m3,LOW);
  digitalWrite(m4,LOW);
}*/
