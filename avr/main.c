#include "tasks/input.h"
#include "tasks/pomodoro.h"
#include <avr/io.h>
#include "buzzer.h"
#include "powermode.h"
#include "led.h"
#include "button.h"
#include "buzzer.h"
#include "tick.h"

#define VERSION 0.8.0

static void hal_init(void);

int main()
{
	hal_init();
	Input input = input_create();
	Pomodoro pomodoro = pomodoro_create(20);
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
	tick_init();
}
