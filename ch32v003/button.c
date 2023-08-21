#include "button.h"
#include "ch32v003fun.h"
#include <stdbool.h>

#define BUTTON_PIN 6

void button_init(void)
{
	RCC->APB2PCENR |= RCC_APB2Periph_GPIOD;
	GPIOD->CFGLR &= ~(0xf<<(4*BUTTON_PIN));
	GPIOD->CFGLR |= (GPIO_SPEED_IN | GPIO_CNF_IN_PUPD)<<(4*BUTTON_PIN);
	GPIOD->OUTDR |= (1<<BUTTON_PIN);
}

bool button_pushed(void)
{
	return (GPIOD->INDR & GPIO_Pin_6) ? false: true;
}
