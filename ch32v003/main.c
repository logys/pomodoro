#define SYSTEM_CORE_CLOCK 48000000UL

#define VERSION 0.8.0
#include "ch32v003fun.h"

#define APB_CLOCK SYSTEM_CORE_CLOCK 

int main(void)
{
	uint32_t count=0;
	SystemInit48HSI();
	RCC->APB2PCENR |= RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOC;
	GPIOD->CFGLR &= ~(0xf<<(4*0));
	GPIOD->CFGLR |= (GPIO_Speed_10MHz | GPIO_CNF_OUT_PP)<<(4*0);
	GPIOD->CFGLR &= ~(0xf<<(4*4));
	GPIOD->CFGLR |= (GPIO_Speed_10MHz | GPIO_CNF_OUT_PP)<<(4*4);
	GPIOC->CFGLR &= ~(0xf<<(4*0));
	GPIOC->CFGLR |= (GPIO_Speed_10MHz | GPIO_CNF_OUT_PP)<<(4*0);
	while(1){
		GPIOD->BSHR = 1 | (1<<4);        // Turn on GPIOs
                GPIOC->BSHR = 1;
                Delay_Ms( 250 );
                GPIOD->BSHR = (1<<16) | (1<<(16+4)); // Turn off GPIODs
                GPIOC->BSHR = (1<<16);
                Delay_Ms( 250 );
                count++;

	}
	return 0;
}
