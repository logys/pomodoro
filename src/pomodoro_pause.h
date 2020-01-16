#ifndef POMODORO_PAUSE_H
#define POMODORO_PAUSE_H
#include "private_actions.h"
#include "timer.h"
#include "handleLed.h"

void initPause(void);
RUN_STATE run(void);
void destroyPause(void);
#endif // POMODORO_PAUSE_H
