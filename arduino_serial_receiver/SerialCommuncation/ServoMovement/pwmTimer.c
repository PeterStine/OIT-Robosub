
/*
 * Timer.h
 *
 * Created: 7/12/2018 6:34:44 PM
 *  Author: jaysu
 */ 

#include "pwmTimer.h"

void (*pulseDown)(void);
void (*pulseUp)(void);

void timerInit(void (*pulseUpFn)(void), void (*pulseDownFn)(void))
{
	pulseDown = pulseDownFn;
	pulseUp = pulseUpFn;
	
	TCCR0B |= (1 << CS02);							// Setup Prescaler to 256, 8 bit
	OCR0A = 29;										// Setup Compare Register A
	TIMSK0 |= ((1 << OCIE0A) | (1 << TOIE0));		// Enable Overflow and compare register A interrupts
	TCNT0 = 0;
	
	sei();
}

void upPulseTime(const uint32_t value)
{
	uint32_t scaledValue = scale(value, 500, 2500, 30, 142);
	printf("Scaled value: %ld\n", scaledValue);
	OCR0A = scaledValue;
}

uint32_t scale(uint32_t reading, uint32_t min_in, uint32_t max_in,
uint32_t min_out, uint32_t max_out)
{
	uint32_t sc = (((reading - min_in) * (max_out - min_out)) / (max_in - min_in)) + min_out;
	return sc;
}

ISR(TIMER0_OVF_vect)
{
	// Control Variables
	static int numOverflows = 0;
	//static int8_t dir = 1;

	// Increment the number of overflows
	numOverflows++;

	// Once we have reached 5 overflows set the PIN High
	if(numOverflows == 5)
	{
		// Servo high
		pulseUp();

		// Reset The Number of Overflows back to 0
		numOverflows = 0;

		// Reset Counter
		TCNT0 = 0;
	}
}

ISR(TIMER0_COMPA_vect)
{
	// Turn Off Servo Control Line
	pulseDown();
}