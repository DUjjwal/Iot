#include "arduino_secrets.h"

/*

*/
#include<Servo.h>
int IRSENSOR1=6;
int IRSENSOR2=7;

Servo myservo;
void setup() {
    Serial.begin(9600);
    pinMode(IRSENSOR1, INPUT);
    pinMode(IRSENSOR2, INPUT);
  myservo.attach(9);
  myservo.write(20);
}

void loop() {
    int val=digitalRead(IRSENSOR1);
    int val2=digitalRead(IRSENSOR2);
    int temp=val*100+20+val2; 
    if(temp==20 ||temp==021) {        
        Serial.println("detected");
        for(int i=20;i<=35;i++) {
            myservo.write(i);
            delay(5);
          }
        for(int i=35;i>=20;i--) {
              myservo.write(i);
              delay(5);
          }
    }
    // Serial.println(temp);
    
}
