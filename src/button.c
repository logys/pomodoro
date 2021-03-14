#include "button.h"
#include <avr/io.h>
#include "gpioHandler.h"

static short gpio_pin;

void button_open(const short pin_injected)
{
	gpio_pin = gpio_pinToGpio(pin_injected);

	DDRB &= ~(1<<(gpio_pin));
	PORTB |= 1<<gpio_pin; //whit pullUp
}

bool button_read(void)
{
	return PINB&(1<<gpio_pin)?false:true;
}
