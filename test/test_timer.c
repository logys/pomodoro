#include "unity.h"
#include "../src/timer.h"
#include <stdlib.h>
#include "fff.h"

DEFINE_FFF_GLOBALS;
FAKE_VALUE_FUNC(uint32_t ,millis)

static CLOCK timer;

void setUp(void)
{
	timer = timer_create();
}

void tearDown(void)
{
}

/*
void test_get_time_after_init(void)
{
	TEST_ASSERT_EQUAL(0, timer_getMilliseconds(tim));
}
void test_timer_count_after_start(void)
{
	timer_start(tim);
	int milliseconds_from_start_timer = 13;
	addMillis(milliseconds_from_start_timer);
	TEST_ASSERT_EQUAL(milliseconds_from_start_timer, timer_getMilliseconds(tim));
}
void test_start_timer_after_millis_already_is_counting(void)
{
	addMillis(500);
	timer_start(tim);
	addMillis(10);
	TEST_ASSERT_EQUAL(10, timer_getMilliseconds(tim));
}
void test_second_start_no_effect(void)
{
	addMillis(4324);
	timer_start(tim);
	addMillis(10);
	timer_start(tim);
	TEST_ASSERT_EQUAL(10, timer_getMilliseconds(tim));
}
void test_reinit_timer(void)
{
	timer_start(tim);
	addMillis(10);
	timer_reinit(tim);
	TEST_ASSERT_EQUAL(0, timer_getMilliseconds(tim));
}
void test_reinit_when_is_paused(void)
{
	addMillis(132);
	timer_start(tim);
	addMillis(10);
	timer_pause(tim);
	addMillis(12313);
	TEST_ASSERT_EQUAL(10, timer_getMilliseconds(tim));
}

void test_on_pause_get_same_time(void)
{
	timer_start(tim);
	addMillis(10);
	timer_pause(tim);
	addMillis(100);
	addMillis(34);
	addMillis(4);
	TEST_ASSERT_EQUAL(10, timer_getMilliseconds(tim));
}

void test_pause_millis_already_counting(void)
{
	addMillis(10);
	timer_start(tim);
	addMillis(10);
	timer_pause(tim);
	TEST_ASSERT_EQUAL(10, timer_getMilliseconds(tim));
}
void test_many_pauses_always_return_same(void)
{
	timer_start(tim);
	addMillis(100);
	timer_pause(tim);
	timer_pause(tim);
	addMillis(1223);
	timer_pause(tim);
	TEST_ASSERT_EQUAL(100, timer_getMilliseconds(tim));
}
void test_resume_timer(void)
{
	addMillis(2313);
	timer_start(tim);
	addMillis(5);
	timer_pause(tim);
	addMillis(2314);
	timer_resume(tim);
	addMillis(5);
	TEST_ASSERT_EQUAL(10, timer_getMilliseconds(tim));
}
void test_resume_no_started(void)
{
	addMillis(463);
	timer_resume(tim);
	addMillis(213);
	TEST_ASSERT_EQUAL(0, timer_getMilliseconds(tim));
}*/
