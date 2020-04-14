#ifndef _TIMER_H
#define _TIMER_H
#include "millis.h"
typedef struct Timer * TIMER;

TIMER timer_create(void);
void timer_destroy(TIMER);
void timer_updateLoop();
void timer_setCallback(TIMER, uint32_t time_ms, void(*)(void));
uint32_t timer_getMilliseconds(TIMER);
void timer_start(TIMER);
void timer_pause(TIMER);
void timer_resume(TIMER);
void timer_reinit(TIMER);
void delay(uint32_t time_ms);

#endif // _TIMER_H
