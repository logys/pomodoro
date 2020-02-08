#include "pomodoro_poweroff.h"

void initPowerOff(void)
{

}
void destroyPowerOff(void)
{

}

RUN_STATE pomodoro_off(void)
{
	reinitSessions();
	return 0;
}
