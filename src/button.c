#include "button.h"
#include <avr/io.h>
#include <stdint.h>
#define NOTANUMBER -1

static uint8_t gpioarray[] = {NOTANUMBER, PB3, PB4, NOTANUMBER, PB0, PB1, PB2, NOTANUMBER};

Button button_create(short pin)
{
	uint8_t gpio_pin = gpioarray[pin - 1];
//	button->pin = pin;
	DDRB &= ~(1<<(gpio_pin));
	PORTB |= 1<<gpio_pin; //whit pullUp
	return (Button){.pin=gpio_pin};
}
BUTTON_STATE button_read(Button * button)
{
	return PINB&(1<<button->pin)?OFF:ON;
}
