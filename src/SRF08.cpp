#include<SRF08.h>

/*SRF08::SRF08(void)
{
	Ranging_Mode = CM_MODE;
}*/


int SRF08::begin(uint8_t I2C_address)
{
	I2C_addr = I2C_address;
	Ranging_Mode = CM_MODE;
	Wire.begin();
	
	Wire.beginTransmission(I2C_addr);
    return Wire.endTransmission();
}
	
	
int SRF08::getRange()
{
	uint8_t highByte = 0x00;                 // Stores high byte from ranging
	uint8_t lowByte = 0x00;                  // Stored low byte from ranging
  
	Wire.beginTransmission(I2C_addr);
	Wire.write(CMD_REG);  //command register
	Wire.write(Ranging_Mode);  // distance in centimeters
	Wire.endTransmission();
	delay(100);

	chose_mode(DIST_REG);

	Wire.requestFrom(I2C_addr, 2);
	highByte = Wire.read();                      // Get high byte
	lowByte = Wire.read();                       // Get low byte

	return (highByte >> 8) + lowByte;	
}

int SRF08::getLight()
{
	chose_mode(LIGHT_REG);
  
	Wire.requestFrom(I2C_addr, 1);
	return Wire.read();	
}
	
SRF08::setCentimeters()
{
	Ranging_Mode = CM_MODE;
}
SRF08::setInches()
{
	Ranging_Mode = IN_MODE;
}
SRF08::setuseconds()
{
	Ranging_Mode = US_MODE;
}

SRF08::chose_mode(uint8_t reg)
{
	Wire.beginTransmission(I2C_addr);
	Wire.write(reg);  //light register
	Wire.endTransmission();
}