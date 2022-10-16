#include "hal.h"
#include <util/delay.h>
#include <avr/io.h>

#define PIN_BUZZER PD4

void buzzer_init(void)
{
	DDRD |= 1<<PIN_BUZZER;
	PORTD &= ~(1<<PIN_BUZZER);
}

void buzzer_on(void)
{
	PORTD |= (1<<PIN_BUZZER);
}

void buzzer_off(void)
{
	PORTD &= ~(1<<PIN_BUZZER);
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
