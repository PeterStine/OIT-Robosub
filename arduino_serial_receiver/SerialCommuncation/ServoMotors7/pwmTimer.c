
/*
 * Timer.h
 *
 * Created: 7/12/2018 6:34:44 PM
 *  Author: jaysu
 */ 
#include <avr/interrupt.h>
#include "pwmTimer.h"

#define NUM_PORTS 7

void (*pulseDown)(uint16_t);
void (*pulseUp)(void);

struct inputMapElement
{
	uint8_t id;
	uint32_t timeDown;
};

static struct inputMapElement inputMap[NUM_PORTS];
static struct inputMapElement currentMap[NUM_PORTS];

int mapIdx = 0;

void timerInit(void (*pulseUpFn)(void), void (*pulseDownFn)(uint16_t))
{
	pulseDown = pulseDownFn;
	pulseUp = pulseUpFn;
	
	TCCR0B |= (1 << CS02);							// Setup Prescaler to 256, 8 bit
	OCR0A = 29;										// Setup Compare Register A
	TIMSK0 |= ((1 << OCIE0A) | (1 << TOIE0));		// Enable Overflow and compare register A interrupts
	TCNT0 = 0;
	
	sei();
}

void upPulseTime(const uint16_t id, const uint32_t uptime)
{
	uint32_t scaledValue = scale(uptime, 1150, 1850, 30, 142);
	printf("Scaled value: %ld\n", scaledValue);
	
	// need to find specific servo
	OCR0A = scaledValue;
}

void sort(struct inputMapElement input[])
{
	uint8_t a;
	uint32_t b;
	
	for (int i = 0; i < NUM_PORTS; i++)
	{
		for (int j = i + 1; j < NUM_PORTS; j++)
		{
			if (input[i].timeDown > input[j].timeDown)
			{
				a = input[i].id;
				b = input[i].timeDown;
				
				input[i].id = input[j].id;
				input[i].timeDown = input[j].timeDown;
				
				input[j].id = a;
				input[j].timeDown = b;
			}
		}
	}
}

void upPulseTimes(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e, uint32_t f, uint32_t g)
{
	inputMap[0].id = 0;
	inputMap[0].timeDown = scale(a, 1150, 1850, 30, 142);
	inputMap[1].id = 1;
	inputMap[1].timeDown = scale(b, 1150, 1850, 30, 142);
	inputMap[2].id = 2;
	inputMap[2].timeDown = scale(c, 1150, 1850, 30, 142);
	inputMap[3].id = 3;
	inputMap[3].timeDown = scale(d, 1150, 1850, 30, 142);
	inputMap[4].id = 4;
	inputMap[4].timeDown = scale(e, 1150, 1850, 30, 142);
	inputMap[5].id = 5;
	inputMap[5].timeDown = scale(f, 1150, 1850, 30, 142);
	inputMap[6].id = 6;
	inputMap[6].timeDown = scale(g, 1150, 1850, 30, 142);
	
	sort(inputMap);
}

void printTable(void)
{
	printf("\nid\tport\n");
	for (int i = 0; i < NUM_PORTS; i++)
	{
		printf("%d\t%ld\n", inputMap[i].id, inputMap[i].timeDown);
	}
}

void upPulseTimeArray(uint32_t positions[])
{
	for (int i = 0; i < NUM_PORTS; i++)
	{
		inputMap[i].id = i;
		inputMap[i].timeDown = scale(positions[i], 1150, 1850, 30, 142);
	}
	
	// printTable();
	
	sort(inputMap);
	
	printTable();
}

void copyMap(void)
{
	for (int i = 0; i < NUM_PORTS; i++)
	{
		currentMap[i].id = inputMap[i].id;
		currentMap[i].timeDown = inputMap[i].timeDown;
	}
}

uint32_t scale(uint32_t reading, uint32_t min_in, uint32_t max_in,
uint32_t min_out, uint32_t max_out)
{
	uint32_t sc = (((reading - min_in) * (max_out - min_out)) / (max_in - min_in)) + min_out;
	if (reading < min_in)
	{
		sc = 30;
	}
	if (reading > max_in)
	{
		sc = 142;
	}
	return sc;
}

ISR(TIMER0_OVF_vect)
{
	// Control Variables
	static int numOverflows = 0;
	//static int8_t dir = 1;

	// Increment the number of overflows
	numOverflows++;

	// Once we have reached 5 overflows set the PIN High
	if(numOverflows == 5)
	{
		copyMap();
		
		mapIdx = 0;
		
		OCR0A = currentMap[0].timeDown;
		
		// Servo high
		pulseUp();

		// Reset The Number of Overflows back to 0
		numOverflows = 0;

		// Reset Counter
		TCNT0 = 0;
	}
}

ISR(TIMER0_COMPA_vect)
{
	// Scan current map which ids to pulse down
	
	int currentTD = currentMap[mapIdx].timeDown;
	while (mapIdx < NUM_PORTS && currentMap[mapIdx].timeDown == currentTD)
	{
		// Turn Off Servo Control Line
		pulseDown(currentMap[mapIdx].id);
		
		mapIdx++;
	}
	if (mapIdx < NUM_PORTS)
	{
		OCR0A = currentMap[mapIdx].timeDown;
	}
}