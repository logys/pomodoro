#include"led.h"
#ifdef ATTINY
#include<avr/io.h>
#else
#include<libopencm3/stm32/gpio.h>
#include<libopencm3/stm32/rcc.h>
#include<libopencm3/stm32/timer.h>
#endif

#include"delay.h"
#include<stdlib.h>

//Drivers attiny
#ifdef ATTINY
void openLed()
{
	/*Inicia el driver Led*/
	DDRB |= (1<<PB0);
	PORTB &= ~(1<<PB0);
	TCCR0A |= (1<<COM0A1)|(1<<WGM00);
	TCCR0B |= (1<<CS00);
	OCR0A = 0;
}
void closeLed()
{
	/*Inicia el driver Led*/
	DDRB &= ~(1<<PB0);
	PORTB &= ~(1<<PB0);
	TCCR0A &= ~((1<<COM0A1)|(1<<WGM00));
	TCCR0B &= ~(1<<CS00);
	OCR0A = 0;
}

void writeLed(double intensidad)
{
	/*Intensidad del LED PWM 0-100*/
	if(intensidad > 100)
		intensidad = 100;
	else if(intensidad < 0)
		intensidad = 0;
	/*set PWM*/
	OCR0A =(int)(intensidad*255/(double)100);
}

void toggleLed()
{
	for(uint8_t i = 0; i < 6; i++){
		if(OCR0A < 255)
			writeLed(100);
		else
			writeLed(0);
		delay(40);
	}
}
//End drivers ATTINY
#else
//Drivers STM32
void openLed()
{
	/*Inicia el driver Led*/
	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_TIM14);
	gpio_mode_setup(GPIOA,
			GPIO_MODE_AF,
			GPIO_PUPD_NONE,
			GPIO4);
	timer_set_mode(	TIM14,
			TIM_CR1_CKD_CK_INT,
			TIM_CR1_CMS_EDGE,
			TIM_CR1_DIR_UP);
	timer_set_oc_mode(	TIM14,
				TIM_OC1,
				TIM_OCM_PWM1);
	gpio_set_af(GPIOA, GPIO_AF4, GPIO4);
	timer_enable_oc_output(TIM14, TIM_OC1);
	timer_set_prescaler(TIM14, 47);
	timer_set_period(TIM14, 16000);
	timer_set_oc_value(TIM14, TIM_OC1, 16000);
	timer_enable_counter(TIM14);
}
void closeLed()
{
	/*Inicia el driver Led*/
	rcc_periph_clock_disable(RCC_TIM14);
	timer_disable_counter(TIM14);
}

void writeLed(double intensidad)
{
	/*Intensidad del LED PWM 0-100*/
	if(intensidad > 100)
		intensidad = 100;
	else if(intensidad < 0)
		intensidad = 0;
	/*set PWM*/
	timer_set_oc_value(TIM14, TIM_OC1, (intensidad/100.0)*16000);
}

void toggleLed()
{
	timer_set_oc_value(TIM14, TIM_OC1, (100/100.0)*16000);
	delay(40);
	timer_set_oc_value(TIM14, TIM_OC1, (0/100.0)*16000);
	delay(40);
}
//End drivers stm32
#endif
