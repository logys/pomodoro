#include "unity.h"

#include "../src/play.h"
#include "progress_spy.h"
#include "spys/timer_spy.h"
#include "../src/session.h"

double one_minute;
short progress;

void setUp(void)
{

	one_minute = 1;
	play_init(one_minute, &progress);
	timer_setTime_spy(0, MILLISECONDS);
}

void tearDown(void)
{
}

void test_progress_update_only_on_less_delta(void)
{
	timer_addTime_spy(250, MILLISECONDS);

	play_do();

	TEST_ASSERT_FLOAT_WITHIN(0.05, 0,(float)(progress));
}

void test_progress_ten_percent(void)
{
	int steps_to_reach_six_seconds = 31;
	for(int i = 0; i < steps_to_reach_six_seconds; i++){
		timer_addTime_spy(200, MILLISECONDS);
		play_do();
	}

	play_do();

	TEST_ASSERT_EQUAL(10, progress);
}
