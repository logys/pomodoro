#include "tasks/input.h"
#include "tasks/pomodoro.h"
#include <avr/io.h>
#include "buzzer.h"
#include "powermode.h"
#include "led.h"
#include "button.h"
#include "buzzer.h"

#define VERSION 0.8.0

int main()
{
	led_init();
	button_init();
	buzzer_init();
	powermode_init();
	Input input = input_create();
	Pomodoro pomodoro;
	while(1){
		input_do(&input, &pomodoro);
		//pomodoro_doIt();
			led_toggle();
		powermode_sleep();
	}
	return 0;
}
