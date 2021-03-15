#ifndef _TIMER_H
#define _TIMER_H

#include <stdint.h>

typedef enum TIME_TYPE {MILLISECONDS, SECONDS}TIME_TYPE;

typedef struct Clock{
	uint32_t time_at_start;
}CLOCK;

CLOCK timer_create(void);
uint32_t timer_getTime(CLOCK *, TIME_TYPE);
void timer_restart(CLOCK *);

#endif // _TIMER_H
