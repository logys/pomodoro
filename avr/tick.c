#include "hal.h"
#include <avr/interrupt.h>

void tick_init(void)
{
	TCCR2A = (1U << WGM21) | (0U << WGM20);
    	TCCR2B = (1U << CS22 ) | (1U << CS21) | (1U << CS20); /* 1/2^10 */
    	TIMSK2 = (1U << OCIE2A); /* Enable TIMER2 compare Interrupt */
    	TCNT2  = 0U;
    	OCR2A  = 155;
}

ISR(TIMER2_COMPA_vect) 
{
}
