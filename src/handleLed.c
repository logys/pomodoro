#include "handleLed.h"
struct Led{
	uint16_t time_toggle;
}led;
static TIMER led_timer;
void initHandleLed(void)
{
	initTimer();
	openLed();
	led_timer = newTimer();
	led.time_toggle = 0;
}

void writeToLed(double workCicle)
{
	led.time_toggle = 500;
	setTimer(led_timer, led.time_toggle, MILLISECONDS);
}

void updateLed(void)
{
	uint16_t elapsed_time = getTimer(led_timer, MILLISECONDS);
	if(elapsed_time >= led.time_toggle)
		toggleLed();
}
