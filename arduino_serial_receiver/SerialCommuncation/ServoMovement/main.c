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
	printf("\nSetting servo position to: %li\n", num);
	//testServo();
		servoPosition(num, 10);
		//_delay_ms(STEP_DELAY);
		//testServo();
}

int main(void)
{
	uartCallbackInit();
	servoInit();
	testServo();
	
	//testServo();
	foreachLineRead(convertAndPrint);

	return 0;
}
