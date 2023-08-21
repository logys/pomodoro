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
	while(1){
		if(button_pushed()){
			led_on();
		}else {
			led_off();
		}
		powermode_standBy();
	}
	return 0;
}
