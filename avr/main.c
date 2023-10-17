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

int main()
{
	led_init();
	button_init();
	buzzer_init();
	powermode_init();
	Input input = input_create();
	Pomodoro pomodoro;
	tick_init();
	while(1){
		input_do(&input, &pomodoro);
		if(pomodoro.button_pressed)
			led_toggle();
		//pomodoro_doIt();
		powermode_sleep();
	}
	return 0;
}
