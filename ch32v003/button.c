#include "button.h"
#include "ch32fun.h"
#include <stdbool.h>

#define BUTTON_PIN 6

void button_init(void)
{
	RCC->APB2PCENR |= RCC_AFIOEN;
	RCC->APB2PCENR |= RCC_APB2Periph_GPIOD;
	GPIOD->CFGLR &= ~(0xf<<(4*BUTTON_PIN));
	GPIOD->CFGLR |= (GPIO_Speed_In | GPIO_CNF_IN_PUPD)<<(4*BUTTON_PIN);
	GPIOD->OUTDR |= (1<<BUTTON_PIN);

	AFIO->EXTICR |= (uint32_t)(0b11 <<(2*BUTTON_PIN));
	EXTI->EVENR |= EXTI_Line6;
	EXTI->FTENR |= EXTI_Line6;
}

bool button_pushed(void)
{
	return (GPIOD->INDR & GPIO_Pin_6) ? false: true;
}
