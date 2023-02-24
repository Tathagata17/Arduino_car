#include "SoftwareSerial.h"
#define l 13
 
int bluetoothdata;
SoftwareSerial HM10(0,1);//rx tx
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
HM10.begin(9600);
pinMode(13,OUTPUT);//left motor
pinMode(12,OUTPUT);//left motor
pinMode(11,OUTPUT);//right motor
pinMode(10,OUTPUT);// right motor
}

void loop() {
  // put your main code here, to run repeatedly:
if(HM10.available())
{
  bluetoothdata=HM10.read();
  Serial.println(bluetoothdata);
  if(bluetoothdata==70)
  {
    
    digitalWrite(13,HIGH); //motor move in forward directio
    digitalWrite(11,HIGH);     
   digitalWrite(12,LOW);
   digitalWrite(10,LOW);
  }
    else if(bluetoothdata==66)
   {
    digitalWrite(13,LOW); //motor move in reverse directio
    digitalWrite(11,LOW);     
   digitalWrite(12,HIGH);
   digitalWrite(10,HIGH);
   }
    else if(bluetoothdata==82) 
    {
    digitalWrite(13,HIGH); //motor move in left directio
    digitalWrite(11,LOW);     
   digitalWrite(12,LOW);
   digitalWrite(10,LOW);
    }
    
     else if(bluetoothdata==76) 
     {
    digitalWrite(13,LOW); //motor move in right directio
    digitalWrite(11,HIGH);     
   digitalWrite(12,LOW);
   digitalWrite(10,LOW);
     }
    
   else if(bluetoothdata==72) 
   {
    digitalWrite(13,LOW); //motor move in right directio
    digitalWrite(11,LOW);     
   digitalWrite(12,LOW);
   digitalWrite(10,LOW);
   }
  
    
  }
}
