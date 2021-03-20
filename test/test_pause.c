#include "unity.h"

#include "../src/pause.h"
#include "fff.h"
#include "stdint.h"

DEFINE_FFF_GLOBALS;

FAKE_VOID_FUNC(timer_create);
FAKE_VOID_FUNC(timer_restart);
FAKE_VALUE_FUNC(uint32_t, timer_getTime);

void setUp(void)
{
	pause_init();
}

void tearDown(void)
{
}

void test_always_progress_is_eigty_percent(void)
{
	timer_getTime_fake.return_val = 1;

	short progress = pause_do();

	TEST_ASSERT_EQUAL(80, progress);
}

void test_finished_if_elapsed_five_minutes(void)
{
	timer_getTime_fake.return_val = 5;
	
	short progress = pause_do();

	TEST_ASSERT_EQUAL(100, progress);
}

void test_finished_false_before_five_minutes(void)
{
	timer_getTime_fake.return_val = 4;
	
	short progress = pause_do();

	TEST_ASSERT_EQUAL(80, progress);
}
