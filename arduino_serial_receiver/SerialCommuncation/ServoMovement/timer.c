
/*
 * Timer.h
 *
 * Created: 7/12/2018 6:34:44 PM
 *  Author: jaysu
 */ 

void timer_init(void)
{
	//TCCR0B |= (1 << CS02);							// Setup Prescaler
	//OCR0A = 40;										// Setup Compare Register A
	//TIMSK0 |= ((1 << OCIE0A) | (1 << TOIE0));		// Enable Overflow and compare register A interrupts
	//TCNT0 = 0;
}

void startSei(void)
{
	//sei();
}

void Servo(int value)
{
	//OCR0A = value;
}