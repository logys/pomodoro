#include "hal.h"
#include <util/delay.h>
#include <avr/io.h>

void buzzer_init(void)
{
}

void buzzer_on(void)
{
}

void buzzer_off(void)
{
}

void buzzing(void)
{
	buzzer_on();
	_delay_ms(100);
	buzzer_off();
	_delay_ms(100);
	buzzer_on();
	_delay_ms(100);
	buzzer_off();
	_delay_ms(100);
	buzzer_on();
	_delay_ms(100);
	buzzer_off();
	_delay_ms(100);
}
