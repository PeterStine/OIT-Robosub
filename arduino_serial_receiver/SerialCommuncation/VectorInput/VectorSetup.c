/*
 * VectorSetup.c
 *
 * Created: 7/19/2018 9:58:22 AM
 *  Author: jaysu
 */ 

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_ELEMENTS 3

int vectorArray[NUM_ELEMENTS];

void vectorInputCallback(char input[])
{
	// Format: <42, -42, -32>
	int inputIndex = 0;
	int bufferIndex = 0;
	int vecIndex = 0;
	
	char buffer[10];
	while (input[inputIndex] != '\0')
	{
		if (isdigit(input[inputIndex]) || input[inputIndex] == '-')
		{
			buffer[bufferIndex] = input[inputIndex];
			buffer[bufferIndex + 1] = '\0';
			bufferIndex++;
		}
		else if (vecIndex < NUM_ELEMENTS && (input[inputIndex] == ',' || input[inputIndex] == '>' || input[inputIndex] == '\0'))
		{
			vectorArray[vecIndex] = atoi(buffer);
			buffer[0] = '\0';
			bufferIndex = 0;
			vecIndex++;
		}
		inputIndex++;
	}
	inputIndex = 0;
	vecIndex = 0;
	// Does not cover: "42, 42, 4-2"
	printf("\n\nReceived <%d, %d, %d>\n", vectorArray[0], vectorArray[1], vectorArray[2]);
}

int vectorFilter(int c)
{
	//printf("\nIndicate: %d\n", c);
	return isdigit(c) || c == '<' || c == ',' || c == '>' || c == ' ' || c == '-';
}