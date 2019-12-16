#include "unity.h"
#include "timer.h"
#include "mock_delay.h"

static void setTimerOnTime(TIMER, double time, UNIT_TIME unit, uint32_t init_time);
void setUp(void)
{
	initTimer1Millis_Expect();
	initTimer();
}

void tearDown(void)
{
}


int time_on_init = 1000;
int time_elapsed = 0;

void test_get_timer_unknown_whitout_set(void)
{
	TIMER test = newTimer();
	

	millis_ExpectAndReturn(time_on_init);
	TEST_ASSERT_EQUAL(-1, getTimer(test, MILLISECONDS));

}
void test_get_timer_milliseconds(void)
{
	TIMER test = newTimer();
	millis_ExpectAndReturn(time_on_init);
	int session_time_milliseconds = 2000;
	enableTimer(test);

	int milliseconds_elapsed = 1000;
	int milliseconds_from_init = milliseconds_elapsed + time_on_init;
	millis_ExpectAndReturn(milliseconds_from_init);
	TEST_ASSERT_EQUAL(milliseconds_elapsed, getTimer(test, MILLISECONDS));
}

void test_get_timer_seconds(void)
{
	TIMER test = newTimer();
	millis_ExpectAndReturn(time_on_init);
	enableTimer(test);

	int seconds_elapsed = 5;
	int milliseconds_from_init = seconds_elapsed*1000 + time_on_init;
	millis_ExpectAndReturn(milliseconds_from_init);
	TEST_ASSERT_FLOAT_WITHIN(0.00001, seconds_elapsed, getTimer(test, SECONDS));
}

void test_get_timer_minutes(void)
{
	TIMER test = newTimer();
	millis_ExpectAndReturn(time_on_init);
	enableTimer(test);

	int minutes_elapsed = 7;
	int milliseconds_from_init = minutes_elapsed*1000*60 + time_on_init;
	millis_ExpectAndReturn(milliseconds_from_init);
	TEST_ASSERT_FLOAT_WITHIN(0.00001, minutes_elapsed, getTimer(test, MINUTES));
}

void test_reinit_timer(void)
{
	TIMER test = newTimer();
	millis_ExpectAndReturn(time_on_init);
	enableTimer(test);

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
	enableTimer(timer);
}

void test_get_wrong_unit(void)
{
	TIMER test = newTimer();
	setTimerOnTime(test, 10, UNKNOWN, time_on_init);
	millis_ExpectAndReturn(200000);
	TEST_ASSERT_EQUAL(UNKNOWN, getTimer(test, UNKNOWN));
}
