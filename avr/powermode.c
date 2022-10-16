#include "hal.h"
#include <avr/interrupt.h>
#include <avr/sleep.h>

void standBy(void)
{
	sei();
	PCICR |= 1<<PCIE2;
	PCMSK2 |= 1<<PCINT19;
	set_sleep_mode(SLEEP_MODE_STANDBY);
	sleep_mode();
	PCMSK2 &= ~(1<<PCINT19);
}

void idle(void)
{
}
