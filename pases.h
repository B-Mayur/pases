/* pases.h - A library for the project "Post Accident Smart Emergency Services(PASES)"
	project by :	"Mayur B"
					"Kewal P"
					"Akshay K"
	Guided by : 	"Prof. K.S.Vaidya"
	Institute :		"TSSM's BSCOER, Narhe"
	Created : 		Feb 8, 2016
	Released :		into Private Domain.
*/

#ifndef PASES_H
#define PASES_H


// Function Prototypes to keep Arduino Happy.
void initHardware(long);
void useInterrupt(bool);
bool testGsmModule(SoftwareSerial *);
void lcdWelcomeMsg(void);
void lcdDateAndTime(void);
void lcdLocation(void);
void lcdSpeed(void);
void myDelay(long);
bool isAccident(void);

#define USE_INTERRUPT true
#define DEBUGGING_ON true
#define GLOBAL_BAUD_RATE 9600

// MODULE PIN DEFINITIONS 
#define GPS_DATA_IN 2
#define GPS_DATA_OUT 3
#define GSM_DATA_IN 4
#define GSM_DATA_OUT 5
#define LCD_ROWS 2
#define LCD_COL 16
#define LCD_RS 	6
#define LCD_EN 	7
#define LCD_D4	8
#define LCD_D5	9
#define LCD_D6	10
#define LCD_D7	11
#define TEMP_SENSOR_PIN 3		// This is Analog Pin 3, NOT digital.

// Set MPU6050 offsets. Use calibration sketch to measure offset values.
#define MPU6050_OFFSET_AX		-569
#define MPU6050_OFFSET_AY		-1457
#define MPU6050_OFFSET_AZ		5255
#define MPU6050_OFFSET_GX
#define MPU6050_OFFSET_GY
#define MPU6050_OFFSET_GZ
// Set MPU6050 thresholds for the Accident Condition.
#define MPU6050_THRESHOLD_AX	3000
#define MPU6050_THRESHOLD_AY	3000
#define MPU6050_THRESHOLD_AZ	4000
#define MPU6050_THRESHOLD_GX
#define MPU6050_THRESHOLD_GY
#define MPU6050_THRESHOLD_GZ

// GSM_MODULE_DEFINITIONS
#define GSM_MODULE_RESPONSE_TIME 250	// Specify in miliSeconds

// Set true to modules which are connected. Everything is CONNECTED(TRUE) by default.

#define HARDWARE_SERIAL0_CONNECTED 			true		
#define MPU6050_MODULE_CONNECTED 			true
#define GPS_MODULE_CONNECTED 				true
#define GSM_MODULE_CONNECTED 				true
#define LIQUID_CRYSTAL_DISPLAY_CONNECTED 	true
#define CARD_READER_MODULE_CONNECTED 		false
#define TEMP_SENSOR_CONNECTED 				true

// ISR_SELECTION_DEFINITION
//#define ENABLE_GPS_READ_ISR false

// LIQUID_CRYSTAL_DISPLAY_MESSAGE_DEFINITIONS
#define LCD_DISPLAY_DELAY 		1000		
#define LCD_NO_DISPLAY_DELAY	250
#define LCD_INSTITUTE 			"TSSM BSCOER"
#define LCD_CAMPUS 				"NARHE CAMPUS"
#define LCD_PROJECT_BY 			"A PROJECT BY"
#define LCD_GROUP_MEMBER_ONE 	"1. MAYUR B."
#define LCD_GROUP_MEMBER_TWO 	"2. KEWAL P."
#define LCD_GROUP_MEMBER_THREE 	"3. AKSHAY K."
#define LCD_GUIDED_BY 			"GUIDED BY"
#define LCD_GUIDE 				"PROF. K.S.VAIDYA"
#define LCD_TEMPERATURE			"TEMPERATURE"
#define LCD_TIME				"TIME:"
#define LCD_DATE 				"DATE:"
#define LCD_LATITUDE			"LAT: "
#define LCD_LONGITUDE			"LONG: "
#define LCD_SPEED 				"SPEED:"
#define LCD_SPEED_UNIT			" Km/h"



// SET DEBUGGIN ON/OFF
#ifdef DEBUGGING_ON
	#define HARDWARE_SERIAL0_CONNECTED true
#else
	#define HARDWARE_SERIAL0_CONNECTED false
#endif

#endif
