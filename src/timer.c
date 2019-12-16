#include "timer.h"

struct Timer{
	uint32_t init_time;
	uint32_t end_time;
	uint32_t accumulated_time;
	uint32_t last_millis;
	bool paused;
};

void initTimer(void)
{
	initTimer1Millis();
}

TIMER newTimer(void)
{
	TIMER tmp = calloc(1, sizeof(struct Timer));
	tmp->init_time = -1;
	return tmp;
}

#define MILLISECONDS_IN_MILLISECOND 1
#define MILLISECONDS_IN_SECOND 1000
#define MILLISECONDS_IN_MINUTE 60000UL
typedef enum {SET = 1, GET}ACTION;

static void setSesionTime(TIMER timer, uint32_t time);
static double setOrGetTime(ACTION, TIMER, double time, UNIT_TIME);
static double getSesionTime(TIMER timer, int time_scale);

void setAlarm(TIMER timer, double time, UNIT_TIME unit)
{
	reinitTimer(timer);
	setOrGetTime(SET, timer, time, unit);
}
static double setOrGetTime(ACTION action, TIMER timer, double time, UNIT_TIME unit)
{
	int time_scale;
 	unit == MILLISECONDS ? time_scale = MILLISECONDS_IN_MILLISECOND:
	unit == SECONDS ? time_scale = MILLISECONDS_IN_SECOND:
	unit == MINUTES ? time_scale = MILLISECONDS_IN_MINUTE:
			(time_scale = UNKNOWN); 
	if(time_scale == UNKNOWN)
		return UNKNOWN;
	if(action == SET){
		setSesionTime(timer, time*time_scale);
	}else if(action == GET){
		return getSesionTime(timer, time_scale);
	}
	return 0;
}
static double getSesionTime(TIMER timer, int time_scale)
{
	if(timer->init_time == -1)
		return -1;
	return timer->accumulated_time/(double)time_scale;
}
static void setSesionTime(TIMER timer, uint32_t time)
{
	timer->end_time = time + timer->init_time;
}


static void updateTime(TIMER timer);
double getTimer(TIMER timer, UNIT_TIME unit)
{
	updateTime(timer);
	return setOrGetTime(GET, timer, 0, unit);
}
static void updateTime(TIMER timer)
{
	if(!timer->paused){
		uint32_t actual_time = millis();
		timer->accumulated_time += actual_time - timer->last_millis;
		timer->last_millis = actual_time;
	}
}

void reinitTimer(TIMER timer)
{
	timer->init_time = millis();
	timer->accumulated_time = 0;
	timer->last_millis = timer->init_time;
}

void pauseTimer(TIMER timer)
{
	updateTime(timer);
	timer->paused = true;
}

void resumeTimer(TIMER timer)
{
	if(timer->paused){
		timer->last_millis = millis();
		timer->paused = false;
	}
}
void delay(uint32_t time_ms)
{
	TIMER delay_ms = newTimer();
	enableTimer(delay_ms);
	while(getTimer(delay_ms, MILLISECONDS) < time_ms){
		__asm__("nop");
	}
	free(delay_ms);
}

void enableTimer(TIMER timer)
{
	reinitTimer(timer);
}

void disableTimer(TIMER timer)
{
}

void destroyTimer(TIMER timer)
{
	free(timer);
}
