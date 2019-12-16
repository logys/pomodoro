#ifndef _TIMER_H
#define _TIMER_H
#include "delay.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Timer * TIMER;
typedef enum {UNKNOWN = -1, MINUTES, SECONDS, MILLISECONDS}UNIT_TIME;

void initTimer(void);
void destroyTimer(TIMER timer);
TIMER newTimer(void);
void enableTimer(TIMER);
void disableTimer(TIMER);
void setAlarm(TIMER timer, double time, UNIT_TIME);
double getTimer(TIMER timer, UNIT_TIME);
void pauseTimer(TIMER timer);
void resumeTimer(TIMER timer);
void reinitTimer(TIMER timer);
void delay(uint32_t time_ms);

#endif // _TIMER_H
