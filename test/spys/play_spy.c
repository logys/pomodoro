#include "play_spy.h"

bool play_do_called = false;
static short *progress;

bool play_do_spy(void)
{
	return play_do_called;
}

void play_do(void)
{
	play_do_called = true;
}

void play_set_progress_spy(short progress_injected)
{
	*progress = progress_injected;
}

void play_init(const short session_time, short * const progress_injected)
{
	progress = progress_injected;
}
