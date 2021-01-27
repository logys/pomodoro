#include "selector.h"
#include <stdlib.h>
#include <stdbool.h>

static CLOCK * timer = NULL;
static ACTION current_action = 0;
static short last_button = 0;

static bool buttonPressedManyTime(short button);
static bool buttonPressed(short button);
static void toggleAction(void);
static bool wasEdge(short button);

void selector_init(CLOCK * timer_injected)
{
	timer = timer_injected;
	timer_enable(timer);
	current_action = PLAY;
	last_button = 0;
}

int selector_selectActionFromInput(int button)
{
	if(buttonPressedManyTime(button))
		current_action = POWEROFF;
	else if(buttonPressed(button) && wasEdge(button)){
		timer_reset(timer);
		toggleAction();
	}
	last_button = button;
	return current_action;
}

static bool buttonPressedManyTime(short button)
{
	double current_time = timer_getTime(timer, SECONDS);
	return button == 1 && current_time >= 5;
}

static bool buttonPressed(short button)
{
	return button == 1;
}

static bool wasEdge(short button)
{
	bool edge = last_button == 0;
	last_button = button;
	return edge;
}
static void toggleAction(void)
{
	if(current_action == PLAY){
		current_action = PAUSE;
	}else
		current_action = PLAY;
}
