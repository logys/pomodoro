#include "poweroff.h"
#include <avr/sleep.h>
#include <avr/io.h>
#include "led.h"
#include "buzzer.h"
#include <avr/interrupt.h>
#include "pomodoro.h"

static bool * finished;

void poweroff_init(bool * const finished_injected)
{
	finished = finished_injected;
}

void poweroff(void)
{
	if(!*finished)
		return ;
	buzzer_off();
	led_off();
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);
	sei();
	/* configure low level interrupt */
	MCUCR &= ~(1<<ISC01 | 1<<ISC00);
	/* Enable low level interrupt */
	GIMSK |= 1<<INT0;
	sleep_mode();
}

ISR(INT0_vect)
{
	GIMSK &= ~(1<<INT0);
	pomodoro_reinit();
}
