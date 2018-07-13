/*
 * servoMotion.c
 *
 * Created: 7/11/2018 5:52:25 PM
 *  Author: jaysu
 */ 


#include "servoMotion.h"

#define DELAY_STEP 20

void servoInit(void) {
	DDRB |= SERVO_MASK;
}

void delay_us(unsigned long us) {
	//_delay_us(2250);
	
	unsigned long steps = us / DELAY_STEP;
	for (unsigned long i = 0; i < steps; i++) {
		_delay_us(DELAY_STEP);
	}
}

void servoPosition(unsigned long pos, int pulses) {
	for (int i = 0; i < pulses; i++) {
	  PORTB |= SERVO_MASK;
	  delay_us(pos);
	  PORTB &= ~SERVO_MASK;
	  _delay_ms(STEP_DELAY);
	}
}

void testServo(void)
{
	//servoInit();

	for (int i = 0; i < 3; i++)
	{
		// Move to First Position
		servoPosition(2250, 1);
		//servoPosition(2100);

		// Stepper Period Delay
		//_delay_ms(STEP_DELAY);
		
		// Move to Second Position
		servoPosition(2000, 1);
		//PORTB |= SERVO_MASK;
		//_delay_us(2000);
		//PORTB &= ~SERVO_MASK;

		// Stepper Period Delay
		//_delay_ms(STEP_DELAY);

		// Move to Third Position
		servoPosition(1500, 1);
		//PORTB |= SERVO_MASK;
		//_delay_us(1500);
		//PORTB &= ~SERVO_MASK;
		
		// Stepper Period Delay
		//_delay_ms(STEP_DELAY);
		
		// Move to Fourth Position
		servoPosition(1000, 1);
		//PORTB|= SERVO_MASK;
		//_delay_us(1000);
		//PORTB &= ~SERVO_MASK;
		
		// Stepper Period Delay
		//_delay_ms(STEP_DELAY);
		
		// Move to Fifth Position
		servoPosition(500, 1);
		//PORTB |= SERVO_MASK;
		//_delay_us(500);
		//PORTB &= ~SERVO_MASK;
		
		// Stepper Period Delay
		//_delay_ms(STEP_DELAY);

	}
}