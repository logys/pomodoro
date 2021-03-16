#include "pause_spy.h"

bool pause_do_called = false;
static short * progress;

bool pause_do_spy(void)
{
	return pause_do_called;
}

void pause_do(void)
{
	pause_do_called = true;
	*progress = 80;
}

void pause_init(short *const progress_injected, bool * const finished_injected)
{
	progress = progress_injected;
}
