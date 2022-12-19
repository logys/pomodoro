#include "hal.h"
#include <avr/interrupt.h>

void tick_init(void)
{
	TCCR0A = (1U << WGM01) | (0U << WGM00);
    	TCCR0B = (0U << CS02 ) | (1U << CS01) | (1U << CS00); /* 1/2^10 */
    	TIMSK = (1U << OCIE0A); /* Enable TIMER2 compare Interrupt */
    	TCNT0 = 0U;
    	OCR0A = 156;
}

ISR(TIMER0_COMPA_vect) 
{
}
