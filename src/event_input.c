#include "event_input.h"
#include "push_driver.h"
#include "timer.h"
#include <stdlib.h>
#include <stdbool.h>

typedef struct Event{
	int8_t state;
	bool button;
	int8_t last_button;
	double time_power_off;
	uint32_t time_pushed;
}event;
static event handler = { };
static TIMER event_timer;

typedef enum {STATE_NONE, STATE_PUSHED, STATE_POWEROFF}STATE;
static STATE current_state;

void eventInput_create(void)
{
	timer_init();
	push_init();
	event_timer = timer_createNew();
	current_state = STATE_NONE;
	handler.state = NONE;
}

void eventInput_destroy(void)
{

	free(event_timer);
	event_timer = NULL;
	timer_destroy();
	push_close();
	handler.button = false;
}

static void state_none(void)
{
	if(handler.button){
		current_state = STATE_PUSHED;
		timer_start(event_timer);
		handler.state = PLAY_PAUSE;
	}
}
static void state_push(void)
{
	if(handler.time_pushed < 50){
		handler.state = NONE;
		return ;
	}
	if(!handler.button){
		current_state = STATE_NONE;
		handler.state = NONE;
	}else{
		current_state = STATE_POWEROFF;
		handler.state = NONE;
	}
}
static void state_poweroff(void)
{
	if(timer_getMilliseconds(event_timer) < 2000 && !handler.button ){
		current_state = STATE_NONE;
		handler.state = NONE;
	}else if(timer_getMilliseconds(event_timer) >= 2000 && handler.button){
		current_state = STATE_NONE;
		handler.state = POWEROFF;
	}
}
void (*state_array[])(void)={state_none, state_push, state_poweroff};

EVENT eventInput_read(void)
{
	handler.button = push_read();
	handler.time_pushed = timer_getMilliseconds(event_timer);
	state_array[current_state]();
	return handler.state;
}
