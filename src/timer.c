#include "timer.h"
#include "millis.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
struct Timer{
	uint32_t time_at_start;
	bool time_started;
	bool time_paused;
	uint32_t time_on_pause;
};
unsigned int countRef = 0;

void timer_init(void)
{
	countRef++;
}

CLOCK timer_create(void)
{
	return (CLOCK){};
}

TIMER timer_createNew(void)
{
	TIMER tmp = calloc(1, sizeof(struct Timer));
	tmp->time_at_start = 0;
	tmp->time_started = false;
	tmp->time_paused = false;
	tmp->time_on_pause = 0;
	return tmp;
}

uint32_t timer_getMilliseconds(TIMER timer)
{
	if(!timer->time_started)
		return 0;
	else{
		if(timer->time_paused)
			return timer->time_on_pause - timer->time_at_start;
		return millis()-timer->time_at_start;
	}
}
void timer_reinit(TIMER timer)
{
	timer->time_at_start = millis();
}


void timer_pause(TIMER timer)
{
	if(!timer->time_paused){
		timer->time_paused = true;
		timer->time_on_pause = millis();
	}
}
static void computeTimeSincePause(TIMER timer)
{
	uint32_t time_elapsed_before_pause = timer->time_on_pause - timer->time_at_start;
	timer->time_at_start = millis() - time_elapsed_before_pause;
}
void timer_resume(TIMER timer)
{
	if(timer->time_paused){
		computeTimeSincePause(timer);
		timer->time_paused = false;
	}
}
void timer_start(TIMER timer)
{
	if(timer->time_started)
		return ;
	timer->time_at_start = millis();
	timer->time_started = true;
}

void timer_destroy(void)
{
	if(countRef == 0){
	}
}

void delay(uint32_t time_ms)
{
	uint32_t time_at_init = millis();
	while((millis() - time_at_init) < time_ms){
		__asm__("nop");
	}
}
