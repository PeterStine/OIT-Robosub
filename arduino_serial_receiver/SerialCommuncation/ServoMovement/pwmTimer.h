
/*
 * timer.h
 *
 * Created: 7/12/2018 7:09:13 PM
 *  Author: jaysu
 */ 

#ifndef PWMTIMER_H_
#define PWMTIMER_H_

#include <stdio.h>

void timerInit(void (*pulseUpFn)(void), void (*pulseDownFn)(void));

void upPulseTime(const uint32_t value);

uint32_t scale(uint32_t reading, uint32_t min_in, uint32_t max_in, uint32_t min_out, uint32_t max_out);

#endif