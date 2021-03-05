#include "progress.h"
#include "timer.h"
#include <stdlib.h>

#define DELTA_TIME 200

static CLOCK *timer = NULL;
static int session_time = -1;
static uint32_t last_time = 0;
static double progress = 0;

void play_init(CLOCK *timer_injected)
{
	timer = timer_injected;
	last_time = 0;
	progress = 0;
}

void play_setSessionTime(const int minutes)
{
	session_time = minutes*60*1000;
}

double play_do(void)
{
	int current_time = timer_getTime(timer, MILLISECONDS);
	if((current_time - last_time) < DELTA_TIME){
		progress = 100*(1 - ((double)(session_time - current_time)/session_time));
	}
	last_time = current_time;
	return progress;
}
