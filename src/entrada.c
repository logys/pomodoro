#include<stdint.h>
#include"entrada.h"
#include"delay.h"
#include<stdlib.h>
#ifdef TEST
	#include"stub_io.h"
#elif ATTINY
	#include<avr/io.h>
#elif STM32
	#include<libopencm3/stm32/rcc.h>
	#include<libopencm3/stm32/gpio.h>
#endif

#define APAGA 2
#define TOGGLE 1
#define NADA 0

uint8_t botonEvent(void)
{
	static uint8_t sum = 0;
	static uint8_t estado = 0;
	estado = readPush();
	if(estado == 1)
		return NADA;
	else{
		delay(40);
		while(readPush() == 0){
			sum++;
			if(sum > 50){
				sum = 0;
				return APAGA;
			}
			delay(40);
		}
		sum = 0;
		return TOGGLE;
	}
	return NADA;
}
#ifdef ATTINY
//Drivers Attiny
void openPush(void)
{
        /*Inicia el driver push Buttons*/
        DDRB &= ~(1<<PB3);
        PORTB |= (1<<PB3);
}
void closePush(void)
{
        /*Inicia el driver push Buttons*/
        DDRB &= ~((1<<PB3));
        PORTB &= ~((1<<PB3));
}
/*Push buttons*/
uint8_t readPush(void)
{
        if(PINB&(1<<PB3))
                return 0;
        return 1;
}
#else
//Drivers Stm32f0
void openPush(void)
{
	rcc_periph_clock_enable(RCC_GPIOA);
	gpio_mode_setup(GPIOA,
			GPIO_MODE_INPUT,
			GPIO_PUPD_PULLUP,
			GPIO0);
}
void closePush(void)
{
	gpio_mode_setup(GPIOA,
			GPIO_MODE_INPUT,
			GPIO_PUPD_NONE,
			GPIO0);
}
uint8_t readPush(void)
{
	if(gpio_get(GPIOA, GPIO0))
		return 1;
	return 0;
}
#endif
