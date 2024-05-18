#include <SRF08.h>
#define I2C_ADDR 0x78

SRF08 sens;

void setup() {
  int error=0;
  // put your setup code here, to run once:
  Serial.begin(9600);
  error = sens.begin(I2C_ADDR);
  while(!Serial);
  Serial.println("Start");
  if(error)
  {
    Serial.println("No sensor detected or wrong I2C address");
    while(error);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  /*Serial.print("Distance: ");
  Serial.print(sens.getRange());
  Serial.print(sens.getUnits());
  Serial.print("  Light: ");
  Serial.println(sens.getLight());
  */
  Serial.println(sens.message(1, "Dist", "Light"));
  delay(300);
}
