#include "button.h"
#include <avr/io.h>
#include <stdint.h>

#define NOTANUMBER -1

static short pin;

static uint8_t gpioarray[] = {NOTANUMBER, PB3, PB4, NOTANUMBER, PB0, PB1, PB2, NOTANUMBER};

void button_init(const short pin_injected)
{
	uint8_t gpio_pin = gpioarray[pin_injected - 1];
	pin = gpio_pin;
//	button->pin = pin;
	DDRB &= ~(1<<(gpio_pin));
	PORTB |= 1<<gpio_pin; //whit pullUp
}

bool button_read(void)
{
	return PINB&(1<<pin)?false:true;
}
