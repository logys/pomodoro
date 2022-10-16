#define F_CPU 16000000UL
#include <util/delay.h>
#include "tasks/input.h"
#include "tasks/pomodoro.h"
#include "hal/hal.h"

#define VERSION 0.7.0

int main()
{
	button_init();
	buzzer_init();
	led_init();
	pomodoro_init(25);
	input_init();
	while(1){
		input_doIt();
		pomodoro_doIt();
		_delay_ms(10);
	}
	return 0;
}
