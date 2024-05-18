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
  
	activate();
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
	
String SRF08::getUnits()
{
	if(Ranging_Mode == IN_MODE) return "in";
	if(Ranging_Mode == CM_MODE) return "cm";
	if(Ranging_Mode == US_MODE) return "us";
	if(Ranging_Mode == ANN_IN_MODE) return "in";
	if(Ranging_Mode == ANN_CM_MODE) return "cm";
	if(Ranging_Mode == ANN_US_MODE) return "us";
	return "";
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

String SRF08::message(uint8_t mode, String dist, String light)
{
	String mess = "";
	switch(mode)
	{
		case 0: // only range
			mess = mess + dist + ": " + getRange() + getUnits();
			break;  
		case 1: // only light
			activate();
			delay(100);
			mess = mess + light + ": " + getLight();
			break;  
		case 2: // both values (range first)
			mess = mess + dist + ": " + getRange() + getUnits() + "  " + light + ": " + getLight();
			break;
		case 3: // both values (light first)
			activate();
			delay(100);
			mess = mess + light + ": " + getLight() + "  " + dist + ": " + getRange() + getUnits();
			break;
	}
	return mess;
}

SRF08::activate()
{
	Wire.beginTransmission(I2C_addr);
	Wire.write(CMD_REG);  //command register
	Wire.write(Ranging_Mode);  // distance in centimeters
	Wire.endTransmission();	
}