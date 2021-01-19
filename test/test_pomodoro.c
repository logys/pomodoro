#include "/home/antonio/.gem/ruby/gems/ceedling-0.30.0/vendor/unity/src/unity.h"
#include "../src/pomodoro.h"
#include "../src/pomodoro_data.h"
#include "../src/pomodoro_sessions.h"
#include "avr/io.h"
#include "../src/session.h"
#include "../src/time.h"

static Pomodoro pomodoro;
void setUp(void)
{	
	pomodoro.session_time = 5;
	pomodoro_init(&pomodoro);
	session_setSessionTime(&pomodoro.session, 5);
}
void tearDown(void)
{
}

//Test update time
void test_time_at_init(void)
{
	time_setCurrent(&pomodoro.time, 0);
	pomodoro_update();
	TEST_ASSERT_EQUAL_FLOAT(0, session_getCurrentTime(&pomodoro.session));
}
void test_time_at_half(void)
{
	time_setCurrent(&pomodoro.time, 2.5*60*1000);
	pomodoro_update();
	TEST_ASSERT_EQUAL_FLOAT(2.5, session_getCurrentTime(&pomodoro.session));
}
void test_add_one_minute(void)
{
	time_setCurrent(&pomodoro.time, 1*60*1000);
	pomodoro_update();
	time_setCurrent(&pomodoro.time, 1*60*1000);
	pomodoro_update();
	TEST_ASSERT_EQUAL_FLOAT(2, session_getCurrentTime(&pomodoro.session));
}

//Test progress
void test_compute_progress_at_init(void)
{
	time_setCurrent(&pomodoro.time, 0);
	pomodoro_update();
	TEST_ASSERT_EQUAL(0, pomodoro.progress);
}
void test_compute_progress_at_half(void)
{
	time_setCurrent(&pomodoro.time, 2.5*60*1000);
	pomodoro_update();
	TEST_ASSERT_EQUAL(50, pomodoro.progress);
}
void test_compute_progress_at_finish(void)
{
	time_setCurrent(&pomodoro.time, 5*60*1000);
	pomodoro_update();
	TEST_ASSERT_EQUAL(100, pomodoro.progress);
}
