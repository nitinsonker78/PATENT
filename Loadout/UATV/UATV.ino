#include "Remote.h"
#include "Servo.h"
#include "Servomotor.h"
#include "conversion.h"
#include "control_param.h"



#define MODE 11
#define DXL_BUS_SERIAL1 1

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;


Dynamixel Dxl(DXL_BUS_SERIAL1);

int ID[] = {1, 2, 3, 4, 5, 6};

void setup() {
  Dxl.begin(3);
  Dxl.setPacketType(DXL_PACKET_TYPE2);
  delay(1000);
  
  pinMode(rcPin1, INPUT);
  pinMode(rcPin2, INPUT); 
  pinMode(rcPin3, INPUT); 
  pinMode(rcPin4, INPUT);
  pinMode(rcPin5, INPUT);
  pinMode(rcPin6, INPUT);

  
  //Set all motors to wheel mode
  int i=1;
  while(i<7)
  {
    Dxl.wheelMode(i);
    i++;
  }
  delay(1000);
  
  servo1.attach(s1);
  servo2.attach(s2);
  servo3.attach(s3);
  servo4.attach(s4);
    
}

void loop() {
  // put your main code here, to run repeatedly: 

}
//Servo

void Servo_close()
{
  int i = servo1.read(); 
       for(angle1 = 180; angle1>=1; angle1-=1)     // goes from 180 degrees to 0 degrees 
      {                                
        servo1.write(angle1);// tell servo to go to position in variable 'pos'  
        delay(5);                       // waits 15ms for the servo to reach the position 
      } 
      i = servo2.read(); 
       for(angle2 = 180; angle2>=1; angle2-=1)     // goes from 180 degrees to 0 degrees 
      {                                
        servo2.write(angle2);// tell servo to go to position in variable 'pos'  
        delay(5);                       // waits 15ms for the servo to reach the position 
      } 
      i = servo3.read(); 
       for(angle3 = 180; angle3>=1; angle3-=1)     // goes from 180 degrees to 0 degrees 
      {                                
        servo3.write(angle3);// tell servo to go to position in variable 'pos'  
        delay(5);                       // waits 15ms for the servo to reach the position 
      }
      i = servo4.read(); 
       for(angle4 = 180; angle4>=1; angle4-=1)     // goes from 180 degrees to 0 degrees 
      {                                
        servo4.write(angle4);// tell servo to go to position in variable 'pos'  
        delay(5);                       // waits 15ms for the servo to reach the position 
      } 
      
}
 

void Servo_open()
{
    int i = servo1.read();
    for(angle1 = i; angle1 < 180; angle1 += 1)  // goes from 0 degrees to 180 degrees 
      {                                  // in steps of 1 degree 
        servo1.write(angle1);// tell servo to go to position in variable 'pos' 
        delay(5);                         // waits 15ms for the servo to reach the position 
      } 
    i = servo2.read();
    for(angle2 = i; angle2 < 180; angle2 += 1)  // goes from 0 degrees to 180 degrees 
      {                                  // in steps of 1 degree 
        servo2.write(angle2);// tell servo to go to position in variable 'pos' 
        delay(5);                      // waits 15ms for the servo to reach the position 
      } 
    i = servo3.read();
    for(angle3 = i; angle3 < 180; angle3 += 1)
    {                                  // in steps of 1 degree 
        servo3.write(angle3);// tell servo to go to position in variable 'pos' 
        delay(5); 
    } 
    i = servo4.read();
    for(angle4 = i; angle4 < 180; angle4 += 1)
      {                                  // in steps of 1 degree 
        servo4.write(angle4);// tell servo to go to position in variable 'pos'                               
        delay(5);
      }                
}

