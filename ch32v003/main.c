#define SYSTEM_CORE_CLOCK 48000000UL

#include "ch32v003fun.h"
#define APB_CLOCK SYSTEM_CORE_CLOCK 
#include "led.h"
#include "powermode.h"
#include "buzzer.h"
#include "button.h"
#include "tasks/input.h"
#include "tasks/pomodoro.h"

#define VERSION 0.8.0

static void hal_init(void);

int main(void)
{
	hal_init();
	Input input = input_create();
	Pomodoro pomodoro = pomodoro_create(1);
	while(1){
		input_do(&input, &pomodoro);
		pomodoro_doIt(&pomodoro);
		powermode_sleep();
	}
	return 0;
}

static void hal_init(void)
{
	led_init();
	button_init();
	buzzer_init();
	powermode_init();
	//tick_init();
}
