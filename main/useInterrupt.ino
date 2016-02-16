// USE INTERRUPT ON TIMER1(16-bit)
void useInterrupt(bool v){
	if(v){
		noInterrupts();		// Disable interrupts(IDE)
	  	TCCR1A = 0;
	  	TCCR1B = 0;
	  	TCNT1 = 0;
	  	OCR1A = 625;			// 625 = (16MHz/256) * 10mS;
	  	TCCR1B |= (1 << WGM12);	// ISR is called every 10ms.
	  	TCCR1B |= (1 << CS12);
	  	TIMSK1 |= (1 << OCIE1A);
	  	interrupts();		// Enable interrupts(IDE)
	}else{
		noInterrupts();
	}
}

// INTERRUPT SERVICE ROUTINE(FOR TIMER1)
ISR(TIMER1_COMPA_vect){
  cli();		// Disable interrupts(AVR_LIB)
  gpsModule.read();
  if(gpsModule.newNMEAreceived()){
    gpsModule.parse(gpsModule.lastNMEA());
  }
  sei();		// Enable interrupts.(AVR_LIB)
}

