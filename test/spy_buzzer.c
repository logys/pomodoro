#include"spy_buzzer.h"
static bool called = false;
bool spy_buzzerCalled(void)
{
	return called;
}
void buzzer_a(short ticks, unsigned int tiempo_ms)
{
	if(ticks > 0)
		called = true;
	else
		called = false;
}

void buzzer_open(void)
{
}
