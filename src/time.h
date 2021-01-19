#ifndef TIME_H
#define TIME_H
#include <stdint.h>
typedef struct Time{
	uint32_t current;
	uint32_t last;
}Time;

void time_setCurrent(Time *, uint32_t time);
double time_getCurrent(Time *);
#endif //TIME_H
