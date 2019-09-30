#ifndef _TIMER_H
#define _TIMER_H
#include "delay.h"
#include <stdint.h>
typedef enum {UNKNOWN = -1, UNREACHED, READY}ALARM_STATE;
void initTimer(void);
ALARM_STATE getAlarm(void);

typedef enum {MINUTES, SECONDS, MILLISECONDS}UNIT_TIME;
void setAlarm(uint16_t time, UNIT_TIME);

#endif // _TIMER_H
