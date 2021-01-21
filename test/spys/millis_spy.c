#include "millis_spy.h"
static uint32_t current_time = 0;
void set_millis_spy(uint32_t time)
{
	current_time = time;
}
uint32_t millis(void)
{
	return current_time;
}
void millis_init(void)
{
	current_time = 0;
}
