#ifndef POMODORO_RUN_H
#define POMODORO_RUN_H
#include <math.h>
#include "timer.h"
#include "buzzer.h"
#include "handleLed.h"
#include "pomodoro_sessions.h"

typedef enum {RUNNING, REACHED, POWEROFF, PAUSE}RUN_STATE;

void initRun(void);
void destroyRun(void);

RUN_STATE run(void);


#endif // POMODORO_RUN_H
