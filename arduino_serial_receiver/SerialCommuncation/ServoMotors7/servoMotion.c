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
void downPulse(uint16_t);

void servoInit(void)
{
	DDRD |= SERVO_D;
	DDRB |= THRUSTER_SEVEN;
	timerInit(upPulse, downPulse);
}

void servoPosition(unsigned int servoID, unsigned long pos)
{
	upPulseTime(servoID, pos);
}

void servoPositionArray(uint32_t positions[])
{
	upPulseTimeArray(positions);
}

void servoPositions(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g)
{
	upPulseTimes(a, b, c, d, e, f, g);
}

void upPulse(void)
{
	// pin up for all the servos
	PORTD |= SERVO_D;
	PORTB |= THRUSTER_SEVEN;
}

void downPulse(uint16_t servoID)
{
	// make a switch corresponding to the specific servo
	// pin down
	
	if (servoID == 0)
	{
		PORTD &= ~THRUSTER_ONE;
	}
	else if (servoID == 1)
	{
		PORTD &= ~THRUSTER_TWO;
	}
	else if (servoID == 2)
	{
		PORTD &= ~THRUSTER_THREE;
	}
	else if (servoID == 3)
	{
		PORTD &= ~THRUSTER_FOUR;
	}
	else if (servoID == 4)
	{
		PORTD &= ~THRUSTER_FIVE;
	}
	else if (servoID == 5)
	{
		PORTD &= ~THRUSTER_SIX;
	}
	else if (servoID == 6)
	{
		PORTB &= ~THRUSTER_SEVEN;
	}
}
