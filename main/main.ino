#include "pases.h"
#include <SoftwareSerial.h>
#include <Adafruit_GPS.h>
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"
#include <LiquidCrystal.h>

#ifdef GPS_MODULE_CONNECTED
	SoftwareSerial mySerial(GPS_DATA_IN, GPS_DATA_OUT);
	Adafruit_GPS gpsModule(&mySerial);
#endif

#ifdef GSM_MODULE_CONNECTED
	SoftwareSerial gsmModule(GSM_DATA_IN,GSM_DATA_OUT);
#endif

#ifdef MPU6050_MODULE_CONNECTED
	MPU6050 mpu;
	int16_t ax, ay, az;		// To hold 3-axis acceleration data resp.
#endif

#ifdef LIQUID_CRYSTAL_DISPLAY_CONNECTED
	LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
#endif

void setup(){
	initHardware(GLOBAL_BAUD_RATE);		// From initHardware.ino
	useInterrupt(USE_INTERRUPT);		// Change boolean value in "pases.h"
										// From useInterrupt.ino
	myDelay(250);

	// If LIQUID_CRYSTAL_DISPLAY is CONNECTED -> Print welcome message on it.
	#ifdef LIQUID_CRYSTAL_DISPLAY_CONNECTED
		lcdWelcomeMsg();			// From lcdFunctions.ino
	#endif
}

void main(){
	lcdTemperature();
	lcdDateAndTime();
	lcdLocation();
	lcdSpeed();
	myDelay(10);
}

