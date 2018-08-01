
/*
 * uartComeback.h
 *
 * Created: 7/11/2018 4:35:18 PM
 *  Author: jaysu
 */ 

#ifndef UARTCALLBACK_H_
#define UARTCALLBACK_H_

#include <stdio.h>
#include "uartDriver.h"

#define FALSE 0
#define TRUE !FALSE

/* To be understood! uartCallbackInit() cannot be called from function. It has to be a macro. Why? */
#define uartCallbackInit() \
{ \
	/* Create File Pointers for in and out */ \
	FILE uart_output = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE); \
	FILE uart_input = FDEV_SETUP_STREAM(NULL, uart_getchar, _FDEV_SETUP_READ);   \
	\
	/* Initialize the UART Driver */ \
	uart_init(); \
	\
	/* Hijack STDIN/STDOUT and send then to the UART Driver */ \
	stdout = &uart_output; \
	stdin  = &uart_input; \
}

void foreachLineRead(void (*inputCallback)(char*), int (*filter)(int));

void foreachCharRead(void);

#endif