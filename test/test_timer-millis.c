#include "unity.h"
#include "../src/timer.h"
#include "../src/millis.h"
#include <stdlib.h>
#include "fff.h"
#include <avr/io.h>
#include <avr/interrupt.h>

DEFINE_FFF_GLOBALS;

static CLOCK timer;

void setUp(void)
{
	timer = timer_create();
}

void tearDown(void)
{
}

void test_millis_inited()
{
	TIMSK = 0;

	timer = timer_create();

	TEST_ASSERT_BITS(1<<OCIE1A, 1<<OCIE1A, TIMSK);
}

void test_get_time_after_init(void)
{
	timer = timer_create();

	uint32_t current_time = timer_getTime(&timer, MILLISECONDS);

	TEST_ASSERT_EQUAL(0, current_time);
}

void test_timer_count_after_60ms(void)
{
	timer = timer_create();

	for(int i = 0; i<60; i++){
		TIM1_COMPA_vect();
	}

	uint32_t current_time = timer_getTime(&timer, MILLISECONDS);

	TEST_ASSERT_EQUAL(60, current_time);
}

void test_restart_timer(void)
{
	timer = timer_create();
	for(int i = 0; i<60; i++){
		TIM1_COMPA_vect();
	}
	timer_restart(&timer);

	uint32_t current_time = timer_getTime(&timer, MILLISECONDS);

	TEST_ASSERT_EQUAL_UINT32(0, current_time);
}
