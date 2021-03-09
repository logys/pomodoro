#include "play_spy.h"

bool play_do_called = false;
static short progress;

bool play_do_spy(void)
{
	return play_do_called;
}

double play_do(void)
{
	play_do_called = true;
	return progress;
}

void play_set_progress_spy(short progress_injected)
{
	progress = progress_injected;
}
