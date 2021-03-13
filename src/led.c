#include"led.h"
#include<stdlib.h>
#include<avr/io.h>

short pines[8] ={
	-1,
	PB3,
	PB4,
	-1,
	PB0,
	PB1,
	PB2,
	-1
};

short gpio_pin;

void led_open(short const led_pin)
{
	gpio_pin = pines[led_pin - 1];
	DDRB |= 1<<gpio_pin;
	PORTB &= ~(1<<gpio_pin);
}

void led_off(void)
{
	PORTB &= ~(1<<gpio_pin);
}

void led_on(void)
{
	PORTB |= 1<<gpio_pin;
}
