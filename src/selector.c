#include "selector.h"
#include <stdlib.h>
#include "timer.h"

#define SECONDS_TO_POWEROFF 5

typedef enum{POWEROFF_STATE, TOGGLER_STATE, TRAP_STATE}STATE;

static CLOCK timer;
static bool const * button;
static ACTION current_action;
static ACTION last_action;
static STATE state;

static void poweroff(void);
static void toggler(void);
static void trap(void);

void (*state_table[])(void) = {poweroff, toggler, trap};

void selector_init(bool const * const butn)
{
	state = POWEROFF_STATE;
	button = butn;
	last_action = -1;
	timer = timer_create();
}

ACTION selector_select(void)
{
	state_table[state]();
	last_action = current_action;
	return current_action;
}

static void poweroff(void)
{
	current_action = POWEROFF;
	state = TOGGLER_STATE;
}

static void toggler(void)
{
	if(*button){
		if(current_action == PLAY)
			current_action = PAUSE;
		else
			current_action = PLAY;
		state = TRAP_STATE;
	}else
		timer_restart(&timer);
}

static void trap(void)
{
	if(timer_getTime(&timer, SECONDS) >= 5){
		current_action = POWEROFF;
		state = TOGGLER_STATE;
	}else if(*button){
	}else{
		state = TOGGLER_STATE;
	}

}
