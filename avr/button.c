#include "button.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>

#define BUTTON_PIN PB0

void button_init(void)
{
	DDRB &= ~(1<<BUTTON_PIN);
	PORTB |= 1<<BUTTON_PIN;

	sei();
	GIMSK |= 1<<PCIE;
	PCMSK |= 1<<PCINT0;
}

bool button_pushed(void)
{
	return PINB & (1<<BUTTON_PIN) ? false : true;
}

ISR(PCINT0_vect)
{
}

