#include"led.h"
#include<stdlib.h>
#include<avr/io.h>
#include "gpioHandler.h"

static short gpio_pin;

void led_open(short const led_pin)
{
	gpio_pin = gpio_pinToGpio(led_pin);

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
