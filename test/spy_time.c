#include"spy_time.h"
static uint32_t time_millis = 0;
void spy_addTimeMillis(uint32_t time)
{
	time_millis += time;
}
uint32_t millis(void)
{
	return time_millis;
}
