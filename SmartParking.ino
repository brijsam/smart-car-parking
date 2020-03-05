#include "ThingSpeak.h"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>
#define IR1 D1
#define IR2 D2
#define IR3 D3
              ////////////////////////  Here we are declaring Variable for nodemcu to acessour ID and PASS and AUTH Key   /////// 
char auth[] = "HuSJKkx7dq0qNUqllWsx61C81l3wgrJg";
char ssid[] = "Brij sam";
char pass[] = "brij963478";

WidgetLED led1(V1);
WidgetLED led2(V2);
WidgetLED led3(V3);

Servo servo;

void setup()
{
  servo.attach(16);//D0 pin in nodemcu
  
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  
}
void loop(){
  
int det1=digitalRead(IR1);  //detect whether the ir sensors are high or low means there is any object or not
int det2=digitalRead(IR2);
int det3=digitalRead(IR3);
{
  Blynk.run();
}

BLYNK_CONNECTED();
{
  Blynk.syncVirtual(V1,V2,V3);
}
BLYNK_WRITE(V1);
  if(det1==HIGH){
    led1.on();
    }
BLYNK_WRITE(V2);
  if(det2==HIGH){
    led2.on();
    }
BLYNK_WRITE(V3);
  if(det3==HIGH){
    led3.on();
    }

//////////////////////////////////////////////////////For servo motor programming///////////////////////////

  if((det1||det2||det3)==LOW){
    servo.write(90);
                     ////////////////////////////////// It will open the Barcade
    };
  if((det1||det2||det3)==HIGH){
    servo.write(0);  ///////////////////////////////////// It will Close the Barcade
    };
delay(500);
}
