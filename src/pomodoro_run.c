#include "pomodoro_run.h"
typedef struct{
	short run_state;
	double actual_session_time;
	double actual_time;
	double work_cicle;
	double last_time;
	double time_paused;
}Run;
static Run runner;
TIMER timer_run;

void initRun(void)
{
	initTimer();
	openBuzzer();
	initHandleLed();
	timer_run = newTimer();
	enableTimer(timer_run);
	runner.run_state = ACTION_RUNNING;
	runner.actual_session_time = NAN;
	runner.actual_time = NAN;
	runner.last_time = NAN;
	runner.time_paused = 0;
}

void destroyRun(void)
{
	destroyTimer(timer_run);
	closeBuzzer();
	destroyHandleLed();
}
static void updateTime(void)
{
	runner.actual_time = getTimer(timer_run, MILLISECONDS);
	runner.actual_session_time = getSessionTime()*1000*60.0;
}
static void handleLed(void)
{
	runner.work_cicle =(runner.actual_time - runner.time_paused)*100/
		(runner.actual_session_time);
	updateLed(runner.work_cicle);
}
static void reinitForNextSession(void)
{
	runner.time_paused = 0;
	runner.last_time = NAN;
	reinitTimer(timer_run);
}
static void wasLastSession(void)
{
	if(isnan(runner.actual_session_time)){
		runner.run_state = ACTION_REACHED;
		buzzer(1, 1000);
	}
}
static void isSeassonReached(void)
{
	if(runner.work_cicle >= 100){
		if(getSessionNumber() % 2 != 0){
			buzzer(2, 400);
		}else{
			buzzer(4, 100);
		}
		advanceSession();
		reinitForNextSession();
	}else{
		runner.last_time = runner.actual_time;
		runner.run_state = ACTION_RUNNING;
	}
	wasLastSession();
}
#define TIME_MINIM_FOR_PAUSE 50
static void wasPaused(void)
{
	static double delta = 0;
	delta = runner.actual_time - runner.last_time;
	if( delta >= TIME_MINIM_FOR_PAUSE)
		runner.time_paused += delta;
}
RUN_STATE pomodoro_run(void)
{
	updateTime();
	wasPaused();
	handleLed();
	isSeassonReached();
	return runner.run_state;
}
