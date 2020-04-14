#include "unity.h"
#include "event_input.h"
#include "mock_entrada.h"
#include "mock_timer.h"
/*

void setUp(void)
{
	openPush_Expect();
	initTimer_Expect();
	newTimer_ExpectAndReturn(NULL);
	initEventInput();
}

void tearDown(void)
{
}

void test_event_no_push(void)
{
	readPush_ExpectAndReturn(OFF);
	TEST_ASSERT_EQUAL(NONE, readEvent());
}

void test_event_first_push(void)
{
	readPush_ExpectAndReturn(ON);
	enableTimer_Expect(NULL);
	TEST_ASSERT_EQUAL(PLAY_PAUSE, readEvent());
}
 
void test_event_push_return_play_pause_only_one_time(void)
{
	readPush_ExpectAndReturn(OFF);
	TEST_ASSERT_EQUAL(NONE, readEvent());

	readPush_ExpectAndReturn(ON);
	enableTimer_Expect(NULL);
	TEST_ASSERT_EQUAL(PLAY_PAUSE, readEvent());

	readPush_ExpectAndReturn(ON);
	getTimer_ExpectAndReturn(NULL, SECONDS, 1);
	TEST_ASSERT_EQUAL(NONE, readEvent());

	readPush_ExpectAndReturn(ON);
	getTimer_ExpectAndReturn(NULL, SECONDS, 1.5);
	TEST_ASSERT_EQUAL(NONE, readEvent());
}

void test_event_return_after_2_seconds_poweroff(void)
{
	readPush_ExpectAndReturn(OFF);
	TEST_ASSERT_EQUAL(NONE, readEvent());

	readPush_ExpectAndReturn(ON);
	enableTimer_Expect(NULL);
	TEST_ASSERT_EQUAL(PLAY_PAUSE, readEvent());

	readPush_ExpectAndReturn(ON);
	getTimer_ExpectAndReturn(NULL, SECONDS, 2);
	TEST_ASSERT_EQUAL(POWEROFF, readEvent());
}
*/
