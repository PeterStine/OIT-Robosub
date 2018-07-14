/*
 * servoMotion.c
 *
 * Created: 7/11/2018 5:52:25 PM
 *  Author: jaysu
 */ 


#include "servoMotion.h"
#include "pwmTimer.h"

#define DELAY_STEP 20

void upPulse(void);
void downPulse(void);

void servoInit(void)
{
	DDRB |= SERVO_MASK;
	timerInit(upPulse, downPulse);
}

void servoPosition(unsigned long pos)
{
	upPulseTime(pos);
}

void upPulse(void)
{
	// pin up
	PORTB |= SERVO_MASK;
}

void downPulse(void)
{
	// pin down
	PORTB &= ~SERVO_MASK;
}