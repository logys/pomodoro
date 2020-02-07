#ifndef POMODORO_PAUSE_H
#define POMODORO_PAUSE_H
#include "timer.h"
#include "handleLed.h"
#include "action.h"

void initPause(void);
RUN_STATE pomodoro_pause(void);
void destroyPause(void);
#endif // POMODORO_PAUSE_H
