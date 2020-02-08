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
	event = readEvent();
	if(event == POWEROFF || pomodoro.first_call){
		setActionPowerOff(); 
		pomodoro.first_call = false;
		pomodoro.state = POMODORO_REACHED;
	}else if(event == NONE){
		pomodoro.state = POMODORO_RUNNING;
	}else if(event == PLAY_PAUSE){
		setActionTogglePlayPause();
		pomodoro.state = POMODORO_RUNNING;
	}
	action();
	return pomodoro.state;
}
