#include "timer.h"
#define MAX_ALARMS 3
typedef struct Timer{
	int8_t id;
	int32_t tiempo;
	int8_t unidad;
	int8_t reached;
	uint32_t time_milliseconds;
	uint32_t init_time_milliseconds;
}timer;
static timer clock_general[MAX_ALARMS];

static void updateClock(int8_t);

void initTimer(void)
{
	initTimer1Millis();
	for(int i = 0; i< MAX_ALARMS; i++){
			clock_general[i].id = i;
			clock_general[i].tiempo = UNKNOWN;
			clock_general[i].unidad = UNKNOWN;
			clock_general[i].reached = UNKNOWN;
			clock_general[i].time_milliseconds = 0;
	}
}

ALARM_STATE getAlarm(ALARM_ID id)
{
	if(clock_general[id].tiempo == UNKNOWN)
		return UNKNOWN;
	updateClock(id);
	if(clock_general[id].reached)
		return READY;
	return UNREACHED;
}

static void updateClock(int8_t id)
{
	if(	(millis() - clock_general[id].init_time_milliseconds) >=
		clock_general[id].time_milliseconds)
		clock_general[id].reached = READY;
}

void setAlarm(ALARM_ID id, uint16_t time, UNIT_TIME unit)
{
	clock_general[id].tiempo = time;
	clock_general[id].unidad = unit;
	clock_general[id].reached = UNREACHED;
	clock_general[id].init_time_milliseconds = millis();
	if(unit == MINUTES)
		clock_general[id].time_milliseconds = time*60*1000;
	else if(unit == SECONDS)
		clock_general[id].time_milliseconds = time*1000;
	else if(unit == MILLISECONDS)
		clock_general[id].time_milliseconds = time;
}

void delay(uint32_t time_ms)
{
	setAlarm(TIMER_DELAY,time_ms, MILLISECONDS);
	while(getAlarm(TIMER_DELAY) <= UNREACHED)
		__asm__("nop");
}
