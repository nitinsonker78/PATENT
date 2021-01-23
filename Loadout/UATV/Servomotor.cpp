#include "Servo.h"

//setting pins to servos
int s1 = 12;
int s2 = 13;
int s3 = 14;
int s4 = 15;
 
int angleopen1 = 0;
int angleopen2 = 0;
int angleopen3 = 0;
int angleopen4 = 0;

int angleclose1 = 0;
int angleclose2 = 0;
int angleclose3 = 0;
int angleclose4 = 0;

  
       for(angle4 = 180; angle4>=1; angle4-=1)     // goes from 180 degrees to 0 degrees 
      {                                
        servo4.write(angle4);// tell servo to go to position in variable 'pos'  
        delay(5);                       // waits 15ms for the servo to reach the position 
      } 1

