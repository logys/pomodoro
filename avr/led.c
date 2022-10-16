#include "hal.h"
#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN PD2

void led_init(void)
{
	DDRD |= 1<<LED_PIN;
}

void led_toggle(void)
{
	PIND |= 1<<LED_PIN;
}

void led_blink(void)
{
	for(int i = 0; i <10 ; i++){
		led_toggle();
		_delay_ms(50);
	}
}
