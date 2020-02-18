#ifndef POMODORO_POWEROFF_H
#define POMODORO_POWEROFF_H
#include "private_actions.h"
#include "pomodoro_sessions.h"
#include "led.h"
#ifndef TEST
	#include<avr/sleep.h>
	#include<avr/interrupt.h>
#else 
	#include"stub_io.h"
	#include"stub_sleep.h"
	#include"stub_interrupt.h"
#endif

void initPowerOff(void);
void destroyPowerOff(void);

RUN_STATE pomodoro_off(void);

#endif // POMODORO_POWEROFF_H
