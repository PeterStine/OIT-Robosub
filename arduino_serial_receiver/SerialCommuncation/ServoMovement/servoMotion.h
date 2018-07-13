
/*
 * servoMotion.h
 *
 * Created: 7/11/2018 5:06:18 PM
 *  Author: jaysu
 */ 

#ifndef SERVOMOTION_H_
#define SERVOMOTION_H_

/// Include Files
#include <avr/io.h>
#include <util/delay.h>

// Defines
#define FALSE 0
#define TRUE !FALSE
#define SERVO_MASK (1 << DDB1)
#define STEP_DELAY 1000
#define POSITION_DELAY 1500

void servoInit(void);
void servoPosition(unsigned long pos, int pulses);
void testServo(void);


#endif