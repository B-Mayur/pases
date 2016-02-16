void initHardware(long baudRate){

	// 1. Initialize HARDWARE_SERIAL0
	if(HARDWARE_SERIAL0_CONNECTED){
		Serial.begin(baudRate);
	}
	
	// 2. Initialize GPS_MODULE // OBJECT NAME : gpsModule AND/OR mySerial
	if(GPS_MODULE_CONNECTED){
		gpsModule.begin(baudRate);
		gpsModule.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCONLY);
		gpsModule.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);	// 1 Hz update rate.
		gpsModule.sendCommand(PGCMD_ANTENNA);
		if(DEBUGGING_ON){
			Serial.println(F("DB: GPS_MODULE_CONNECTED SUCCESSFULLY."));
		}
	}

	// 3. Initialize GSM_MODULE
	if(GSM_MODULE_CONNECTED){
		if(testGsmModule(gsmModule)){
			if(DEBUGGING_ON){
				Serial.println(F("DB: GSM_MODULE_CONNECTED SUCCESSFULLY"));
			}
		}
		else{
			if(DEBUGGING_ON){
				Serial.println(F("DB: GSM_MODULE_CONNECTION FAILED"));
			}
		}
	}

	// 4. Initialize MPU6050_MODULE
	if(MPU6050_MODULE_CONNECTED){
		wire.begin();
		mpu.Initialize();
		mpu.setFullScaleAccelRange(MPU6050_ACCEL_FS_16);	// Set FULL_SCALE_RANGE of ACCELEROMETER to be 16g
		if(mpu.testConnection()){
			#ifdef MPU6050_OFFSET_AX
				mpu.setXAccelOffset(MPU6050_OFFSET_AX);
			#else
				mpu.setXAccelOffset(0);
			#endif
			#ifdef MPU6050_OFFSET_AY
				mpu.setYAccelOffset(MPU6050_OFFSET_AY);
			#else
				mpu.setYAccelOffset(0);
			#endif
			#ifdef MPU6050_OFFSET_AZ
				mpu.setZAccelOffset(MPU6050_OFFSET_AZ);
			#else
				mpu.setZAccelOffset(0);
			#endif
			if(DEBUGGING_ON){
				Serial.println(F("DB: MPU6050_MODULE_CONNECTED SUCCESSFULLY."));
			}
		}
	}

	// 5. Initialize LIQUID_CRYSTAL_DISPLAY
	if(LIQUID_CRYSTAL_DISPLAY_CONNECTED){
		LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
		lcd.begin(LCD_COL, LCD_ROWS);
		if(DEBUGGING_ON){
			Serial.println(F("DB: LIQUID_CRYSTAL_DISPLAY_CONNECTED SUCCESSFULLY"));
		}
	}

	// 6. Initialize CARD_READER_MODULE
	if(CARD_READER_MODULE_CONNECTED){
		// Will do this coding later. It is not connected at the moment anyway.

		if(DEBUGGING_ON){
			Serial.println(F("DB: CARD_READER_MODULE_CONNECTED SUCCESSFULLY"));
		}
	}

	// 7. Define Temperature sensor.
	if(TEMP_SENSOR_CONNECTED){
		float t=0.0, t1 = 0.0;
		do{
			t = analogRead(TEMP_SENSOR_PIN);
			delay(10);
			t1 = analogRead(TEMP_SENSOR_PIN);
		}while(t!=t1);

		if(DEBUGGING_ON){
			Serial.println(F("DB: TEMP_SENSOR_CONNECTED SUCCESSFULLY."))
		}

	}
}

bool testGsmModule(SoftwareSerial *module){
    module->begin(9600);
    char response[32];
    char *str = NULL;
    byte i = 0;
    module->println(F("AT"));
    delay(500);
    if(module->available()){
        while(module->available()){
            response[i++] = module->read();
        }
    }
    str = strstr(response,"OK");
    if(str!=NULL)
      return true;
    else
      return false;
}
