#include "unity.h"
#include "timer.h"
#include "spy_delay.h"

void setUp(void)
{
	initTimer();
}

void tearDown(void)
{
}

void test_initTimer_unkw(void)
{
	TEST_ASSERT_EQUAL(UNKNOWN, getAlarm(TIMER_POMODORO));
}

void test_set_alarm_unreached(void)
{
	fake_setMillis(0);
	setAlarm(TIMER_POMODORO,10, SECONDS);
	fake_setMillis(0);
	TEST_ASSERT_EQUAL(UNREACHED, getAlarm(TIMER_POMODORO));
}

void test_set_alarm_reached_seconds(void)
{
	fake_setMillis(0);
	setAlarm(TIMER_POMODORO,10, SECONDS);
	fake_setMillis(1000*10);
	TEST_ASSERT_EQUAL(READY, getAlarm(TIMER_POMODORO));
}

void test_set_alarm_reached_minutes(void)
{
	fake_setMillis(0);
	setAlarm(TIMER_POMODORO,3, MINUTES);
	fake_setMillis(1000*60*3);
	TEST_ASSERT_EQUAL(READY, getAlarm(TIMER_POMODORO));
}

void test_set_alarm_reached_milliseconds(void)
{
	fake_setMillis(0);
	setAlarm(TIMER_POMODORO,30, MILLISECONDS);
	fake_setMillis(100);
	TEST_ASSERT_EQUAL(READY, getAlarm(TIMER_POMODORO));
}

void test_set_multiple_times(void)
{
	fake_setMillis(0);
	TEST_ASSERT_EQUAL(UNKNOWN, getAlarm(TIMER_POMODORO));
	fake_setMillis(0);
	setAlarm(TIMER_POMODORO,10, SECONDS);
	fake_setMillis(9*1000);
	TEST_ASSERT_EQUAL(UNREACHED, getAlarm(TIMER_POMODORO));
	fake_setMillis(0);
	setAlarm(TIMER_POMODORO,20, SECONDS);
	fake_setMillis(20*1000);
	TEST_ASSERT_EQUAL(READY, getAlarm(TIMER_POMODORO));
}

/*void test_delay(void)
{
	delay(100);
	fake_setMillis(50);
	TEST_ASSERT_EQUAL(UNREACHED, getAlarm(TIMER_POMODORO));
	fake_setMillis(100);
	TEST_ASSERT_EQUAL(READY, getAlarm(TIMER_POMODORO));
}*/

void test_set_alarm_buttons_and_pomodoro_unreached(void)
{
	fake_setMillis(0);
	setAlarm(TIMER_POMODORO, 1000, MILLISECONDS);
	fake_setMillis(500);
	TEST_ASSERT_EQUAL(UNREACHED, getAlarm(TIMER_POMODORO));
	fake_setMillis(0);
	setAlarm(TIMER_BUTTONS, 100, MILLISECONDS);
	fake_setMillis(90);
	TEST_ASSERT_EQUAL(UNREACHED, getAlarm(TIMER_BUTTONS));
}

void test_set_alarm_buttons_and_pomodoro_reached(void)
{
	fake_setMillis(0);
	setAlarm(TIMER_POMODORO, 1000, MILLISECONDS);
	fake_setMillis(1000);
	TEST_ASSERT_EQUAL(READY, getAlarm(TIMER_POMODORO));
	fake_setMillis(0);
	setAlarm(TIMER_BUTTONS, 100, MILLISECONDS);
	fake_setMillis(100);
	TEST_ASSERT_EQUAL(READY, getAlarm(TIMER_POMODORO));
}

void test_reach_alarm_diferent_millis(void)
{
	fake_setMillis(0);
	setAlarm(TIMER_POMODORO, 1000, MILLISECONDS);
	fake_setMillis(1000);
	TEST_ASSERT_EQUAL(READY, getAlarm(TIMER_POMODORO));
	setAlarm(TIMER_DELAY, 300, MILLISECONDS);
	fake_setMillis(1200);
	TEST_ASSERT_EQUAL(UNREACHED, getAlarm(TIMER_DELAY));
	fake_setMillis(1300);
	TEST_ASSERT_EQUAL(READY, getAlarm(TIMER_DELAY));
}
