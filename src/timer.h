#ifndef _TIMER_H
#define _TIMER_H

#include<stdint.h>
typedef struct Timer * TIMER;

typedef struct Clock{
}CLOCK;

typedef enum TIME_TYPE {MILLISECONDS, SECONDS}TIME_TYPE;

void timer_init(void);
void timer_enable(CLOCK *);
double timer_getTime(CLOCK *, TIME_TYPE);
void timer_reset(CLOCK *);
CLOCK timer_create(void);

void timer_destroy(void);
TIMER timer_createNew(void);
uint32_t timer_getMilliseconds(TIMER);
void timer_start(TIMER);
void timer_pause(TIMER);
void timer_resume(TIMER);
void timer_reinit(TIMER);
void delay(uint32_t time_ms);

#endif // _TIMER_H
