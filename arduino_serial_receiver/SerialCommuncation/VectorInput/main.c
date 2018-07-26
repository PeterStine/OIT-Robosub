/*
 * VectorInput.c
 *
 * Created: 7/19/2018 9:53:07 AM
 * Author : jaysu
 */ 

#include <avr/io.h>
#include "VectorSetup.h"
#include "uartCallback.h"


int main(void)
{
	uartCallbackInit();
	
    foreachLineRead(vectorInputCallback, vectorFilter);
}

