#include "input.h"
#include "pomodoro.h"
#include "button.h"

typedef enum {IDLE, REBOUND}State;

static const int TICK_TIME = 10;
static const int REBOUND_TIME = 200;
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
