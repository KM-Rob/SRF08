#ifndef SRF08_H
#define SRF08_H

#include<arduino.h>
#include<Wire.h>

// Registers
#define CMD_REG 0x00
#define LIGHT_REG 0x01
#define DIST_REG 0x02

// Commands
#define IN_MODE 0x50
#define CM_MODE 0x51
#define US_MODE 0x52
#define ANN_IN_MODE 0x53
#define	ANN_CM_MODE 0x54
#define ANN_US_MODE 0x55
#define SEQ1	0xA0
#define SEQ2	0xA5
#define SEQ3	0xAA


class SRF08
{
	private:
	
	// variables
		uint8_t I2C_addr;
		uint8_t Ranging_Mode;

	// functions
		chose_mode(uint8_t reg);
		activate();	
		
	public:
	//	SRF08(void);
		int begin(uint8_t I2C_address);
		int getRange();
		int getLight();
		String getUnits();
		setCentimeters();
		setInches();
		setuseconds();
		String message(uint8_t mode, String dist, String light);
};


#endif /* SRF08_H */