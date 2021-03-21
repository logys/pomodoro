#include "unity.h"

#include "../src/play.h"
#include "fff.h"
#include <stdint.h>

DEFINE_FFF_GLOBALS;
FAKE_VALUE_FUNC(uint32_t, timer_getTime);
FAKE_VOID_FUNC(timer_create);
FAKE_VOID_FUNC(timer_restart);

double one_minute;

void setUp(void)
{
	RESET_FAKE(timer_getTime);
	one_minute = 1;
	play_init(one_minute);
}

void tearDown(void)
{
}

void test_progress_update_only_on_less_delta(void)
{
	timer_getTime_fake.return_val = 250;

	short progress = play_do();

	TEST_ASSERT_FLOAT_WITHIN(0.05, 0,(float)(progress));
}

void test_progress_ten_percent(void)
{
	int steps_to_reach_six_seconds = 31;
	for(int i = 0; i < steps_to_reach_six_seconds; i++){
		timer_getTime_fake.return_val = 200;
		play_do();
	}

	short progress = play_do();

	TEST_ASSERT_EQUAL(10, progress);
}
