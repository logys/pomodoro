#include "unity.h"

#include "../src/progress.h"
#include "../src/pomodoro.h"
#include "spys/millis_spy.h"

Pomodoro pomodoro;
void setUp(void)
{
}

void tearDown(void)
{
}

void test_calculate_progress_at_init(void)
{
	pomodoro.session.session_time = 5;
	pomodoro.session.acumulated_time = 0;

	pomodoro.progress = progress_update(pomodoro.session);
	TEST_ASSERT_EQUAL(0, pomodoro.progress);
}

void test_calculate_progress_at_fiven_time_for_five_minutes(void)
{
	pomodoro.session.session_time = 5;
	pomodoro.session.acumulated_time = 2.5;

	pomodoro.progress = progress_update(pomodoro.session);
	TEST_ASSERT_EQUAL(50, pomodoro.progress);
}
