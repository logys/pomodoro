#include "pomodoro_run.h"
typedef struct{
	short run_state;
	double actual_session_time;
	double actual_time;
}Run;
static Run runner;
TIMER timer_run;

void initRun(void)
{
	initTimer();
	openBuzzer();
	initHandleLed();
	timer_run = newTimer();
	runner.run_state = RUNNING;
	runner.actual_session_time = NAN;
	runner.actual_time = NAN;
}

void destroyRun(void)
{
	destroyTimer(timer_run);
	closeBuzzer();
	destroyHandleLed();
}

static void selectBuzzer(void)
{
	short actual_session_number = getSessionNumber();
	if(isnan(runner.actual_session_time)){
		buzzer(1, 1000);
	}else if(actual_session_number % 2 != 0)
		buzzer(2, 400); //odd session
	else 
		buzzer(4, 100); //even session
}

static bool isSessionReached(void)
{
	if(isnan(runner.actual_session_time))
		return true;
	return runner.actual_time >= runner.actual_session_time;
}
static void pause(void)
{
	runner.run_state = PAUSE;
	pauseTimer(timer_run);
}
static void lastSessionWasPaused(void)
{
	if(runner.run_state == PAUSE){
		resumeTimer(timer_run);
	}
}
static void updateTime(void)
{
	runner.actual_time = getTimer(timer_run, MINUTES);
	runner.actual_session_time = getSessionTime();
}
RUN_STATE run(bool play)
{
	if(!play){
		pause();
	}else{
		lastSessionWasPaused();
		updateTime();
		updateLed((runner.actual_time)*100/
				runner.actual_session_time);
		if(isSessionReached()){
			if(isnan(runner.actual_session_time)){
				runner.run_state = POWEROFF;
			}else{
				runner.run_state = REACHED;
			}
			selectBuzzer();
			advanceSession();
		}else
			runner.run_state = RUNNING;
	}
	return runner.run_state;
}
