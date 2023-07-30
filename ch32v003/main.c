#define SYSTEM_CORE_CLOCK 48000000UL

#define VERSION 0.8.0
#include "ch32v003fun.h"

#define APB_CLOCK SYSTEM_CORE_CLOCK 
#include "led.h"
#include "powermode.h"

int main(void)
{
	SystemInit48HSI();
	led_init();
	powermode_init();
	while(1){
		led_toggle();
		powermode_standBy();
	}
	return 0;
}
