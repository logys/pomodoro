#include "hal.h"
#include <avr/io.h>

#define BUTTON_PIN PD3

void button_init(void)
{
	DDRD &= ~(1<<BUTTON_PIN);
	PORTD |= 1<<BUTTON_PIN;
}

bool button_pushed(void)
{
	return PIND & (1<<BUTTON_PIN) ? false : true;
}
