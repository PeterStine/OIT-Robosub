// Include Files
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include "uartDriver.h"

// Defines
#define FALSE 0
#define TRUE !FALSE
//#define BLUE_MASK (1 << DDB0)
//#define GREEN_MASK (1 << DDB1)
//#define RED_MASK (1 << DDB2)

int main(void)
{
	
	//Set the Outputs for the RGB LED
	//DDRB |= BLUE_MASK | RED_MASK | GREEN_MASK;	
	
	// Create File Pointers for in and out
	FILE uart_output = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);
	FILE uart_input = FDEV_SETUP_STREAM(NULL, uart_getchar, _FDEV_SETUP_READ);

	// Initialize the UART Driver
	uart_init();

	// Hijack STDIN/STDOUT and send then to the UART Driver
	stdout = &uart_output;
	stdin  = &uart_input;

	// Char used for getting info from UART
	char input;

	/* Replace with your application code */
	while (TRUE)
	{
		printf("\nPlease enter a character: ");
		input = getchar();
		printf("\nYou wrote %c\n", input);
		
		printf("\nIn ASCII: %X\n", input);
	}
	return 0;
}
