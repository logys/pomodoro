#include "push_driver.h"
#ifndef TEST
	#include<avr/io.h>
#else
	#include "stub_io.h"
#endif

#define PIN PB3

void push_init(void)
{
	DDRB &=~(1<<PIN);
	PORTB |= 1<<PIN;
}

void push_close(void)
{
	DDRB &=~(1<<PIN);
	PORTB &=~(1<<PIN);
}

PUSH_STATE push_read(void)
{
	char state = PINB;
	if(state & (1<<PIN))
		return PUSH_OFF;
	else
		return PUSH_ON;
}
