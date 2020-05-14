
#include<SoftwareSerial.h>
SoftwareSerial HC06(10,9);

String messageRecu;
void setup(){
  Serial.begin(9600);
  HC06.begin(9600);
pinMode(13,OUTPUT);
 
  }

  void loop(){
    while(HC06.available()){
      delay(3);
      char c=HC06.read();
      messageRecu+=c;
    }
      if(messageRecu.length()>0){
        Serial.println(messageRecu);
        
     if(messageRecu=="F")
    { 
    digitalWrite(13,HIGH);
   
    }
 if(messageRecu="");
  }
  }
