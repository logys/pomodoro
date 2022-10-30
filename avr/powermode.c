#include "hal.h"
#include <avr/sleep.h>

void standBy(void)
{
	set_sleep_mode(SLEEP_MODE_STANDBY);
	sleep_mode();
}

void idle(void)
{
}
