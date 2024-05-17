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
