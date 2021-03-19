#include "timer.h"
#include "millis.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

CLOCK timer_create(void)
{
	millis_init();
	return (CLOCK){.time_at_start=millis()};
}

uint32_t timer_getTime(CLOCK * timer, TIME_TYPE type)
{
	uint32_t time = millis() - timer->time_at_start;
	if(type == MILLISECONDS)
		return time;
	else if(type == SECONDS)
		return time/1000.0;
	else
		return time/60000.0;
}

void timer_restart(CLOCK * timer)
{
	timer->time_at_start = millis();
}
