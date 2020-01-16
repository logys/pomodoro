#include "pomodoro_pause.h"
struct Pause_struct{
	double actual_time;
	double last_time;
	bool timer_seted;
	short state;
};

static struct Pause_struct pauser = {};
TIMER timer_pause;

void initPause(void)
{
	initTimer();
	initHandleLed();
	timer_pause = newTimer();
	pauser.timer_seted = false;
}

void destroyPause(void)
{
}

static void requestTime(void)
{
	pauser.actual_time = getTimer(timer_pause, MILLISECONDS);
}
#define MILLISECONDS_NEED_RESET 50
static bool wasElapsedManyTime(void)
{
	return (pauser.actual_time -pauser.last_time) >= MILLISECONDS_NEED_RESET;
}
static void reinitTimeFirstCall(void)
{
	if(!pauser.timer_seted || wasElapsedManyTime() || pauser.actual_time < pauser.last_time){
		pauser.timer_seted = true;
		reinitTimer(timer_pause);
	}
	pauser.last_time = pauser.actual_time;
}
static int const MAX_PAUSE_TIME = 60*1000*5;
static void isTimePauseReached(void)
{
	if(pauser.actual_time >= MAX_PAUSE_TIME)
		pauser.state = REACHED;
	else
		pauser.state = RUNNING;
}

#define TOGGLE_TIME 15
RUN_STATE run(void)
{
	requestTime();
	reinitTimeFirstCall();
	updateLed(TOGGLE_TIME);
	isTimePauseReached();
	return pauser.state;
}
