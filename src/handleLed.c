#include "handleLed.h"
struct Led{
	double time_toggle;
	bool work_cicle_seted;
	short num_toggles;
}led;
static TIMER led_timer;
void initHandleLed(void)
{
	initTimer();
	openLed();
	led_timer = newTimer();
	led.time_toggle = 0;
	led.work_cicle_seted = false;
	led.num_toggles = 0;
}

static void updateTimeToggle(double work_cicle);
static void writeToTimer(double work_cicle);
static bool timerSeted(void);

void writeToLed(double work_cicle)
{
	if(!timerSeted()){
		writeToTimer(work_cicle);
	}
}
static bool timerSeted(void)
{
	return led.work_cicle_seted;
}
static void writeToTimer(double work_cicle)
{
		updateTimeToggle(work_cicle);
		enableTimer(led_timer);
		led.work_cicle_seted = true;
}
static void updateTimeToggle(double work_cicle)
{
	if(work_cicle > 100)
		work_cicle = 100;
	else if(work_cicle < 0)
		work_cicle = 0;

	led.time_toggle =-492/100.0*work_cicle+500;
}

static void enableRewriteCicle(void);
static void checkMinimunToggles(void);
static bool timeReached(void);

void updateLed(void)
{
	if(timeReached()){
		toggleLed();
		checkMinimunToggles();
		reinitTimer(led_timer);
	}
}
static bool timeReached(void)
{
	uint16_t elapsed_time = getTimer(led_timer, MILLISECONDS);
	return elapsed_time >= led.time_toggle;
}
static void checkMinimunToggles(void)
{
	led.num_toggles++;
	if(led.num_toggles == 2){
		enableRewriteCicle();
	}
}
static void enableRewriteCicle(void)
{
	led.num_toggles = 0;
	led.work_cicle_seted = false;
}
