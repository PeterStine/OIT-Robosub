// Include Files
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include "uartCallback.h"
#include "servoMotion.h"

// Defines
#define FALSE 0
#define TRUE !FALSE

void convertAndPrint(char* input)
{
	long num = atol(input);
	printf("\nSetting servo position to: %ld\n", num);
	servoPosition(num);
}

int main(void)
{
	uartCallbackInit();
	servoInit();
	
	foreachLineRead(convertAndPrint);

	return 0;
}
