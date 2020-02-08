#include "unity.h"

#include "pomodoro_pause.h"
#include "mock_timer.h"
#include "mock_handleLed.h"

void setUp(void)
{
	initTimer_Expect();
	initHandleLed_Expect();
	newTimer_ExpectAndReturn(NULL);
	initPause();
}

void tearDown(void)
{
	destroyTimer_Ignore();
	destroyHandleLed_Ignore();
	destroyPause();
}

void setTimerFirstTime(void)
{
	reinitTimer_Expect(NULL);
}
void setMillisecondsOnTimer(double time)
{
	getTimer_ExpectAndReturn(NULL, MILLISECONDS, time);
}
void assertLed(void)
{
	updateLed_ExpectAndReturn(85, 0);
}
void test_unreached_time_return_ACTION_RUNNING(void)
{
	setMillisecondsOnTimer(3000);
	setTimerFirstTime();
	assertLed();
	TEST_ASSERT_EQUAL(ACTION_RUNNING, pomodoro_pause());
}
void test_only_init_timer_one_time(void)
{
	setMillisecondsOnTimer(2000);
	setTimerFirstTime();
	assertLed();
	TEST_ASSERT_EQUAL(ACTION_RUNNING, pomodoro_pause());
	
	setMillisecondsOnTimer(2001);
	assertLed();
	TEST_ASSERT_EQUAL(ACTION_RUNNING, pomodoro_pause());
}
void test_reinit_timer_if_last_call_was_to_50ms(void)
{
	setMillisecondsOnTimer(2000);
	setTimerFirstTime();
	assertLed();
	TEST_ASSERT_EQUAL(ACTION_RUNNING, pomodoro_pause());

	setMillisecondsOnTimer(2050);
	setTimerFirstTime();
	assertLed();
	TEST_ASSERT_EQUAL(ACTION_RUNNING, pomodoro_pause());
}
void test_write_to_led(void)
{
	setMillisecondsOnTimer(1000);
	setTimerFirstTime();
	assertLed();
	TEST_ASSERT_EQUAL(ACTION_RUNNING, pomodoro_pause());
}
void test_return_reached_on_five_minutes(void)
{
	int max_minutes_of_pause_session = 60*1000*5;
	setMillisecondsOnTimer(max_minutes_of_pause_session);
	setTimerFirstTime();
	assertLed();
	TEST_ASSERT_EQUAL(ACTION_REACHED, pomodoro_pause());
}
void test_return_reached_until_reinit_time(void)
{
	int max_minutes_of_pause_session = 60*1000*5;
	setMillisecondsOnTimer(max_minutes_of_pause_session);
	setTimerFirstTime();
	assertLed();
	pomodoro_pause();

	setMillisecondsOnTimer(max_minutes_of_pause_session + 49);
	assertLed();
	TEST_ASSERT_EQUAL(ACTION_REACHED, pomodoro_pause());
}
void test_after_session_reached_init_new_session_after_50_ms(void)
{
	setMillisecondsOnTimer(60*1000*5);
	setTimerFirstTime();
	assertLed();
	TEST_ASSERT_EQUAL(ACTION_REACHED, pomodoro_pause());

	setMillisecondsOnTimer(10);
	setTimerFirstTime();
	assertLed();
	TEST_ASSERT_EQUAL(ACTION_RUNNING, pomodoro_pause());
}
