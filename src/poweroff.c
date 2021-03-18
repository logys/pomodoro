#include "poweroff.h"
#include <avr/sleep.h>
#include <avr/io.h>
#include "led.h"
#include "buzzer.h"
#include <avr/interrupt.h>

static bool const * finished;

void poweroff_init(bool const * const finished_injected)
{
	finished = finished_injected;
}

void poweroff(void)
{
	if(*finished){
		buzzer_off();
		led_off();
		sei();
		/* Enable PCINT interrupt */
		GIMSK |= 1<<PCIE;
		/* Enable interrupt pin 3 */
		PCMSK |= 1<<PCINT4;
		set_sleep_mode(SLEEP_MODE_PWR_DOWN);
		sleep_mode();
	}
}

ISR(PCINT0_vect)
{
	GIMSK &= ~(1<<PCIE);
	PCMSK &= ~(1<<PCINT4);
}
