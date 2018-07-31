// Include Files
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "uartCallback.h"
#include "servoMotion.h"
#include "vectorInput.h"

// Defines
#define FALSE 0
#define TRUE !FALSE

//void setServoPosition(char* inputOne, char* inputTwo, char* inputThree, char* inputFour, char* inputFive, char* inputSix, char* inputSeven)
//{
	//long numOne = atol(inputOne);
	//long numTwo = atol(inputTwo);
	//long numThree = atol(inputThree);
	//long numFour = atol(inputFour);
	//long numFive = atol(inputFive);
	//long numSix = atol(inputSix);
	//long numSeven = atol(inputSeven);
	//
	//// need work
	//printf("\nSetting servos position to: %ld, %ld, %ld, %ld, %ld, %ld, and %ld\n", numOne, numTwo, numThree, numFour, numFive, numSix, numSeven);
	//
	//servoPositions(numOne, numTwo, numThree, numFour, numFive, numSix, numSeven);
//}

int main(void)
{
	uartCallbackInit();
	servoInit();
	vectorInputInit(servoPositionArray);
	
	foreachLineRead(vectorInputCallback, vectorFilter);

	return 0;
}
