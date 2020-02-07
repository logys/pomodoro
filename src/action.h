#ifndef ACTION_H
#define ACTION_H
#include"private_actions.h"
#include"pomodoro_run.h"
#include"pomodoro_pause.h"
#include"pomodoro_poweroff.h"
void initAction(void);
void destroyAction(void);
RUN_STATE (*action)(void);
void setActionPowerOff(void);
void setActionTogglePlayPause(void);

#endif // ACTION_H
