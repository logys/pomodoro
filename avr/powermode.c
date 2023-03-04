#include "hal.h"
#include <avr/sleep.h>

void standBy(void)
{
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);
	sleep_mode();
}

void idle(void)
{
	set_sleep_mode(SLEEP_MODE_IDLE);
	sleep_mode();
}
