#include"pomodoro.h"

typedef struct{
	short state;
	bool first_call;
}Pomodoro;

static Pomodoro pomodoro;

void initPomodoro(void)
{
	initEventInput();
	initSessions();
	initAction();
	pomodoro.state = POMODORO_DISABLED;
	pomodoro.first_call = true;
}
void destroyPomodoro(void)
{
	destroyEventInput();
}
POMODORO_STATE updatePomodoro(void)
{
	static short event;
	static RUN_STATE last_action;
	event = readEvent();
	if(event == POWEROFF || pomodoro.first_call || last_action == ACTION_REACHED){
		last_action = ACTION_RUNNING;
		setActionPowerOff(); 
		pomodoro.first_call = false;
		pomodoro.state = POMODORO_REACHED;
	}else if(last_action == ACTION_POWEROFF){
		setActionPlay();
	}else if(event == NONE){
		pomodoro.state = POMODORO_RUNNING;
	}else if(event == PLAY_PAUSE){
		setActionTogglePlayPause();
		pomodoro.state = POMODORO_RUNNING;
	}
	last_action = action();
	return pomodoro.state;
}
