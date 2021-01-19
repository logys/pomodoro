#include "button.h"
#include <avr/io.h>

void button_create(Button * button, short pin)
{
	button->pin = pin;
	DDRB &= ~(1<<pin);
	PORTB &= ~(1<<pin); //whitout pullUp
}
short button_read(void)
{
	return 0;
}
