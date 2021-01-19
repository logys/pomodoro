#include "time.h"

void time_setCurrent(Time *object, uint32_t time)
{
	object->current = time;
}
double time_getCurrent(Time *object)
{
	return object->current;
}
