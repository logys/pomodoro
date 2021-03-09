#include "controller.h"
#include "play.h"
#include "selector.h"
#include "timer.h"
#include "pause.h"

static bool * finished;
static short * progress;
static CLOCK timer_selector;

void controller_init(const short session_time, short * const progress_injected,
		bool const * const button, bool * finished_injected)
{
	finished = finished_injected;
	progress = progress_injected;
	selector_init(button, &timer_selector);
}

void controller_do(void)
{
	ACTION action = selector_select();
	if(action == PLAY)
		*progress = play_do();
	else if(action == PAUSE)
		*progress = pause_do();

	if(*progress >= 100 || action == POWEROFF)
		*finished = true;
	else
		*finished = false;
}
