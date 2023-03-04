#include "tasks/input.h"
#include "tasks/pomodoro.h"
#include "hal/hal.h"
#include <avr/io.h>

#define VERSION 0.8.0

int main()
{
	ADCSRA &= ~(1<<ADEN);
	input_init();
	const int session_time = 20;
	pomodoro_init(session_time);
	tick_init();
	while(1){
		input_doIt();
		pomodoro_doIt();
		idle();
	}
	return 0;
}
