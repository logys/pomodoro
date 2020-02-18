#include "pomodoro_poweroff.h"

void initPowerOff(void)
{
}
void destroyPowerOff(void)
{
}
static void setupIRButton(void)
{
	GIMSK |= (1<<PCIE);
	PCMSK |= (1<<PCINT3);
}
RUN_STATE pomodoro_off(void)
{
	sleepLed();
	setupIRButton();
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);
	cli();
	sleep_enable();
	sleep_bod_disable();
	sei();
	sleep_cpu();
	sleep_disable();
	sei();
	reinitSessions();
	wakeUpLed();
	return ACTION_POWEROFF;
}

#ifndef TEST
ISR(PCINT0_vect)
{
//	GIMSK &= ~(1<<PCIE);
}
#endif
