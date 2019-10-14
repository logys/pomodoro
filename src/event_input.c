#include "event_input.h"
#include <stdbool.h>

typedef struct Event{
	int8_t event;
	int8_t timer_power_off;
	int8_t timer_delay;
	int8_t button;
	int8_t last_state;
}event;
static event handler;
void initEventInput(void)
{
	openPush();
	initTimer();
	handler.event = UNKNOWN;
	handler.timer_power_off = UNKNOWN;
	handler.timer_delay = UNKNOWN;
	handler.button = UNKNOWN;
	handler.last_state = UNKNOWN;

}

static void eventOff(void);
static void setAlarms(void);
static void getAlarms(void);
static void checkAlarms(void);
static void handleLastState(void);

int8_t readEvent(void)
{
	handler.button = readPush();
	if(handler.button == OFF){
		eventOff();
	}else{ //Button pressed
		if(handler.last_state == ON){
			setAlarms();
		}
		getAlarms();
		checkAlarms();
		handleLastState();
	}
	return handler.event;
}

static void eventOff(void)
{
	handler.event = NONE;
	handler.last_state = OFF;
}
static void setAlarms(void)
{
			setAlarm(TIMER_BUTTONS_SAMPLES, 100, MILLISECONDS);
			setAlarm(TIMER_BUTTONS, 2, SECONDS);
}
static void getAlarms(void)
{
		handler.timer_delay = getAlarm(TIMER_BUTTONS_SAMPLES);
		handler.timer_power_off = getAlarm(TIMER_BUTTONS);
}
static void checkAlarms(void)
{
		if(handler.timer_delay == READY){
			handler.last_state = OFF;
		}
		if(handler.timer_power_off == READY){
			handler.event = POWEROFF;
		}
}

static void handleLastState(void)
{
	/* handle.event is seted to POWEROFF for checkAlarms() if the button is
	 * pressed for 2 seconds*/
		if(handler.last_state != ON){
			if(handler.event != POWEROFF)
				handler.event = PLAY_PAUSE;
		}else if(handler.last_state == ON){
			handler.event = NONE;
		}
		handler.last_state = ON;
}
