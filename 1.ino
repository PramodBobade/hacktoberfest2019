#include <Servo.h>

Servo servo_test;

int pir=A0;
int trigger=9;
int echo=10;
int buzzer=5;
int angle = 0;
int anglelimit=15;
    

void setup() {
  
  pinMode(pir,INPUT);
  pinMode(echo,INPUT);
  pinMode(trigger,OUTPUT);
  pinMode(buzzer,OUTPUT);
  
  Serial.begin(9600); 
  servo_test.attach(8);

}


  
void loop() {


long duration;
int distance;
digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);
duration = pulseIn(echo, HIGH);
distance= duration*0.034/2;
Serial.print("Distance: ");
Serial.println(distance);

if(analogRead(pir)<=500){
  digitalWrite(buzzer,HIGH);
  delay(100);
  exit(0);
}
else{
  digitalWrite(buzzer,LOW);
  delay(100);
}
if(angle<180){
  clockwise();
}
else{
  anticlockwise();
}
 

}

Serial.println("hello world");
  

void anticlockwise(){
  for(int i = 0; i < anglelimit; i += 1)  
  {                                  
    servo_test.write(i);                
    delay(15);                       
  } 
  angle=angle+15;
  anglelimit=anglelimit+15;
}

void clockwise(){
  for(int i = anglelimit; i>=1; i-=5)    
  {                                
    servo_test.write(i);              
    delay(15);                       
  } 
  angle=angle-15;
  anglelimit=anglelimit-15;
 }
  
