#include "controller.h"
#include "selector.h"
#include "play.h"
#include "pause.h"

static bool * finished;
static short * progress;

void controller_init(const short session_time, short * const progress_injected,
		bool const * const button, bool * finished_injected)
{
	finished = finished_injected;
	progress = progress_injected;

	selector_init(button);
	play_init(session_time, progress);
	pause_init(progress);
}

void controller_do(void)
{
	ACTION action = selector_select();
	if(action == PLAY)
		play_do();
	else if(action == PAUSE)
	       	pause_do();

	if(*progress >= 100 || action == POWEROFF)
		*finished = true;
	else
		*finished = false;
}
