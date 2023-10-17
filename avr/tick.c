#include <avr/interrupt.h>
#include "tick.h"

void tick_init(void)
{
	/* Cleat time on conpare configured */
	TCCR0A = (1U << WGM01) | (0U << WGM00);
	/* prescaler 8 128k/8 => 16k*/
    	TCCR0B = (0U << CS02 ) | (1U << CS01) | (0U << CS00); // 128k/8
    	TIMSK = (1U << OCIE0A); /* Enable TIMER2 compare Interrupt */
    	TCNT0 = 0U;
    	OCR0A = 159; //160 ticks for 10ms interrupt
}

ISR(TIMER0_COMPA_vect) 
{
}
