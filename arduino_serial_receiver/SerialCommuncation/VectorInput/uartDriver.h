/*************************************************************
* Author:			Troy Scevers
* Filename:			uartDriver.h
* Date Created:		03/29/17
* Modifications:
**************************************************************/

#ifndef UARTDRIVER_H_
#define UARTDRIVER_H_

// Defines
#define BAUD 9600

// Function Prototypes
void uart_init(void);
int uart_putchar(char c, FILE *stream);
int uart_getchar(FILE *stream);


#endif /* UARTDRIVER_H_ */