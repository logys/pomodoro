#include "unity.h"
#include "main.h"
#include "mock_pomodoro.h"
#include "pomodoro_sessions.h"


void setUp(void)
{
}

void tearDown(void)
{
}

void test_set_sessiones(void)
{
	initPomodoro_Expect();
	updatePomodoro_ExpectAndReturn(0);
	appMain();
}
