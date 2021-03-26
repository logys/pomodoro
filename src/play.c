#include "millis.h"
#include <stdlib.h>
#include "play.h"

#define DELTA_TIME 250

static double session_time;
static double last_time;
static double progress;
static double acumulated;

void play_init(const short session_time_injected)
{
	last_time = 0;
	session_time = session_time_injected*60*1000UL;
	acumulated = 0;
	progress = 0;
}

short play_do(void)
{
	if(progress >= 100)
		play_reinit();
	int current_time = millis();
	int delta = current_time - last_time;
	if(delta < DELTA_TIME){
		acumulated += delta;
		progress = acumulated / session_time*100;
	}
	last_time = current_time;
	return progress;
}

void play_reinit(void)
{
	progress = 0;
	last_time = 0;
	acumulated = 0;
}
