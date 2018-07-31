/*
 * VectorSetup.c
 *
 * Created: 7/19/2018 9:58:22 AM
 *  Author: jaysu
 */ 

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "vectorInput.h"

#define NUM_ELEMENTS 7

void (*vectorCallback)(uint32_t[]);

uint32_t vectorArray[NUM_ELEMENTS];

void vectorInputInit(void (*vectorCallBackFn)(uint32_t[]))
{
	vectorCallback = vectorCallBackFn;
}

void vectorInputCallback(char input[])
{
	// Format: <42, -42, -32>
	int inputIndex = 0;
	int bufferIndex = 0;
	int vecIndex = 0;
	
	char buffer[10];
	while (input[inputIndex] != '\0')
	{
		if (isdigit(input[inputIndex]))
		{
			buffer[bufferIndex] = input[inputIndex];
			buffer[bufferIndex + 1] = '\0';
			bufferIndex++;
		}
		else if (vecIndex < NUM_ELEMENTS && (input[inputIndex] == ',' || input[inputIndex] == '>' || input[inputIndex] == '\0'))
		{
			// printf("\n%d\t%s", vecIndex, buffer);
			vectorArray[vecIndex] = atoi(buffer);
			buffer[0] = '\0';
			bufferIndex = 0;
			vecIndex++;
		}
		inputIndex++;
	}
	inputIndex = 0;
	vecIndex = 0;
	
	//printf("\n");
	//for (int i = 0; i < NUM_ELEMENTS; i++)
	//{
		//printf("%ld, ", vectorArray[i]);
	//}
	//printf("\n");
	
	vectorCallback(vectorArray);
}

int vectorFilter(int c)
{
	//printf("\nIndicate: %d\n", c);
	return isdigit(c) || c == '<' || c == ',' || c == '>' || c == ' ';
}