#define SYSTEM_CORE_CLOCK 48000000UL

#define VERSION 0.8.0
#include "ch32v003fun.h"

#define APB_CLOCK SYSTEM_CORE_CLOCK 
#include "led.h"

int main(void)
{
	SystemInit48HSI();
	led_init();
	while(1){
		led_on();
                Delay_Ms( 250 );
		led_off();
                Delay_Ms( 250 );
	}
	return 0;
}
