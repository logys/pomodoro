#define SYSTEM_CORE_CLOCK 48000000UL

#define VERSION 0.8.0
#include "ch32v003fun.h"

#define APB_CLOCK SYSTEM_CORE_CLOCK 
#include "led.h"
#include "powermode.h"
#include "buzzer.h"
#include "button.h"

int main(void)
{
	SystemInit48HSI();
	led_init();
	powermode_init();
	buzzer_init();
	button_init();
	uint32_t counter = 0;
	powermode_standBy();
	while(1){
		if(counter <= 600)
			counter++;
		else {
			counter = 0;
			led_toggle();
		}
		powermode_sleep();
	}
	return 0;
}
