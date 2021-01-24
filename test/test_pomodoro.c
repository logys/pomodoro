#include "/home/antonio/.gem/ruby/gems/ceedling-0.30.0/vendor/unity/src/unity.h"
#include "../src/pomodoro.h"
#include "../src/session.h"
#include "../src/time.h"
#include "../test/spys/millis_spy.h"

#define HALF_TIME_SESSION_MS 2.5*60*1000

static Pomodoro pomodoro;
void setUp(void)
{	
	pomodoro_init(&pomodoro);
	pomodoro.session.session_time = 5;
	millis_init();
}
void tearDown(void)
{
}

//Test progress
void test_compute_progress_at_init(void)
{
	set_millis_spy(0);
	pomodoro_update();
	TEST_ASSERT_EQUAL(0, pomodoro_getProgress(&pomodoro));
}
void test_compute_progress_at_half(void)
{
	set_millis_spy(HALF_TIME_SESSION_MS);
	pomodoro_update();
	TEST_ASSERT_EQUAL(50, pomodoro_getProgress(&pomodoro));
}
void test_compute_progress_at_finish(void)
{
	set_millis_spy(2*HALF_TIME_SESSION_MS);
	pomodoro_update();
	TEST_ASSERT_EQUAL(100, pomodoro_getProgress(&pomodoro));
}
