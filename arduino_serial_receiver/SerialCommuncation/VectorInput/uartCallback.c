
/*
 * uartComeback.c
 *
 * Created: 7/11/2018 4:35:45 PM
 *  Author: jaysu
 */ 

#include <avr/io.h>
#include <stdio.h>
#include "uartDriver.h"
#include "uartCallback.h"

#define ENTER_KEY '\x0D'
#define DEL_KEY '\x7F'
#define BELL '\x07'
#define LINE_LENGTH 20

void foreachLineRead(void (*inputCallback)(char*), int (*filter)(int))
{
	while(TRUE)
	{
		char input[LINE_LENGTH + 1];
		int i = 0;
		printf("\nPlease enter a vector:\n");
		
		while((input[i] = getchar()) != ENTER_KEY && i < LINE_LENGTH)
		{
			if (input[i] == DEL_KEY)
			{
				if (i > 0)
				{
					printf("%c", input[i--]);
				}
			}
			else if (filter(input[i]))
			{
				printf("%c", input[i++]);
			}
			else {
				printf("%c", BELL);
			}
		}
		
		inputCallback(input);
		
		input[i] = '\0';
		i = 0;
		
		printf("\n");
	}
}

void foreachCharRead(void)
{
	while(TRUE)
	{
		printf("Please input: ");
		char input = getchar();
		
		printf("\nYou wrote %c\n", input);
		
		printf("\nIn ASCII: %X\n", input);
	}
}