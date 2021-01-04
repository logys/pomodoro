#include "handleLed.h"
#include "stdbool.h"
#include "stdint.h"
#include "stdlib.h"

static TIMER led_timer = NULL;
typedef enum{STATE_INIT, STATE_HALF, STATE_SECOND_HALF}STATE_HANDLE;
static STATE_HANDLE current_state;

void handleLed_create(void)
{
	led_open();
	timer_init();
	led_timer = timer_createNew();
	current_state = STATE_INIT;
}
void handleLed_destroy(void)
{
	led_close();
	free(led_timer);
	led_timer = NULL;
	timer_destroy();
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
static double time_period = 0;
void init_ms(double work_cicle)
{
	time_period = 2*calculateHalfPeriod(work_cicle);
	timer_start(led_timer);
	led_on();
	current_state = STATE_HALF;
}
void half_period(double wc)
{
	if(timer_getMilliseconds(led_timer) >= time_period/2.0){
		led_off();
		current_state = STATE_SECOND_HALF;
	}

}
void second_half(double wc)
{
	if(timer_getMilliseconds(led_timer) >= time_period){
		current_state = STATE_INIT;
	}
}
void (*state_handleLed[])(double) = {init_ms, half_period, second_half};
void handleLed_update(double work_cicle)
{
	state_handleLed[current_state](work_cicle);
}
void handleLed_off(void)
{
}
