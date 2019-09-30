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
	TEST_ASSERT_EQUAL(UNKNOWN, getAlarm());
}

void test_set_alarm_unreached(void)
{
	setAlarm(10, SECONDS);
	fake_setMillis(0);
	TEST_ASSERT_EQUAL(UNREACHED, getAlarm());
}

void test_set_alarm_reached_seconds(void)
{
	setAlarm(10, SECONDS);
	fake_setMillis(1000*10);
	TEST_ASSERT_EQUAL(READY, getAlarm());
}

void test_set_alarm_reached_minutes(void)
{
	setAlarm(3, MINUTES);
	fake_setMillis(1000*60*3);
	TEST_ASSERT_EQUAL(READY, getAlarm());
}

void test_set_alarm_reached_milliseconds(void)
{
	setAlarm(30, MILLISECONDS);
	fake_setMillis(100);
	TEST_ASSERT_EQUAL(READY, getAlarm());
}

void test_set_multiple_times(void)
{
	fake_setMillis(0);
	TEST_ASSERT_EQUAL(UNKNOWN, getAlarm());
	setAlarm(10, SECONDS);
	fake_setMillis(9*1000);
	TEST_ASSERT_EQUAL(UNREACHED, getAlarm());
	setAlarm(20, SECONDS);
	fake_setMillis(20*1000);
	TEST_ASSERT_EQUAL(READY, getAlarm());
}
