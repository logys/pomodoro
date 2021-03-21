#include "progress.h"
#include "timer.h"
#include <stdlib.h>

#define DELTA_TIME 10

static CLOCK timer;
static uint32_t session_time;
static uint32_t last_time;
static double progress;

void play_init(const short session_time_injected)
{
	timer = timer_create();
	last_time = 0;
	session_time = session_time_injected*60*1000;
}

short play_do(void)
{
	if(progress >= 100)
		progress = 0;
	int current_time = timer_getTime(&timer, MILLISECONDS);
	if((current_time - last_time) < DELTA_TIME){
		progress += 100*(1 - ((double)(session_time - current_time)/session_time));
	}else
		timer_restart(&timer);
	last_time = current_time;
	return progress;
}
