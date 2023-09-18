#define SYSTEM_CORE_CLOCK 48000000UL

#define VERSION 0.8.0
#include "ch32v003fun.h"

#define APB_CLOCK SYSTEM_CORE_CLOCK 
#include "led.h"
#include "powermode.h"
#include "buzzer.h"
#include "button.h"
#include "tasks/input.h"
#include "tasks/pomodoro.h"

int main(void)
{
	SystemInit48HSI();
	led_init();
	buzzer_init();
	button_init();
	powermode_init();
	input_init();
	pomodoro_init(1);
	while(1){
		input_doIt();
		pomodoro_doIt();
		powermode_sleep();
	}
	return 0;
}
