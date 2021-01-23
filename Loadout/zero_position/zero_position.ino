

#define DXL_BUS_SERIAL1 1  //Dynamixel on Serial1(USART1)  <-OpenCM9.04

Dynamixel Dxl(DXL_BUS_SERIAL1);

#define MOVING_SPEED 32
#define PRESENT_POS 37
#define GOAL_POSITION 30

int theta_dead = 60;
int theta_circle = 360;
int p;

float p_to_Theta(int P){
  return P * (theta_circle - theta_dead) / 1024.0 - 5.0 * (theta_circle) / 12.0; // (5 * theta circle / 12) offsets 0 to bottom
}

void setup() {
  // put your setup code here, to run once:
  Dxl.begin(3);
  Dxl.jointMode(6);
  /*
  Dxl.jointMode(1); //jointMode() is to use position mode
  Dxl.jointMode(2);
  Dxl.jointMode(3);
  Dxl.jointMode(4);
  Dxl.jointMode(5);
  Dxl.jointMode(6);
  */
}

void loop() {
  /*
  Dxl.writeWord(1, GOAL_POSITION, 512);
  Dxl.writeWord(2, GOAL_POSITION, 512);
  Dxl.writeWord(3, GOAL_POSITION, 512);
  Dxl.writeWord(4, GOAL_POSITION, 512);
  Dxl.writeWord(5, GOAL_POSITION, 512);
  Dxl.writeWord(6, GOAL_POSITION, 512);
  */
  /*for (int i = 1; i < 7; i++){  
    SerialUSB.print(i);
    SerialUSB.print(": ");
    SerialUSB.println(p_to_Theta(Dxl.readWord(i, PRESENT_POS)));
  }*/for(int i = 0;i<7;i++)
  {
    SerialUSB.print(" Postion : " );
    SerialUSB.print(i);
    SerialUSB.print(" : ");
    
    SerialUSB.println(p_to_Theta(Dxl.readWord(i, PRESENT_POS)));
    delay(1000);
  }
  
}

