#include "hal.h"
#include <util/delay.h>
#include <avr/io.h>

#define PIN_BUZZER PB2

void buzzer_init(void)
{
	DDRB |= 1<<PIN_BUZZER;
	PORTB &= ~(1<<PIN_BUZZER);
}

void buzzer_on(void)
{
	PORTB |= (1<<PIN_BUZZER);
}

void buzzer_off(void)
{
	PORTB &= ~(1<<PIN_BUZZER);
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
