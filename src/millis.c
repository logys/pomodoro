/** \file 
 * \brief  Funciones para calcular el tiempo*/
#include"millis.h"
#include<stdbool.h>

volatile uint32_t tiempo = 0;
bool alreadyInit = false;

/** \brief Regresa el número de milisegundos desde que se inicio el programa 
 * \code
 * unsigned long a = millis();
 * ...
 * do something
 * ...
 * unsigned long tiempo_transcurrido_ms = millis() - a;
 * \endcode
 * \return unsigned long
 * \note Se reserva timer 1 para esta función
 * */
#ifdef ATTINY
uint32_t millis(void)
{
	if(!alreadyInit)
		return 0;
	uint32_t tmp = 0;
	uint8_t oldSREG = 0;
	oldSREG = SREG;
	cli();
	tmp = tiempo;
	SREG = oldSREG;
	return tmp;
}

void millis_init()
{
		if(alreadyInit)
			return ;
		TCCR1 |= (0<<CS12)|(1<<CS11)|(1<<CS10);
		TCCR1 &= ~(1<<CS12);
		OCR1A = 240;
		sei();
		TIMSK |= (1<<OCIE1A);
		tiempo = 0;
		alreadyInit = true;
}

void millis_destroy(void)
{
	TIMSK &= ~(1<<OCIE1A);
	alreadyInit = false;
}

void reiniciarMillis(void)
{
	static uint8_t oldSREG = 0;
	oldSREG = SREG;
	cli();
	tiempo = 0;
	SREG = oldSREG;
	sei();
}
ISR(TIM1_COMPA_vect)
{
	tiempo++;
}
#elif STM32
//Delay stm32
void initTimer1Millis(void)
{
	rcc_clock_setup_in_hse_8mhz_out_48mhz();
	nvic_enable_irq(NVIC_TIM17_IRQ);
	rcc_periph_clock_enable(RCC_TIM17);
	timer_set_mode(	TIM17,
			TIM_CR1_CKD_CK_INT,
			TIM_CR1_CMS_EDGE,
			TIM_CR1_DIR_UP);
	timer_set_prescaler(TIM17, 47);
	timer_set_period(TIM17, 1000);
	timer_enable_counter(TIM17);
	timer_enable_irq(TIM17, TIM_DIER_UIE);
	tiempo = 0;
}
void tim17_isr(void)
{
	tiempo += 1;
	timer_clear_flag(TIM17, TIM_SR_UIF);
}
uint32_t millis(void)
{
	static volatile uint32_t tmp = 0;
	timer_enable_irq(TIM17, TIM_DIER_UIE);
	tmp = tiempo;
	timer_disable_irq(TIM17, TIM_DIER_UIE);
	return tmp;
}
void reiniciarMillis(void)
{
	timer_enable_irq(TIM17, TIM_DIER_UIE);
	tiempo = 0;
	timer_disable_irq(TIM17, TIM_DIER_UIE);
}
#endif