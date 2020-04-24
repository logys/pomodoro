#include "unity.h"
#include "event_input.h"
#include "push_driver.h"
#include "timer.h"
#include "millis.h"
#include "stub_io.h"
#include "stub_interrupt.h"

void setUp(void)
{
	initEventInput();
}

void tearDown(void)
{

}

void test_event_no_push(void)
{
	push_set(0);
	TEST_ASSERT_EQUAL(NONE, readEvent());
}

void test_event_first_push(void)
{
	push_set(1);
	TEST_ASSERT_EQUAL(PLAY_PAUSE, readEvent());
}
 
void test_event_push_return_play_pause_only_one_time(void)
{
	push_set(0);
	TEST_ASSERT_EQUAL(NONE, readEvent());

	push_set(1);
	TEST_ASSERT_EQUAL(PLAY_PAUSE, readEvent());

	push_set(1);
	addMillis(1000);
	TEST_ASSERT_EQUAL(NONE, readEvent());
}

void test_event_return_after_2_seconds_poweroff(void)
{
	push_set(0);
	TEST_ASSERT_EQUAL(NONE, readEvent());

	push_set(1);
	TEST_ASSERT_EQUAL(PLAY_PAUSE, readEvent());

	push_set(1);
	addMillis(2000);
	TEST_ASSERT_EQUAL(POWEROFF, readEvent());
}
