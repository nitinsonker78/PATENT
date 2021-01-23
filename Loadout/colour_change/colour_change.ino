/* Minimum_Source*/
#define LED 25
#define DXL_BUS_SERIAL1 1  //Dynamixel on Serial1(USART1)  <-OpenCM9.04
Dynamixel Dxl(DXL_BUS_SERIAL1);

void setup() {
   Dxl.begin(3); //baudrate set to 1 Mbps (max)
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly: 
digitalWrite(BOARD_LED_PIN, LOW);
/*for(int id=1;id<7;id++)
{
  for(int j = 0;j<8;j++)
  {
   Dxl.writeByte(id, LED, j);
  }
}
*/
for(int j=2;j<8;j++)
{
  for(int id = 1;id<7;id++)
  {
   Dxl.writeByte(id, LED, j);
  }
  delay(500);
}
}

