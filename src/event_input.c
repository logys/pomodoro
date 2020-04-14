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
	timer_power_off = timer_create();
}
void destroyEventInput(void)
{

}

static void eventOff(void);

int8_t readEvent(void)
{
	handler.button = readPush();
	if(handler.button == OFF){
		eventOff();
	}else if(handler.button == ON){ //Button pressed
		if(handler.last_button == OFF){
			timer_start(timer_power_off);
			handler.state = PLAY_PAUSE;
		}else{
			handler.time_power_off = timer_getMilliseconds(timer_power_off);
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
