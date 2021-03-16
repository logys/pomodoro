#include "pause.h"
#include "timer.h"

static short * progress;
static bool * finished;
static CLOCK timer;

void pause_init(short * const progress_injected, bool * const finished_injected)
{
	progress = progress_injected;
	finished = finished_injected;
	timer = timer_create();
}

void pause_do(void)
{
	*progress = 80;
	if(timer_getTime(&timer, MINUTES) >= 5)
		*finished = true;
	else
		*finished = false;
}
