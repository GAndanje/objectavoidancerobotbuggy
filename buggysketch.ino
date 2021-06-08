#include <NewPing.h>
#include <Servo.h>
int tripPin = 2;
int echoPin = 3; 
int pwmENA = 5;
int pwmENB = 6;
int leftwheelForward =13;
int leftwheelBackward = 7;
int rightwheelForward = 8;
int rightwheelBackward = 12;
int leftDistance;
int rightDistance;
int duration;
int distance;
int delayInterval =10;
int timeNow;
int pinServo = 10;
NewPing sonar(tripPin,echoPin);
Servo myServo;
void setup() 
  {
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(leftwheelForward,OUTPUT);
    pinMode(leftwheelBackward,OUTPUT);
    pinMode(rightwheelForward,OUTPUT);
    pinMode(rightwheelBackward,OUTPUT);
    pinMode(pwmENA,OUTPUT);
    pinMode(pwmENA,OUTPUT);
    pinMode(pinServo,OUTPUT);
    myServo.attach(pinServo);
    digitalWrite(pwmENA,1);
    digitalWrite(pwmENB,1);
    myServo.write(65);
    delay(1000);
    distance = sonar.convert_cm(sonar.ping_median());
    
  }

void loop() 
  {
    myServo.write(65);
    if(distance <=15)
      {moveStop();
     timeNow = millis();
     while(millis()-timeNow < delayInterval)
        {} 
      reverse();
     timeNow = millis();
     while(millis()-timeNow < delayInterval*100)
        {} 
      moveStop();
     timeNow = millis();
     while(millis()-timeNow < delayInterval)
        {} 
      
      if(checkRight()>distance and checkRight()>checkLeft())
        {
          turnRight();
          timeNow = millis();
          while(millis()-timeNow < delayInterval*10)
            {} 
           moveStop();
        }
       else if (checkLeft() >distance and checkLeft()>checkRight())
        {
           turnLeft();
           timeNow = millis();
          while(millis()-timeNow < delayInterval*10)
            {}    
           moveStop();        
        }
       else
       {moveForward();}
      }
    else
      {
        moveForward();
      }
     distance =sonar.convert_cm(sonar.ping_median());
     timeNow = millis();
     while(millis()-timeNow < delayInterval*10)
        {} 
    
  }
int checkRight()
  {
    myServo.write(35);
    timeNow = millis();
    if (millis()-timeNow>=delayInterval*10)
      {rightDistance = sonar.convert_cm(sonar.ping_median());}
    else
      {}
 
    myServo.write(65);
    return rightDistance;
  }
int checkLeft()
  {
    myServo.write(95);
    timeNow = millis();
    if (millis()-timeNow>=delayInterval*10)
      {leftDistance = sonar.convert_cm(sonar.ping_median());}
    else
      {}
    myServo.write(65);
      return leftDistance;
  }
void turnLeft()
  {
    digitalWrite(leftwheelForward,LOW);
    digitalWrite(rightwheelForward,HIGH);
    digitalWrite(leftwheelBackward,HIGH);
    digitalWrite(rightwheelBackward,LOW);
     timeNow = millis();
     while(millis()-timeNow < delayInterval*10)
        {}
  }
void turnRight()
  {
    digitalWrite(leftwheelForward,HIGH);
    digitalWrite(rightwheelForward,LOW);
    digitalWrite(leftwheelBackward,LOW);
    digitalWrite(rightwheelBackward,HIGH);
     timeNow = millis();
     while(millis()-timeNow < delayInterval*10)
        {}
  }
void moveForward()
  {
    digitalWrite(leftwheelForward,HIGH);
    digitalWrite(rightwheelForward,HIGH);
    digitalWrite(leftwheelBackward,LOW);
    digitalWrite(rightwheelBackward,LOW);
  }
void reverse()
  {
    digitalWrite(leftwheelBackward,HIGH);
    digitalWrite(rightwheelBackward,HIGH);
    digitalWrite(leftwheelForward,LOW);
    digitalWrite(rightwheelForward,LOW);
  }
void moveStop()
  {
    digitalWrite(leftwheelBackward,LOW);
    digitalWrite(rightwheelBackward,LOW);
    digitalWrite(leftwheelForward,LOW);
    digitalWrite(rightwheelForward,LOW);
  }

  
