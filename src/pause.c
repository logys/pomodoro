#include "pause.h"
#include "timer.h"

#define DELTA 200

static short progress;
static CLOCK timer;
unsigned int last_time;

void pause_init(void)
{
	timer = timer_create();
	last_time = false;
}

short pause_do(void)
{
	if(progress >= 100)
		timer_restart(&timer);
	int current_time = timer_getTime(&timer, MINUTES);
	if(current_time - last_time > DELTA)
		timer_restart(&timer);
	if(current_time >= 5)
		progress = 100;
	else
		progress = 80;
	last_time = current_time;
	return progress;
}

void pause_reinit(void)
{
	progress = 0;
	timer_restart(&timer);
}
