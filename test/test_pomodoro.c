#include "unity.h"
#include "../src/pomodoro.h"
#include "../src/session.h"
#include "../src/time.h"
#include "../test/spys/millis_spy.h"

#define HALF_TIME_SESSION_MS 2.5*60*1000

static Pomodoro pomodoro;
void setUp(void)
{	
	pomodoro_init(&pomodoro);
	pomodoro.session.session_time = 5;
	millis_init();
}
void tearDown(void)
{
}
