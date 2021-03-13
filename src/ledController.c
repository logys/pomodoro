#include "ledController.h"
#include "led.h"
#include "blinker.h"

static short const * progress;
static bool const * finished;

void ledController_init(short const led_pin,
			bool * const finished_injected,
			short const * const progress_injected)
{
	progress = progress_injected;
	finished = finished_injected;
	led_open(led_pin);
	blinker_init(progress);
}

void ledController_do(void)
{
	if(*finished)
		led_off();
	else
		blinker_do();
}
