#include "unity.h"
#include "../src/pomodoro.h"

static Pomodoro pomodoro;

void setUp(void)
{	
	pomodoro_init(&pomodoro);
}
void tearDown(void)
{
}
