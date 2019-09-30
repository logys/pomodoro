#include "timer.h"

typedef struct Timer{
	int32_t tiempo;
	int8_t unidad;
	int8_t reached;
	uint32_t time_milliseconds;
}timer;
static timer clock;

static void updateClock(void);

void initTimer(void)
{
	initTimer1Millis();
	clock.tiempo = UNKNOWN;
	clock.unidad = UNKNOWN;
	clock.reached = UNKNOWN;
	clock.time_milliseconds = 0;
}

ALARM_STATE getAlarm(void)
{
	updateClock();
	if(clock.tiempo == UNKNOWN)
		return UNKNOWN;
	if(clock.reached)
		return READY;
	return UNREACHED;
}

static void updateClock(void)
{
	if(clock.time_milliseconds <= millis())
		clock.reached = READY;
}

void setAlarm(uint16_t time, UNIT_TIME unit)
{
	clock.tiempo = time;
	clock.unidad = unit;
	clock.reached = UNREACHED;
	reiniciarMillis();
	if(unit == MINUTES)
		clock.time_milliseconds = time*60*1000;
	else if(unit == SECONDS)
		clock.time_milliseconds = time*1000;
	else if(unit == MILLISECONDS)
		clock.time_milliseconds = time;
}
