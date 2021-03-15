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

void test_get_time_after_init(void)
{
	millis_fake.return_val = 0;

	uint32_t current_time = timer_getTime(&timer, MILLISECONDS);

	TEST_ASSERT_EQUAL(0, current_time);
}

void test_timer_count_after_60ms(void)
{
	millis_fake.return_val = 60;

	uint32_t current_time = timer_getTime(&timer, MILLISECONDS);

	TEST_ASSERT_EQUAL(60, current_time);
}

void test_restart_timer(void)
{
	millis_fake.return_val = 60;
	timer_restart(&timer);

	uint32_t current_time = timer_getTime(&timer, MILLISECONDS);

	TEST_ASSERT_EQUAL_UINT32(0, current_time);
}
