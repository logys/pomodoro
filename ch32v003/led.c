#include "led.h"
#include "ch32v003fun.h"

#define LED_PIN 4
void led_init(void)
{
	RCC->APB2PCENR |= RCC_APB2Periph_GPIOD;
	GPIOD->CFGLR &= ~(0xf<<(4*LED_PIN));
	GPIOD->CFGLR |= (GPIO_Speed_10MHz | GPIO_CNF_OUT_PP)<<(4*LED_PIN);
}

void led_on(void)
{
	GPIOD->BSHR = 1 | (1<<LED_PIN);
}

void led_off(void)
{
	GPIOD->BSHR = (1<<16) | (1<<(16+LED_PIN));
}

void led_toggle(void)
{
	GPIOD->OUTDR ^= (1<<LED_PIN);
}
