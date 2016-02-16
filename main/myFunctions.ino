// myDelay()
void myDelay(long d){
  unsigned long start = millis();
  do{
	    mpu.getAcceleration(&ax, &ay, &az);
	    printAccelData();
	    if(abs(ax) >= MPU6050_THRESHOLD_AX || abs(ay) >= MPU6050_THRESHOLD_AY){
	      Serial.println(F("Accident Occurred."));
	      // Call "postAccidentProcess()" here.
	      delay(10000);		// delay() is optional.
	    }
  }while(millis() - start < d);
}

bool isAccident(void){
	mpu.getAcceleration(&ax, &ay, &az);
	if(abs(ax) >= MPU6050_THRESHOLD_AX || abs(ay) >= MPU6050_THRESHOLD_AY){
		Serial.println(F("Accident Occurred."));
		// Call "postAccidentProcess()" here.
		// delay() is optional.
		delay(10000); // 10 seconds delay for debugging purpose.
	}
}
