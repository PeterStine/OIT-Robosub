
/*
 * timer.h
 *
 * Created: 7/12/2018 7:09:13 PM
 *  Author: jaysu
 */ 

#ifndef PWMTIMER_H_
#define PWMTIMER_H_

#include <stdio.h>

void timerInit(void (*pulseUpFn)(void), void (*pulseDownFn)(uint16_t));

void upPulseTime(const uint16_t id, const uint32_t uptime);

void upPulseTimes(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g);

void upPulseTimeArray(uint32_t positions[]);

uint32_t scale(uint32_t reading, uint32_t min_in, uint32_t max_in, uint32_t min_out, uint32_t max_out);

#endif