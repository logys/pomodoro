#include "async_button.h"
#include "action.h"

static enum ActionType action = POWEROFF;

static void toggle(void);
static void play(void);
static void poweroff(void);

void async_button_determine_action(short const elapsed_time)
{
	if(elapsed_time >= 2)
		poweroff();
	else{
		if(action == PLAY || action == TOGGLE)
			toggle();
		else
			play();
	}
}

static void poweroff(void)
{
	action = POWEROFF;
	action_set_poweroff();
}

static void toggle(void)
{
	if(action == PLAY)
		action_set_pause();
	else 
		action_set_play();
	action = TOGGLE;
}

static void play(void)
{
	action_set_play();
	action = PLAY;
}

