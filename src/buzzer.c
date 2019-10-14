#ifdef TEST
	#include "stub_io.h"
#elif ATTINY
	#include<avr/io.h>
#else
#include<libopencm3/stm32/gpio.h>
#include<libopencm3/stm32/rcc.h>
#endif

#include"buzzer.h"

void buzzer(int8_t ticks, int32_t  tiempoms)
{
	if(ticks <= 0 || tiempoms <= 0)
		return;
	if(ticks > 10)
		ticks = 10;
	if(tiempoms > 1000)
		tiempoms = 1000;
	for(uint8_t i = 0; i < ticks*2; i++){
		delay(tiempoms);
		toggle();
	}
}

//Drivers ATTINY
#ifdef ATTINY
void openBuzzer(void)
{
	        /* Inicia el driver buzzer*/
	        DDRB |= (1<<PB1);
	        PORTB &= ~(1<<PB1);
}
void closeBuzzer(void)
{
        /*Inicia el driver buzzer*/
        DDRB &= ~(1<<PB1);
        PORTB &= ~(1<<PB1);
}
/*Buzzer encendido y apagado*/
void writeBuzz(short const estado)
{
        if(estado == ON)
                PORTB |= (1<<PB1);
        else if(estado == OFF)
                PORTB &= ~(1<<PB1);
}
unsigned short readBuzz(void)
{
        /*Regresa el estado del buzzer*/
        return PINB&(1<<PB1)?ON:OFF;
}
//End drivers ATTINY
#else
//Drivers STM32
void openBuzzer(void)
{
	/* Inicia el driver buzzer PA1 output*/
	rcc_periph_clock_enable(RCC_GPIOA);
	gpio_mode_setup(GPIOA,
			GPIO_MODE_OUTPUT,
			GPIO_PUPD_NONE,
			GPIO1);
}
void closeBuzzer(void)
{
        /*Inicia el driver buzzer*/
	gpio_mode_setup(GPIOA,
			GPIO_MODE_INPUT,
			GPIO_PUPD_NONE,
			GPIO1);

}
/*Buzzer encendido y apagado*/
void writeBuzz(short const estado)
{
        if(estado == ON)
		gpio_set(GPIOA, GPIO1);
        else if(estado == OFF)
		gpio_clear(GPIOA, GPIO1);
}
unsigned short readBuzz(void)
{
        /*Regresa el estado del buzzer*/
        return gpio_get(GPIOA, GPIO1);
}
//End drivers stm32
#endif

void toggle(void)
{
	PINB |= 1<<PB1;
}
