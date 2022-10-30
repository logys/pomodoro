#include "hal.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#define BUTTON_PIN PD3

void button_init(void)
{
	DDRD &= ~(1<<BUTTON_PIN);
	PORTD |= 1<<BUTTON_PIN;

	sei();
	PCICR |= 1<<PCIE2;
	PCMSK2 |= 1<<PCINT19;
}

bool button_pushed(void)
{
	return PIND & (1<<BUTTON_PIN) ? false : true;
}

ISR(PCINT2_vect)
{
}
