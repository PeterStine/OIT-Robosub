
/*
 * timer.h
 *
 * Created: 7/12/2018 7:09:13 PM
 *  Author: jaysu
 */ 

#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>

void timer_init(void);

void startSei(void);

void Servo(int value);

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
		PORTD |= SERVO_MASK;

		// Reset The Number of Overflows back to 0
		numOverflows = 0;

		// Reset Counter
		TCNT0 = 0;
	}
}

ISR(TIMER0_COMPA_vect)
{
	// Turn Off Servo Control Line
	PORTD &= ~SERVO_MASK;
}

#endif