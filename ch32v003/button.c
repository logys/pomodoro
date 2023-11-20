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

	GPIOD->CFGLR &= ~(0xf<<(4*PD7));
	GPIOD->CFGLR |= (GPIO_SPEED_IN | GPIO_CNF_IN_PUPD)<<(4*PD7);
	GPIOD->OUTDR |= (1<<PD7);

	GPIOD->CFGLR &= ~(0xf<<(4*PD3));
	GPIOD->CFGLR |= (GPIO_SPEED_IN | GPIO_CNF_IN_PUPD)<<(4*PD3);
	GPIOD->OUTDR |= (1<<PD3);

	GPIOD->CFGLR &= ~(0xf<<(4*PD2));
	GPIOD->CFGLR |= (GPIO_SPEED_IN | GPIO_CNF_IN_PUPD)<<(4*PD2);
	GPIOD->OUTDR |= (1<<PD2);

	GPIOD->CFGLR &= ~(0xf<<(4*PD0));
	GPIOD->CFGLR |= (GPIO_SPEED_IN | GPIO_CNF_IN_PUPD)<<(4*PD0);
	GPIOD->OUTDR |= (1<<PD0);

	RCC->APB2PCENR |= RCC_APB2Periph_GPIOC;
	GPIOC->CFGLR &= ~(0xf<<(4*PC0));
	GPIOC->CFGLR |= (GPIO_SPEED_IN | GPIO_CNF_IN_PUPD)<<(4*PC0);
	GPIOC->OUTDR |= (1<<PC0);

	GPIOC->CFGLR &= ~(0xf<<(4*PC1));
	GPIOC->CFGLR |= (GPIO_SPEED_IN | GPIO_CNF_IN_PUPD)<<(4*PC1);
	GPIOC->OUTDR |= (1<<PC1);

	GPIOC->CFGLR &= ~(0xf<<(4*PC2));
	GPIOC->CFGLR |= (GPIO_SPEED_IN | GPIO_CNF_IN_PUPD)<<(4*PC2);
	GPIOC->OUTDR |= (1<<PC2);

	GPIOC->CFGLR &= ~(0xf<<(4*PC3));
	GPIOC->CFGLR |= (GPIO_SPEED_IN | GPIO_CNF_IN_PUPD)<<(4*PC3);
	GPIOC->OUTDR |= (1<<PC3);

	GPIOC->CFGLR &= ~(0xf<<(4*PC4));
	GPIOC->CFGLR |= (GPIO_SPEED_IN | GPIO_CNF_IN_PUPD)<<(4*PC4);
	GPIOC->OUTDR |= (1<<PC4);

	GPIOC->CFGLR &= ~(0xf<<(4*PC5));
	GPIOC->CFGLR |= (GPIO_SPEED_IN | GPIO_CNF_IN_PUPD)<<(4*PC5);
	GPIOC->OUTDR |= (1<<PC5);

	GPIOC->CFGLR &= ~(0xf<<(4*PC6));
	GPIOC->CFGLR |= (GPIO_SPEED_IN | GPIO_CNF_IN_PUPD)<<(4*PC6);
	GPIOC->OUTDR |= (1<<PC6);

	GPIOC->CFGLR &= ~(0xf<<(4*PC7));
	GPIOC->CFGLR |= (GPIO_SPEED_IN | GPIO_CNF_IN_PUPD)<<(4*PC7);
	GPIOC->OUTDR |= (1<<PC7);

	RCC->APB2PCENR |= RCC_APB2Periph_GPIOA;
	GPIOA->CFGLR &= ~(0xf<<(4*PA1));
	GPIOA->CFGLR |= (GPIO_SPEED_IN | GPIO_CNF_IN_PUPD)<<(4*PA1);
	GPIOA->OUTDR |= (1<<PA1);

	GPIOA->CFGLR &= ~(0xf<<(4*PA2));
	GPIOA->CFGLR |= (GPIO_SPEED_IN | GPIO_CNF_IN_PUPD)<<(4*PA2);
	GPIOA->OUTDR |= (1<<PA2);
}

bool button_pushed(void)
{
	return (GPIOD->INDR & GPIO_Pin_6) ? false: true;
}
