#include "controller.h"
#include "selector.h"
#include "play.h"
#include "pause.h"
#include "pomodoro.h"

static bool * finished;
static short * progress;
static ACTION last_action;
void controller_init(short * const progress_injected, bool * finished_injected)
{
	finished = finished_injected;
	progress = progress_injected;
	last_action = -1;

	pause_init();
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
	if(action == POWEROFF && last_action == POWEROFF)
		pomodoro_reinit();
	last_action = action;
}
