

#include<SoftwareSerial.h> //Included SoftwareSerial Library
//Started SoftwareSerial at RX and TX pin of ESP8266/NodeMCU
SoftwareSerial s1(3,1);
SoftwareSerial s(D4, A0);


#include <Servo.h>

Servo servo1;  
Servo servo2; 
Servo servo3; 
Servo servo4; 
int ch1  = 0;  // Receiver Channel 1 PPM value
int ch2  = 0;  // Receiver Channel 2 PPM value 
int ch3  = 0;  // Receiver Channel 3 PPM value
int ch4  = 0;  // Receiver Channel 4 PPM value
int ch5  = 0;  // Receiver Channel 5 PPM value
int ch6  = 0;  // Receiver Channel 6 PPM valu

//#define rcPin1  // Pin 8 Connected to CH1 of Transmitter;
#define rcPin2 D0  // Pin 9 Connected to CH1
//#define rcPin3 D8   // Pin 9 Connected to CH2
#define rcPin4 D7   // Pin 9 Connected to CH2
#define rcPin5 D6 // Pin 9 Connected to CH3
#define rcPin6 D5   // Pin 9 Connected to CH3


int minvalue1=950;
int minvalue2=1100;
int mid1=1350;
int mid2=1700;
int maxvalue1=2050;
int maxvalue2=1800;

int so[] = {6, 11, 8, 8};
int sc[] = {110, 110, 110, 110};
int close = 143;
int close2 = 137;




void closeservo()
{ int pos;
       for (pos = 9; pos <= close; pos += 1) { 
      servo1.write(pos); 
      // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
    }
    for (pos =  6; pos <= close2; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      servo2.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
    } 
    for (pos = 11; pos <= close; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      servo3.write(pos); 
      // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 11; pos <= close2; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      servo4.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
    }
}


void openservo()
{ int pos;
  for (pos = close; pos >= 9; pos -= 1) { // goes from 180 degrees to 0 degrees
      servo1.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
    } 
    for (pos = close2; pos >= 6; pos -= 1) { // goes from 180 degrees to 0 degrees
      servo2.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
    }  
    for (pos = close; pos >= 11; pos -= 1) { // goes from 180 degrees to 0 degrees
      servo3.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
    } 
    for (pos = close2; pos >= 11; pos -= 1) { // goes from 180 degrees to 0 degrees
      servo4.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15ms for the servo to reach the position
    }
    
}





void setup() {

  
  // put your setup code here, to run once:
  s.begin(9600);
  s1.begin(9600);
  servo1.attach(D8);
  servo2.attach(D1);
  servo3.attach(D2);
  servo4.attach(D3);
  Serial.begin(9600);
  
 // pinMode(A0,OUTPUT);
  //..............remote...............//

 // pinMode(rcPin1, INPUT);
  pinMode(rcPin2, INPUT); 
 // pinMode(rcPin3, INPUT);
 //pinMode(rcPin4, INPUT);
  pinMode(rcPin5, INPUT);
  pinMode(rcPin6, INPUT);

servo1.write(close2);
servo2.write(close2);
servo3.write(close2);
servo4.write(close2);
  
}

int flag = 1;
void loop() {
 if(s.available())  
 { 
  int pos;
  char a = ((char)s.read());
  (char)s1.write(a);
   Serial.println(a);

   
   
   switch(a){
     case 'c':
     closeservo();   
    // flag=0;
     
     break;

     case 'o':
      openservo();
      // flag=1;
     break;
     }
   
   
}
}


  
