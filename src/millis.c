/** \file 
 * ot
 * \brief  Funciones para calcular el tiempo*/

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

#include"millis.h"
#include<stdbool.h>
#include<avr/io.h>
#include<avr/interrupt.h>

volatile uint32_t tiempo = 0;
bool alreadyInit = false;
uint32_t millis(void)
{
	uint32_t tmp = 0;
	uint8_t oldSREG = 0;
	oldSREG = SREG;
	SREG &= ~(1<<7);
	tmp = tiempo;
	SREG = oldSREG;
	return tmp;
}

void millis_init(void)
{
	/* CLKPR divide frequency to 1 Mhz */
	CLKPR |= (1<<CLKPS0)|(1<<CLKPS1);
	/* PLLCSR quit pll*/
	PLLCSR &= ~(1<<PCKE);
	/* Prescale to 4, set's tick to 4us */
	TCCR1 |= (1<<CS11)|(1<<CS10);
	TCCR1 &= ~((1<<CS12)|(1<<CS13));
	/* 4us times 250 equal to 1ms */
	OCR1A = 249;
	/* Enable global Interrupt */
	SREG |= (1<<7);
	/* Enable compare interrupt channel A */
	TIMSK |= (1<<OCIE1A);

	tiempo = 0;
}

void millis_reinit(void)
{
	uint8_t oldSREG = 0;
	oldSREG = SREG;
	SREG &= ~(1<<7);
	tiempo = 0;
	SREG = oldSREG;
}

ISR(TIM1_COMPA_vect)
{
	TCNT1=0;
	tiempo++;
}
