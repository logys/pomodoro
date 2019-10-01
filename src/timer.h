#ifndef _TIMER_H
#define _TIMER_H
#include "delay.h"
#include <stdint.h>
void initTimer(void);

typedef enum {UNKNOWN = -1, UNREACHED, READY}ALARM_STATE;
typedef enum {TIMER_POMODORO, TIMER_DELAY, TIMER_BUTTONS}ALARM_ID;
ALARM_STATE getAlarm(ALARM_ID);

typedef enum {MINUTES, SECONDS, MILLISECONDS}UNIT_TIME;
void setAlarm(ALARM_ID, uint16_t time, UNIT_TIME);

void delay(uint32_t time_ms);

#endif // _TIMER_H
