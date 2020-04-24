#include"stub_io.h"
#include"push_driver.h"

void push_set(short state)
{
	if(state)
		PINB &= ~(1<<PB3);
	else 
		PINB |= 1<<PB3;
}
