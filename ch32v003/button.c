#include "button.h"
#include "ch32v003fun.h"
#include <stdbool.h>

#define BUTTON_PIN 6
#define PD7 7
#define PD3 3
#define PD2 2
#define PD0 0
#define PC0 0
#define PC1 1
#define PC2 2
#define PC3 3
#define PC4 4
#define PC5 5
#define PC6 6
#define PC7 7
#define PA1 1
#define PA2 2

void button_init(void)
{
	RCC->APB2PCENR |= RCC_AFIOEN;
	RCC->APB2PCENR |= RCC_APB2Periph_GPIOD;
	GPIOD->CFGLR &= ~(0xf<<(4*BUTTON_PIN));
	GPIOD->CFGLR |= (GPIO_SPEED_IN | GPIO_CNF_IN_PUPD)<<(4*BUTTON_PIN);
	GPIOD->OUTDR |= (1<<BUTTON_PIN);

	AFIO->EXTICR |= (uint32_t)(0b11 <<(2*BUTTON_PIN));
	EXTI->EVENR |= EXTI_Line6;
	EXTI->FTENR |= EXTI_Line6;
}

bool button_pushed(void)
{
	return (GPIOD->INDR & GPIO_Pin_6) ? false: true;
}
