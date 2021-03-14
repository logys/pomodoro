#include"buzzer.h"
#include<avr/io.h>

short gpio_pin[] ={
	-1,
	PB3,
	PB4,
	-1,
	PB0,
	PB1,
	PB2,
	-1
};
static short pin;

void buzzer_open(short const pin_injected)
{
	pin = gpio_pin[pin_injected-1];
	DDRB |= 1 << pin;
	PORTB &=~ (1 << pin);
}

void buzzer_off(void)
{
	PORTB &= ~(1<<pin);
}

void buzzer_on(void)
{
	PORTB |= 1<<pin;
}
