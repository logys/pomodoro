#include "pause.h"
#include "timer.h"

static short progress;
static CLOCK timer;

void pause_init(void)
{
	timer = timer_create();
}

short pause_do(void)
{
	if(timer_getTime(&timer, MINUTES) >= 5)
		progress = 100;
	else
		progress = 80;
	return progress;
}
