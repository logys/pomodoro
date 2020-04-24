#include "handleLed.h"
static struct HandleLed{
	bool timer_seted;
	short counter_toggles;
}handleLed;
static TIMER led_timer;
void initHandleLed(void)
{
	openLed();
	led_timer = timer_createNew();
	handleLed.timer_seted = false;
	handleLed.counter_toggles = 0;
}

#define SLOPE -492
#define ABSICE 500
static double calculateHalfPeriod(double work_cicle)
{
	if(work_cicle <0)
		work_cicle = 0;
	else if(work_cicle > 100)
		work_cicle = 100;
	return SLOPE*work_cicle/100.0 + ABSICE;
}
static bool isTimeReached(double half_period_time, double actual_time)
{
	return half_period_time <= actual_time;
}
static void toggleAndReinit(void)
{
	timer_reinit(led_timer);
	toggleLed();
}
static bool isTimerNoSeted(void)
{
	return !handleLed.timer_seted;
}
static void setTimer(void)
{
	timer_start(led_timer);
	handleLed.timer_seted = true;
}
static LED_STATE state;
LED_STATE updateLed(double work_cicle)
{
	static double half_period_time = 0;
	if(isTimerNoSeted()){
		setTimer();
		half_period_time = calculateHalfPeriod(work_cicle);
		state = TOGGLING;
	}
	double actual_time = timer_getMilliseconds(led_timer);
	if(isTimeReached(half_period_time, actual_time)){
		toggleAndReinit();
		handleLed.counter_toggles ++;
		if(handleLed.counter_toggles > 1){
			handleLed.counter_toggles = 0;
			state = READY;
			handleLed.timer_seted = false;
		}
	}
	return state;
}

void destroyHandleLed(void)
{
	closeLed();
	timer_destroy();
}
