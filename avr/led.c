#include "hal.h"
#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN PB1

void led_init(void)
{
	DDRB |= 1<<LED_PIN;
}

void led_toggle(void)
{
	PINB |= 1<<LED_PIN;
}

void led_blink(void)
{
	for(int i = 0; i <10 ; i++){
		led_toggle();
		_delay_ms(50);
	}
}

void led_blink_slow(void)
{
	for(int i = 0; i <10 ; i++){
		led_toggle();
		_delay_ms(500);
	}
}
