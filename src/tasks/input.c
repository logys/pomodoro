#include "input.h"
#include "pomodoro.h"
#include "button.h"

static const int TICK_TIME = 10;
static const int REBOUND_TIME = 50;

Input input_create(void)
{
	return (Input){.time_ms = 0};
}

void input_do(Input * input, Pomodoro * pomodoro)
{
	bool pressed = button_pushed();
	bool positive_edge = pressed && !input->last_pushed 
		&& (input->time_ms == 0);
	input->time_ms = positive_edge ? REBOUND_TIME : 
		(input->time_ms>0 ? input->time_ms-TICK_TIME: 0);
	pomodoro->button_pressed = positive_edge ? true : false;
	input->last_pushed = pressed;
}
