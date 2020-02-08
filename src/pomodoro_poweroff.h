#ifndef POMODORO_POWEROFF_H
#define POMODORO_POWEROFF_H
#include "private_actions.h"
#include "pomodoro_sessions.h"
void initPowerOff(void);
void destroyPowerOff(void);

RUN_STATE pomodoro_off(void);

#endif // POMODORO_POWEROFF_H
