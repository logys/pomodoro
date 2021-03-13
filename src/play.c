#include "progress.h"
#include "timer.h"
#include <stdlib.h>

#define DELTA_TIME 200

static CLOCK timer;
static uint32_t session_time = -1;
static uint32_t last_time = 0;
static short * progress;

void play_init(const short session_time_injected, short * const progress_injected)
{
	timer = timer_create();
	last_time = 0;
	progress = progress_injected;
	session_time = session_time_injected*60*1000;
}

void play_do(void)
{
	int current_time = timer_getTime(&timer, MILLISECONDS);
	if((current_time - last_time) < DELTA_TIME){
		*progress = 100*(1 - ((double)(session_time - current_time)/session_time));
	}
	last_time = current_time;
}
