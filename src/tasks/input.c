#include "input.h"
#include "pomodoro.h"
#include "button.h"

typedef enum {IDLE, REBOUND}State;

static const int TICK_TIME = 10;
static const int REBOUND_TIME = 50;
static State state;
static int time;

void input_init(void)
{
	state = IDLE;
	time = 0;
}

void input_doIt(void)
{
	bool input_pushed = button_pushed();
	switch(state){
		case IDLE:
			if(input_pushed == true){
				pomodoro_pushed();
				state = REBOUND;
			}
			break;
		case REBOUND:
			time += TICK_TIME;
			if(time >= REBOUND_TIME && input_pushed == false){
				state = IDLE;
				time = 0;
			}
			break;
		default:
			return;
	}
}

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
		(input->time_ms>0 ? input->time_ms-10: 0);
	pomodoro->button_pressed = positive_edge ? true : false;
	input->last_pushed = pressed;
}
