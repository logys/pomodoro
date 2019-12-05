#include "apagar.h"

void apagar(void)
{
	sei();	
	GIMSK |= 1<<PCIE;
	PCMSK |= 1<<PCINT3;
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);
	sleep_mode();
}

ISR(PCINT0_vect)
{
	PCMSK &=~(1<<PCINT3);
}
