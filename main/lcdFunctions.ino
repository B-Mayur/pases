void lcdWelcomeMsg(){
	#ifdef DEBUGGING_ON
		Serial.println(F("DB: LCD << Welcome Message"))
	#endif
	#ifdef LIQUID_CRYSTAL_DISPLAY_CONNECTED
		// Print INSTITUTE_NAME
		lcd.clear();
		lcd.print(F(LCD_INSTITUTE));
		lcd.setCursor(0,1);
		lcd.print(F(LCD_CAMPUS));
		lcd.display();
		// Display message for specific time
		myDelay(LCD_DISPLAY_DELAY);
		// Erase message on lcd
		lcd.noDisplay();
		// Wait for specific time
		myDelay(LCD_NO_DISPLAY_DELAY);

		// Print GROUP_MEMBER_ONE
		lcd.clear();
		lcd.print(F(LCD_PROJECT_BY));
		lcd.setCursor(0,1);
		lcd.print(F(LCD_GROUP_MEMBER_ONE));
		lcd.display();
		// Display message for specific tim
		myDelay(LCD_DISPLAY_DELAY);
		// Erase message on lcd
		lcd.noDisplay();
		// wait for specific time
		myDelay(LCD_NO_DISPLAY_DELAY);

		// Print GROUP_MEMBER_TWO
		lcd.clear();
		lcd.print(F(LCD_PROJECT_BY));
		lcd.setCursor(0,1);
		lcd.print(F(LCD_GROUP_MEMBER_TWO));
		lcd.display();
		// Display message for specific tim
		myDelay(LCD_DISPLAY_DELAY);
		// Erase message on lcd
		lcd.noDisplay();
		// wait for specific time
		myDelay(LCD_NO_DISPLAY_DELAY);

		// Print GROUP_MEMBER_THREE
		lcd.clear();
		lcd.print(F(LCD_PROJECT_BY));
		lcd.setCursor(0,1);
		lcd.print(F(LCD_GROUP_MEMBER_THREE));
		lcd.display();
		// Display message for specific tim
		myDelay(LCD_DISPLAY_DELAY);
		// Erase message on lcd
		lcd.noDisplay();
		// wait for specific time
		myDelay(LCD_NO_DISPLAY_DELAY);

		// Print PROJECT_GUIDE
		lcd.clear();
		lcd.print(F(LCD_GUIDED_BY));
		lcd.setCursor(0,1);
		lcd.print(F(LCD_GUIDE));
		lcd.display();
		// Display message for specific tim
		myDelay(LCD_DISPLAY_DELAY);
		// Erase message on lcd
		lcd.noDisplay();
		// wait for specific time
		myDelay(LCD_NO_DISPLAY_DELAY);
	#endif
		return;
}

void lcdTemperature(){
	#ifdef DEBUGGING_ON
		Serial.println(F("DB: LCD << TEMPERATURE READING"));
	#endif
	#ifdef LIQUID_CRYSTAL_DISPLAY_CONNECTED
		#ifdef TEMP_SENSOR_CONNECTED
			float temp = 0;
			temp = analogRead(TEMP_SENSOR_PIN);
			temp = temp/9.31;		
			lcd.clear();
			lcd.print(F(LCD_TEMPERATURE));
			lcd.setCursor(0,1);
			lcd.print(temp, 2);
			lcd.display();
			// Display message for specific tim
			myDelay(LCD_DISPLAY_DELAY);
			// Erase message on lcd
			lcd.noDisplay();
			// wait for specific time
			myDelay(LCD_NO_DISPLAY_DELAY);
		#else

		#endif
	#endif
	return;
}

void lcdDateAndTime(){
	#ifdef LIQUID_CRYSTAL_DISPLAY_CONNECTED
		#ifdef GPS_MODULE_CONNECTED
			#ifdef DEBUGGING_ON
				Serial.println(F("DB: LCD << DATE & TIME"));
			#endif
			// Print LCD_TIME first.
			lcd.clear();
			lcd.print(F(LCD_TIME));
			lcd.setCursor(0,1);
			lcd.print(gpsModule.hour, DEC); lcd.print(F(":"));
			lcd.print(gpsModule.minute, DEC); lcd.print(F(":"));
			lcd.print(gpsModule.seconds, DEC);
			lcd.display();
			// Display message for specific tim
			myDelay(LCD_DISPLAY_DELAY);
			// Erase message on lcd
			lcd.noDisplay();
			// wait for specific time
			myDelay(LCD_NO_DISPLAY_DELAY);

			// Print LCD_DATE then.
			lcd.clear();
			lcd.print(F(LCD_DATE));
			lcd.setCursor(0,1);
			lcd.print(gpsModule.day, DEC); lcd.print(F("/"));
			lcd.print(gpsModule.month, DEC); lcd.print(F("/20"));
			lcd.print(gpsModule.year, DEC);
			lcd.display();
			// Display message for specific time
			myDelay(LCD_DISPLAY_DELAY);
			// Erase message on lcd
			lcd.noDisplay();
			// wait for specific time
			myDelay(LCD_NO_DISPLAY_DELAY);
		#endif
	#endif
	return;
}

void lcdLocation(){
	#ifdef LIQUID_CRYSTAL_DISPLAY_CONNECTED
		#ifdef GPS_MODULE_CONNECTED
			#ifdef DEBUGGING_ON
				Serial.println(F("DB: LCD << LOCATION"));
			#endif
			lcd.clear();
			lcd.print(F(LCD_LATITUDE));
			lcd.print(gpsModule.latitudeDegrees, 4);
			lcd.setCursor(0,1);
			lcd.print(F(LCD_LONGITUDE));
			lcd.print(gpsModule.longitudeDegrees, 4);
			lcd.display();
			// Display message for specific tim
			myDelay(LCD_DISPLAY_DELAY);
			// Erase message on lcd
			lcd.noDisplay();
			// wait for specific time
			myDelay(LCD_NO_DISPLAY_DELAY);
		#endif
	#endif
	return;
}

void lcdSpeed(){
	#ifdef LIQUID_CRYSTAL_DISPLAY_CONNECTED
		#ifdef GPS_MODULE_CONNECTED
			#ifdef DEBUGGING_ON
				Serial.println(F("DB: LCD << SPEED"));
			#endif
			lcd.clear();
			lcd.print(F(LCD_SPEED));
			lcd.setCursor(0,1);
			lcd.print(gpsModule.speed);
			lcd.print(F(LCD_SPEED_UNIT));
			lcd.display();
			// Display message for specific tim
			myDelay(LCD_DISPLAY_DELAY);
			// Erase message on lcd
			lcd.noDisplay();
			// wait for specific time
			myDelay(LCD_NO_DISPLAY_DELAY);
		#endif
	#endif
	return;
}
