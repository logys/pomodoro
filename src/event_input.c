#include "event_input.h"

typedef struct Event{
	int8_t state;
	int8_t button;
	int8_t last_button;
	double time_power_off;
}event;
static event handler = { };
static TIMER timer_power_off;
void initEventInput(void)
{
	openPush();
	initTimer();
	timer_power_off = newTimer();
}

static void eventOff(void);
static bool buttonPressed(void);

int8_t readEvent(void)
{
	handler.button = readPush();
	if(handler.button == OFF){
		eventOff();
	}else if(handler.button == ON){ //Button pressed
		if(handler.last_button == OFF){
			setTimer(timer_power_off, 2, SECONDS);
			handler.state = PLAY_PAUSE;
		}else{
			handler.time_power_off = getTimer(timer_power_off, SECONDS);
			if(handler.time_power_off >= 2){
				handler.state = POWEROFF;
			}else{
				handler.state = NONE;
			}
		}
	}
	handler.last_button = handler.button;
	return handler.state;
}

static void eventOff(void)
{
	handler.state = NONE;
}
