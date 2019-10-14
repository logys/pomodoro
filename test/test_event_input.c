#include "unity.h"
#include "event_input.h"
#include "mock_entrada.h"
#include "mock_timer.h"


void setUp(void)
{
	openPush_Ignore();
	initTimer_Ignore();
	initEventInput();
}

void tearDown(void)
{
}

void test_event_no_push(void)
{
	readPush_ExpectAndReturn(0);
	TEST_ASSERT_EQUAL(NONE, readEvent());
}

void test_event_first_push(void)
{
	readPush_ExpectAndReturn(1);
	getAlarm_ExpectAndReturn(TIMER_BUTTONS_SAMPLES, READY);
	getAlarm_ExpectAndReturn(TIMER_BUTTONS, UNREACHED);
//	setAlarm_Expect(TIMER_BUTTONS_SAMPLES, 100, MILLISECONDS);
	TEST_ASSERT_EQUAL(PLAY_PAUSE, readEvent());
}

void test_event_less_100ms_only_one_time(void)
{
	readPush_ExpectAndReturn(1);
	getAlarm_ExpectAndReturn(TIMER_BUTTONS_SAMPLES, UNREACHED);
	getAlarm_ExpectAndReturn(TIMER_BUTTONS, UNREACHED);
	TEST_ASSERT_EQUAL(PLAY_PAUSE, readEvent());
	
	readPush_ExpectAndReturn(1);
	setAlarm_Expect(TIMER_BUTTONS_SAMPLES, 100, MILLISECONDS);
	setAlarm_Expect(TIMER_BUTTONS, 2, SECONDS);
	getAlarm_ExpectAndReturn(TIMER_BUTTONS_SAMPLES, UNREACHED);
	getAlarm_ExpectAndReturn(TIMER_BUTTONS, UNREACHED);
	TEST_ASSERT_EQUAL(NONE, readEvent());
}

void test_event_after_100ms_return_again(void)
{
	readPush_ExpectAndReturn(1);
	getAlarm_ExpectAndReturn(TIMER_BUTTONS_SAMPLES, UNREACHED);
	getAlarm_ExpectAndReturn(TIMER_BUTTONS, UNREACHED);
	TEST_ASSERT_EQUAL(PLAY_PAUSE, readEvent());

	readPush_ExpectAndReturn(1);
	setAlarm_Expect(TIMER_BUTTONS_SAMPLES, 100, MILLISECONDS);
	setAlarm_Expect(TIMER_BUTTONS, 2, SECONDS);
	getAlarm_ExpectAndReturn(TIMER_BUTTONS_SAMPLES, READY);
	getAlarm_ExpectAndReturn(TIMER_BUTTONS, UNREACHED);
	TEST_ASSERT_EQUAL(PLAY_PAUSE, readEvent());
}

void test_event_poweroff(void)
{
	readPush_ExpectAndReturn(1);
	getAlarm_ExpectAndReturn(TIMER_BUTTONS_SAMPLES, UNREACHED);
	getAlarm_ExpectAndReturn(TIMER_BUTTONS, UNREACHED);
	TEST_ASSERT_EQUAL(PLAY_PAUSE, readEvent());

	readPush_ExpectAndReturn(1);
	setAlarm_Expect(TIMER_BUTTONS_SAMPLES, 100, MILLISECONDS);
	setAlarm_Expect(TIMER_BUTTONS, 2, SECONDS);
	getAlarm_ExpectAndReturn(TIMER_BUTTONS_SAMPLES, READY);
	getAlarm_ExpectAndReturn(TIMER_BUTTONS, READY);
	TEST_ASSERT_EQUAL(POWEROFF, readEvent());
}
