/*************************************************************
* Author:			Troy Scevers
* Filename:			uartDriver.c
* Date Created:		03/29/17
* Modifications:	
**************************************************************/
// Defines

// Include Files
#include <avr/io.h>
#include <stdio.h>
#include "uartDriver.h"
#include <util/setbaud.h>

/**********************************************************************
* Purpose: This function initializes the UART driver.
*
* Precondition:		
*     F_CPU must be declared in project or defined
*
* Postcondition:
*      Sets up UART to be used for IO
*
************************************************************************/
void uart_init(void)
{
    UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;

#if USE_2X
    UCSR0A |= _BV(U2X0);
#else
    UCSR0A &= ~(_BV(U2X0));
#endif

    UCSR0C = _BV(UCSZ01) | _BV(UCSZ00); /* 8-bit data */
    UCSR0B = _BV(RXEN0) | _BV(TXEN0);   /* Enable RX and TX */
}

/**********************************************************************
* Purpose: This function sends a character to the uart.
*
* Precondition:
*     stream - FILE stream must be declared before use.
*     c      - Character to send
*
* Postcondition:
*      Returns nothing (return value is for compatablility.
*
************************************************************************/
int uart_putchar(char c, FILE *stream)
{
	if (c == '\n')
	{
		uart_putchar('\r', stream);
	}
	
	loop_until_bit_is_set(UCSR0A, UDRE0);
	UDR0 = c;

	return 0;
}

/**********************************************************************
* Purpose: This function reads a character from the uart.
*
* Precondition:
*     stream - FILE stream must be declared before use.
*
* Postcondition:
*      Returns the character read by the uart as an int (for compatability).
*
************************************************************************/
int uart_getchar(FILE *stream)
{
	loop_until_bit_is_set(UCSR0A, RXC0); /* Wait until data exists. */
	return UDR0;
}
