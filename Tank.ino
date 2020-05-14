#include <AFMotor.h>

//initial motors pin
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ); 

char command; 

void setup() 
{       
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
}

void loop(){
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    Stop();
    switch(command){
    case 'F':  
      forward();
      break;
    case 'B':  
       back();
      break;
    case 'L':  
      left();
      break;
    case 'R':
      right();
      break;
    }
  } 
}

void forward()
{
  motor1.setSpeed(255);  //Set the left motor in maximum force.
  motor1.run(FORWARD);   //Set the direction of rotation of the left motor.
  motor2.setSpeed(255);  //Set the right motor in maximum force.
  motor2.run(FORWARD);   //Set the direction of rotation of the right motor.
}

void back()
{
  motor1.setSpeed(255);   //Set the left motor in maximum force.
  motor1.run(BACKWARD);   //Set the direction of rotation of the left motor.
  motor2.setSpeed(255);   //Set the right motor in maximum force.
  motor2.run(BACKWARD);   //Set the direction of rotation of the right motor.
}

void left()
{
  motor1.setSpeed(255);   //Set the left motor in maximum force.
  motor1.run(BACKWARD);   //Set the direction of rotation of the left motor.
  motor2.setSpeed(255);   //Set the right motor in maximum force.
  motor2.run(FORWARD);    //Set the direction of rotation of the right motor.
}

void right()
{
  motor1.setSpeed(255);   //Set the left motor in maximum force.
  motor1.run(FORWARD);    //Set the direction of rotation of the left motor.
  motor2.setSpeed(255);   //Set the right motor in maximum force.
  motor2.run(BACKWARD);   //Set the direction of rotation of the right motor.
} 

void Stop()
{
  motor1.setSpeed(0);    //Set the left motor speed.
  motor1.run(RELEASE);   //STOP the left motor.
  motor2.setSpeed(0);    //Set the right motor speed.
  motor2.run(RELEASE);   //STOP the right motor.
}
