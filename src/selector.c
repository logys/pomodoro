#include "selector.h"
#include <stdlib.h>

#define SECONDS_TO_POWEROFF 5

static CLOCK * timer = NULL;
static bool * button = NULL;
static bool last_button = false;
static ACTION current_action = POWEROFF;
static ACTION last_action = POWEROFF;
static bool firstQuery = true;

void selector_init(bool *butn, CLOCK * timer_injected)
{
	button = butn;
	firstQuery = true;
	last_action = POWEROFF;
	timer = timer_injected;
	last_button = false;
}

ACTION selector_select(void)
{
	if(firstQuery || timer_getTime(timer, SECONDS) >= SECONDS_TO_POWEROFF){
		firstQuery = false;
		current_action = POWEROFF;
	}
	else if(last_action == POWEROFF || 
			(last_action == PAUSE && *button == true)){
		current_action = PLAY;
	}
	else if(last_action == PLAY && *button == true)
		current_action = PAUSE;

	if(!last_button)
		timer_reset(timer);
	last_button = *button;
	last_action = current_action;
	return current_action;
}
