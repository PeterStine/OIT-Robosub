/*
 * TextToHex.c
 *
 * Created: 7/12/2018 8:09:45 PM
 * Author : jaysu
 */ 

// Include Files
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include "uartCallback.h"


int main(void)
{
	uartCallbackInit();
	foreachCharRead();
}

