#include "blinker.h"
#include "led.h"
#include "timer.h"

static short const * progress;
static bool const * finished;
static CLOCK timer;

void blinker_init(short const * const progress_injected, bool const * const finished_injected)
{
	progress = progress_injected;
	finished = finished_injected;

	timer = timer_create();
}

void blinker_do(void)
{
	if(*progress >= 100 || *finished){
		led_off();
		return ;
	}
	int current_time = timer_getTime(&timer, MILLISECONDS);
	int cp = *progress;
	int toggle_time = -492/100.0*cp + 500;
	if(current_time >= toggle_time){
		led_toggle();
		timer_restart(&timer);
	}
}

