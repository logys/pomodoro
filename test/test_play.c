#include "unity.h"

#include "../src/play.h"
#include "progress_spy.h"
#include "spys/timer_spy.h"
#include "../src/session.h"

double one_minute;
CLOCK timer; 
void setUp(void)
{
	play_init(&timer);
	one_minute = 1;
	timer_setTime_spy(0, MILLISECONDS);
}

void tearDown(void)
{
}

void test_progress_update_only_on_less_delta(void)
{
	play_setSessionTime(1);
	timer_addTime_spy(250, MILLISECONDS);

	double progress = play_do();

	TEST_ASSERT_FLOAT_WITHIN(0.05, 0, progress);
}

void test_progress_ten_percent(void)
{
	play_setSessionTime(one_minute);
	int steps_to_reach_six_seconds = 31;
	for(int i = 0; i < steps_to_reach_six_seconds; i++){
		timer_addTime_spy(200, MILLISECONDS);
		play_do();
	}

	double progress = play_do();

	TEST_ASSERT_EQUAL(10, progress);
}
