#include "blinker.h"
#include "led.h"
#include "timer.h"

static short * progress;
static CLOCK timer;

void blinker_init(short * const progress_injected)
{
	progress = progress_injected;
	timer = timer_create();
}

void blinker_do(void)
{
	int current_time = timer_getTime(&timer, MILLISECONDS);
	int toggle_time = -(*progress)*484/100 + 500;
	if(current_time >= toggle_time){
		led_toggle();
		timer_reset(&timer);
	}
}
