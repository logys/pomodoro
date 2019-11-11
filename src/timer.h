#ifndef _TIMER_H
#define _TIMER_H
#include "delay.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
void initTimer(void);
void destroyTimer(void);

typedef enum {UNKNOWN = -1, UNREACHED, READY}ALARM_STATE;
typedef enum {TIMER_POMODORO, TIMER_DELAY, TIMER_BUTTONS, TIMER_BUTTONS_SAMPLES,
		TIMER_LED, TIMER_BUZZER}ALARM_ID;
ALARM_STATE getAlarm(ALARM_ID);

typedef enum {MINUTES, SECONDS, MILLISECONDS}UNIT_TIME;
void setAlarm(ALARM_ID, uint16_t time, UNIT_TIME);

typedef struct Timer * TIMER;
TIMER newTimer(void);
void setTimer(TIMER timer, double time, UNIT_TIME);
double getTimer(TIMER timer, UNIT_TIME);
void reinitTimer(TIMER timer);
void pauseTimer(TIMER timer);
void resumeTimer(TIMER timer);
void delay(uint32_t time_ms);

#endif // _TIMER_H
