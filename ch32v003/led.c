#include "led.h"
#include "ch32v003fun.h"

#define PIN_LED 4
void led_init(void)
{
	RCC->APB2PCENR |= RCC_APB2Periph_GPIOD;
	GPIOD->CFGLR &= ~(0xf<<(4*PIN_LED));
	GPIOD->CFGLR |= (GPIO_Speed_10MHz | GPIO_CNF_OUT_PP)<<(4*PIN_LED);
}

void led_on(void)
{
	GPIOD->BSHR = 1 | (1<<PIN_LED);
}

void led_off(void)
{
	GPIOD->BSHR = (1<<16) | (1<<(16+PIN_LED));
}

void led_toggle(void)
{
	GPIOD->OUTDR ^= (1<<PIN_LED);
}
