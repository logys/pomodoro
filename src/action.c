#include "action.h"
#include "play.h"
#include "pause.h"
#include "poweroff.h"

static void (*action)(void) = poweroff_do;

void action_set_play(void)
{
	action = play_do;
}

void action_set_pause(void)
{
	action = pause_do;
}

void action_set_poweroff(void)
{
	action = poweroff_do;
}

void action_do(void)
{
	action();
}

