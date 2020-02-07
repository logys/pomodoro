#ifndef POMODORO_RUN_H
#define POMODORO_RUN_H
#include <math.h>
#include "timer.h"
#include "buzzer.h"
#include "handleLed.h"
#include "pomodoro_sessions.h"
#include "action.h"

void initRun(void);
void destroyRun(void);

RUN_STATE pomodoro_run(void);


#endif // POMODORO_RUN_H
