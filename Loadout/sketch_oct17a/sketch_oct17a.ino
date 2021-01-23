/* Minimum_Source*/


#define MODE 11
#define DXL_BUS_SERIAL1 1

Dynamixel Dxl(DXL_BUS_SERIAL1);

int ID[] = {1, 2, 3, 4, 5, 6};

void setup() {
  Dxl.begin(3);
  Dxl.setPacketType(DXL_PACKET_TYPE2);
  delay(1000);
  
  //Set all motors to wheel mode
  int i=1;
  while(i<7)
  {
    Dxl.wheelMode(i);
    i++;
  }
  delay(1000);
  
  
  
}

void loop() {
  // put your main code here, to run repeatedly: 

}

