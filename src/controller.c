#include "controller.h"
#include "selector.h"
#include "play.h"
#include "pause.h"
#include "pomodoro.h"
#include "poweroff.h"

static bool * finished;
static short * progress;
void controller_init(short * const progress_injected, bool * finished_injected)
{
	finished = finished_injected;
	progress = progress_injected;

	pause_init();
}

void controller_do(void)
{
	if(*finished){
		pomodoro_reinit();
	}
	ACTION action = selector_select();
	if(action == PLAY)
		*progress = play_do();
	else if(action == PAUSE)
	       	*progress = pause_do();

	if(*progress >= 100 || action == POWEROFF){
		*finished = true;
	}
	else
		*finished = false;
}
