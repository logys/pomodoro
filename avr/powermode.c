#include "hal.h"
#include <avr/sleep.h>
#include <avr/io.h>

static void unused_pines_as_input_pullup(void);
static void adc_disabled(void);

void powerconfig_init(void)
{
	unused_pines_as_input_pullup();
	adc_disabled();
}

static void unused_pines_as_input_pullup(void)
{
	DDRB &= ~(1<<PB3);
	PORTB |= 1<<PB3;
	DDRB &= ~(1<<PB4);
	PORTB |= 1<<PB4;
}

static void adc_disabled(void)
{
	ADCSRA &= ~(1<<ADEN);
}

void standBy(void)
{
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);
	sleep_mode();
}

void idle(void)
{
	set_sleep_mode(SLEEP_MODE_IDLE);
	sleep_mode();
}
