#include "timer_spy.h"

double time = 0;

void timer_enable(CLOCK * timer)
{
}

double timer_getTime(CLOCK * timer, TIME_TYPE type)
{
	return time;
}

void timer_reset(CLOCK * timer)
{
	time = 0;
}

void timer_setTime_spy(double time_input, TIME_TYPE type)
{
	time = time_input;
}

void timer_addTime_spy(double time_input, TIME_TYPE type)
{
	time += time_input;
}
