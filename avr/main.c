#include "tasks/input.h"
#include "tasks/pomodoro.h"
#include "hal/hal.h"

#define VERSION 0.8.0

int main()
{
	const int session_time = 20;
	button_init();
	buzzer_init();
	led_init();
	input_init();
	pomodoro_init(session_time);
	tick_init();
	while(1){
		input_doIt();
		pomodoro_doIt();
		idle();
	}
	return 0;
}
