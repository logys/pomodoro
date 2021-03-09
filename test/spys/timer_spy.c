#include "timer_spy.h"

double time = 0;

void timer_enable(CLOCK * timer)
{
}

double timer_getTime(CLOCK * timer, TIME_TYPE type)
{
	if(type == SECONDS)
		return time /1000.0;
	return time;
}

void timer_reset(CLOCK * timer)
{
	time = 0;
}

void timer_setTime_spy(double time_input, TIME_TYPE type)
{
	if(type == SECONDS)
		time_input *= 1000;
	time = time_input;
}

void timer_addTime_spy(double time_input, TIME_TYPE type)
{
	time += time_input;
}

CLOCK timer_create(void)
{
	return (CLOCK){};
}
