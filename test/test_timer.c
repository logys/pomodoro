#include "unity.h"
#include "timer.h"
#include "mock_delay.h"

struct Timer{
	uint32_t init_time;
	uint32_t end_time;;
};
static void setTimerOnTime(TIMER, double time, UNIT_TIME unit, uint32_t init_time);
void setUp(void)
{
	initTimer1Millis_Expect();
	initTimer();
}

void tearDown(void)
{
}

void test_initTimer_at_cero(void)
{
	TIMER test = newTimer();
	TEST_ASSERT_EQUAL(0, test->init_time);
	TEST_ASSERT_EQUAL(0, test->end_time);
}

int time_on_init = 1000;
int time_elapsed = 0;
void test_set_timer_milliseconds(void)
{
	TIMER test = newTimer();
	int milliseconds_for_set_timer = 2000;
	millis_ExpectAndReturn(time_on_init);
	setTimer(test, milliseconds_for_set_timer, MILLISECONDS);

	int total_time_in_timer = milliseconds_for_set_timer + time_on_init;
	TEST_ASSERT_EQUAL(time_on_init, test->init_time);
	TEST_ASSERT_EQUAL(total_time_in_timer, test->end_time);
}
void test_set_timer_seconds(void)
{
	TIMER test = newTimer();
	int seconds_for_set_timer = 5;
	millis_ExpectAndReturn(time_on_init);
	setTimer(test, seconds_for_set_timer, SECONDS);

	int total_time_in_timer = seconds_for_set_timer*1000 + time_on_init;
	TEST_ASSERT_EQUAL(time_on_init, test->init_time);
	TEST_ASSERT_EQUAL(total_time_in_timer, test->end_time);
}
void test_set_timer_minutes(void)
{
	TIMER test = newTimer();
	int minutes_for_set_timer = 7;
	millis_ExpectAndReturn(time_on_init);
	setTimer(test, minutes_for_set_timer, MINUTES);

	int total_time_in_timer = minutes_for_set_timer*1000*60 + time_on_init;
	TEST_ASSERT_EQUAL(time_on_init, test->init_time);
	TEST_ASSERT_EQUAL(total_time_in_timer, test->end_time);
}

void test_get_timer_milliseconds(void)
{
	TIMER test = newTimer();
	millis_ExpectAndReturn(time_on_init);
	int session_time_milliseconds = 2000;
	setTimer(test, session_time_milliseconds, MILLISECONDS);

	int milliseconds_elapsed = 1000;
	int milliseconds_from_init = milliseconds_elapsed + time_on_init;
	millis_ExpectAndReturn(milliseconds_from_init);
	TEST_ASSERT_EQUAL(milliseconds_elapsed, getTimer(test, MILLISECONDS));
}

void test_get_timer_seconds(void)
{
	TIMER test = newTimer();
	millis_ExpectAndReturn(time_on_init);
	setTimer(test, 2, SECONDS);

	int seconds_elapsed = 5;
	int milliseconds_from_init = seconds_elapsed*1000 + time_on_init;
	millis_ExpectAndReturn(milliseconds_from_init);
	TEST_ASSERT_EQUAL(seconds_elapsed, getTimer(test, SECONDS));
}

void test_get_timer_minutes(void)
{
	TIMER test = newTimer();
	millis_ExpectAndReturn(time_on_init);
	setTimer(test, 10, MINUTES);

	int minutes_elapsed = 7;
	int milliseconds_from_init = minutes_elapsed*1000*60 + time_on_init;
	millis_ExpectAndReturn(milliseconds_from_init);
	TEST_ASSERT_EQUAL(minutes_elapsed, getTimer(test, MINUTES));
}

void test_reinit_timer(void)
{
	TIMER test = newTimer();
	millis_ExpectAndReturn(time_on_init);
	setTimer(test, 10, MINUTES);

	int milliseconds_on_reinit = 10000;
	millis_ExpectAndReturn(milliseconds_on_reinit);
	reinitTimer(test);
	int milliseconds_after_reinit = 1000;
	millis_ExpectAndReturn(milliseconds_on_reinit + milliseconds_after_reinit);
	TEST_ASSERT_EQUAL(milliseconds_after_reinit, getTimer(test, MILLISECONDS));
}

void test_after_pause_get_same_time(void)
{
	TIMER test = newTimer();
	setTimerOnTime(test, 10, MINUTES, time_on_init);

	int time_on_pause = 2000;
	millis_ExpectAndReturn(time_on_pause);
	pauseTimer(test);

	int time_paused = time_on_pause - time_on_init;
	TEST_ASSERT_EQUAL(time_paused, getTimer(test, MILLISECONDS));
	TEST_ASSERT_EQUAL(time_paused/1000, getTimer(test, SECONDS));
}

void test_doble_pause(void)
{
	TIMER test = newTimer();
	setTimerOnTime(test, 10, MINUTES, time_on_init);

	int time_on_pause = 2000;
	millis_ExpectAndReturn(time_on_pause);
	pauseTimer(test);

	int second_time_on_pause = 3000;
//	millis_ExpectAndReturn(second_time_on_pause);
	pauseTimer(test);

//	millis_ExpectAndReturn(5000);
	int time_paused = time_on_pause - time_on_init;
	TEST_ASSERT_EQUAL(time_paused, getTimer(test, MILLISECONDS));
}

void test_resume_timer(void)
{
	TIMER test = newTimer();
	setTimerOnTime(test, 10, MINUTES, time_on_init);

	int time_on_pause = 2000;
	millis_ExpectAndReturn(time_on_pause);
	pauseTimer(test);

	int time_on_resume = 3000;
	millis_ExpectAndReturn(time_on_resume);
	resumeTimer(test);

	int time_after_resume = 4000;
	millis_ExpectAndReturn(time_after_resume);
	int time_whitout_pause = time_on_pause - time_on_init + time_after_resume - 
		time_on_resume;
	TEST_ASSERT_EQUAL(time_whitout_pause, getTimer(test, MILLISECONDS));
}

void test_resume_whitout_pause(void)
{
	TIMER test = newTimer();
	setTimerOnTime(test, 10, MINUTES, time_on_init);

	resumeTimer(test);
	resumeTimer(test);

	int time_after_resume = 4000;
	millis_ExpectAndReturn(time_after_resume);
	int time_elapsed = time_after_resume - time_on_init;
	TEST_ASSERT_EQUAL(time_elapsed, getTimer(test, MILLISECONDS));
}

void test_delay(void)
{
	millis_ExpectAndReturn(time_on_init);
	for(int i = 0; i<=100; i++)
		millis_ExpectAndReturn(time_on_init+i);
	delay(100);
}

static void setTimerOnTime(TIMER timer, double time, UNIT_TIME unit, uint32_t init_time)
{
	millis_ExpectAndReturn(init_time);
	setTimer(timer, time, unit);
}

void test_get_wrong_unit(void)
{
	TIMER test = newTimer();
	setTimerOnTime(test, 10, UNKNOWN, time_on_init);
	millis_ExpectAndReturn(200000);
	TEST_ASSERT_EQUAL(UNKNOWN, getTimer(test, UNKNOWN));
}
