
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

void foreachLineRead(void (*inputCallback)(char*)) // void (*inputCallback)(char)
{
	while(TRUE) {
		
		char input[5];
		int i = 0;
		printf("\nPlease enter a character: ");
		
		while((input[i] = getchar()) != '\x0D' && i < 10)
		{
			printf("%c", input[i]);
			i++;
		}
		
		inputCallback(input);
		
		input[i] = '\0';
		i = 0;
		
		printf("\n");
		
		
	}
}

void foreachCharRead(void) {
	while(TRUE) {
		printf("Please input: ");
		char input = getchar();
		
		printf("\nYou wrote %c\n", input);
		
		printf("\nIn ASCII: %X\n", input);
		
		//inputCallback(input);
	}
}