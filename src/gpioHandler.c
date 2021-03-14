#include "gpioHandler.h"
#include <avr/io.h>

short const gpio_table[] ={
	-1,
	PB3,
	PB4,
	-1,
	PB0,
	PB1,
	PB2,
	-1
};

short const gpio_pinToGpio(short const pin)
{
	return gpio_table[pin -1];
}
