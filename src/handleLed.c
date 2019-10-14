#include "handleLed.h"

typedef struct LedHandler{
	int8_t state;
	int8_t toggling;
	int8_t alarm;
	int8_t cicle;
	uint16_t time;
}ledHandler;
static ledHandler led;
void initHandleLed(void)
{
	initTimer();
	openLed();
	led.state = UNKNOWN;
	led.toggling = UNKNOWN;
	led.time = UNKNOWN;
	led.alarm = UNKNOWN;
	led.cicle = UNKNOWN;
}

void writeToLed(double workCicle)
{
 	if(led.state != ON)
		return;
	if(workCicle > 100)
		workCicle = 100;
	if(workCicle < 0)
		workCicle = 0;
	if(led.toggling != ON){
		led.time = (uint16_t)(-492/100.0*workCicle + 500);
		led.toggling = ON;
		led.cicle = 1;
		setAlarm(TIMER_LED, led.time, MILLISECONDS); 
	}
}

void updateLed(void)
{
 	if(led.state != ON)
		return;
	led.alarm = getAlarm(TIMER_LED);
	if(led.alarm == READY){
		toggleLed();
		setAlarm(TIMER_LED, led.time, MILLISECONDS); 
		led.cicle++;
		if(led.cicle >= 2)
			led.toggling = OFF;
	}
}

void handleLedOn(void)
{
	led.state = ON;
}

void handleLedOff(void)
{
	led.state = OFF;
}
