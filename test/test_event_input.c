#include "unity.h"
#include "event_input.h"
#include "push_driver.h"
#include "timer.h"
#include "millis.h"
#include "stub_io.h"
#include "stub_interrupt.h"

void setUp(void)
{
	eventInput_create();
}

void tearDown(void)
{
	eventInput_destroy();
}

void test_event_no_push(void)
{
	push_set(0);
	TEST_ASSERT_EQUAL(NONE, eventInput_read());
}

void test_event_first_push(void)
{
	push_set(1);
	TEST_ASSERT_EQUAL(PLAY_PAUSE, eventInput_read());
}
 
void test_event_push_return_play_pause_only_one_time(void)
{
	push_set(0);
	TEST_ASSERT_EQUAL(NONE, eventInput_read());

	push_set(1);
	TEST_ASSERT_EQUAL(PLAY_PAUSE, eventInput_read());

	push_set(0);
	addMillis(1000);
	TEST_ASSERT_EQUAL(NONE, eventInput_read());
}

void test_event_return_after_2_seconds_poweroff(void)
{
	push_set(0);
	TEST_ASSERT_EQUAL(NONE, eventInput_read());

	push_set(1);
	TEST_ASSERT_EQUAL(PLAY_PAUSE, eventInput_read());

	push_set(1);
	addMillis(50);
	TEST_ASSERT_EQUAL(NONE, eventInput_read());

	push_set(1);
	addMillis(3000);
	TEST_ASSERT_EQUAL(POWEROFF, eventInput_read());
}
