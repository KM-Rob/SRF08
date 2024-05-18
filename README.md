# Antratek SRF08
## Arduino library
This is library of Antratek SRF08 ultrasonic range sensor for Arduino
The sensor utilizes I2C for communication.
Datasheet of the sensor is in:
<https://www.robot-electronics.co.uk/htm/srf08tech.html>
The code is based on:
<https://zeldor.biz/2012/10/arduino-srf08/>

Nominal commit includes functions & features:
* configuring object,
* begining function with sensor presence,
* reading range in centimeters, inches and microseconds (default mode is centimeters),
* reading light with nominal gain according to datasheet,
* changing mode of range measurement.

### API Functions:
* begin(I2C_address) - creates sensor object with its I2C address,
* int getRange() - initiates distance measurement and returns value of measurement,
* int getLight() - reads light value (without measurement initiation),
* String getUnits() - returns unit of range measurement in string form for: cenitimeters - "cm", inches - "in", microseconds - "us",
* setCentimeters() - sets range measurement mode to centimeters,
* setInches() - sets range measurement mode to inches,
* setuseconds() - sets range measurement mode to microseconds,
* String message(mode, dist, light) - performs measurement(s) and returns string message with values and additional information strings,

### Types of message
In case of mode message function returns string (can use nums or bold strings):
* 0 **Range_only**, returns message in structure "*'dist': valueunits*",
* 1 **Light_only**, returns message in structure "*'light': value*",
* 2 **Range_first**, returns message in structure "*'dist': valueunits  'light': value*",
* 3 **Light_first**, returns message in structure "*'light': value  'dist': valueunits*",

where *'dist'* and *'light'* are values in proper input parameters. 
Exemplary message:

*Dist: 56cm  Light: 246* - for mode 2 and variables: dist - "Dist" and light - "Light" 
