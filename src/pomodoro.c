#include"pomodoro.h"
struct Pomodoro{
	POMODORO_STATE state;
	bool enabled;
}pomodoro;

TIMER timer_pomodoro;
void initPomodoro(void)
{
	initTimer();
	initEventInput();
	initHandleLed();
	openBuzzer();
	timer_pomodoro = newTimer();
	initSessions();
	
	pomodoro.state = -1;
	pomodoro.enabled = false;
}

static bool isSessionReached(double actual_time);
static void doBuzz();
static void handleReachedSession(void);
POMODORO_STATE updatePomodoro(void)
{
	if(pomodoro.enabled){
		double actual_time = getTimer(timer_pomodoro, MINUTES);
		if(isSessionReached(actual_time)){
			handleReachedSession();
		}else 
			pomodoro.state = INPROGRESS;
	}else
		pomodoro.state = DISABLED;
	return pomodoro.state;
}
static void handleReachedSession(void)
{
	doBuzz();
	advanceSession();
	pomodoro.state = REACHED;
}

#define NUM_BUZZER_FINISH 1
#define NUM_BUZZER_ODD 2
#define NUM_BUZZER_EVEN 4
#define MILLIS_BUZZER_FINISH 1000
#define MILLIS_BUZZER_ODD 400
#define MILLIS_BUZZER_EVEN 100

static bool isOddSession(void);
static void doBuzz(void)
{
	if(isnan(getSessionTime())){
		buzzer(NUM_BUZZER_FINISH, MILLIS_BUZZER_FINISH);
	}else if(isOddSession())
		buzzer(NUM_BUZZER_ODD, MILLIS_BUZZER_ODD);
	else
		buzzer(NUM_BUZZER_EVEN, MILLIS_BUZZER_EVEN);
}
static bool isOddSession(void)
{
	short session_number = getSessionNumber();
	return session_number%2 != 0;
}
static bool isSessionReached(double actual_time)
{
	if(actual_time == UNKNOWN)
		return false;
	double session_time = getSessionTime();
	return (session_time <= actual_time) || isnan(session_time) ;
}

void enablePomodoro(void)
{
	pomodoro.enabled = true;
	enableTimer(timer_pomodoro);
}

void disablePomodoro(void)
{
	pomodoro.enabled = false;
}
