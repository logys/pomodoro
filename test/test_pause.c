#include "unity.h"

#include "../src/pause.h"
#include "fff.h"
#include "stdint.h"

DEFINE_FFF_GLOBALS;

FAKE_VOID_FUNC(timer_create);
FAKE_VALUE_FUNC(uint32_t, timer_getTime);

short progress;
bool finished;

void setUp(void)
{
	progress = 0;
	pause_init(&progress, &finished);
}

void tearDown(void)
{
}

void test_always_progress_is_eigty_percent(void)
{
	progress = 0;

	pause_do();

	TEST_ASSERT_EQUAL(80, progress);
}

void test_finished_if_elapsed_five_minutes(void)
{
	finished = false;
	timer_getTime_fake.return_val = 5;
	
	pause_do();

	TEST_ASSERT(finished);
}

void test_finished_false_before_five_minutes(void)
{
	finished = true;
	timer_getTime_fake.return_val = 4;
	
	pause_do();

	TEST_ASSERT_FALSE(finished);
}
