#include "action.h"
bool first_toggle;
void initAction(void)
{
	initPowerOff();
	initRun();
	initPause();
	action = pomodoro_off;
	first_toggle = true;
}
void destroyAction(void)
{
	destroyPowerOff();
	destroyRun();
	destroyPause();
}
void setActionTogglePlayPause(void)
{
	bool last_action_was_pause = action == pomodoro_pause;
	if(first_toggle || last_action_was_pause){
		setActionPlay();
		first_toggle = false;
	}
	else{
		action = pomodoro_pause;
	}
}
void setActionPowerOff(void)
{
	action = pomodoro_off;
}
void setActionPlay(void)
{
	action = pomodoro_run;
}
