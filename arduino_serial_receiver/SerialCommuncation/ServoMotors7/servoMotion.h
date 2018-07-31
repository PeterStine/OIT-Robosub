
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

// Defines
#define FALSE 0
#define TRUE !FALSE

#define THRUSTER_ONE (1 << DDD2)
#define THRUSTER_TWO (1 << DDD3)
#define THRUSTER_THREE (1 << DDD4)
#define THRUSTER_FOUR (1 << DDD5)
#define THRUSTER_FIVE (1 << DDD6)
#define THRUSTER_SIX (1 << DDD7)
#define THRUSTER_SEVEN (1 << DDB1)

#define SERVO_D (THRUSTER_ONE | THRUSTER_TWO | THRUSTER_THREE | THRUSTER_FOUR | THRUSTER_FIVE | THRUSTER_SIX)

#define STEP_DELAY 1000
#define POSITION_DELAY 1500

void servoInit(void);

void servoPositionArray(uint32_t positions[]);

void servoPosition(unsigned int servoID, unsigned long pos);
void servoPositions(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g);


#endif