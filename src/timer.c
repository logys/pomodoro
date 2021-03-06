#include "timer.h"
#include "millis.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>


void timer_init(void)
{
}

CLOCK timer_create(void)
{
	return (CLOCK){0};
}

uint32_t timer_getTime(CLOCK * timer, TIME_TYPE type)
{
	return millis() - timer->time_at_start;
}

void timer_restart(CLOCK * timer)
{
	timer->time_at_start = millis();
}
