#include "unity.h"
#include "handleLed.h"
#include "timer.h"
#include "led.h"
#include <stdbool.h>
#include "stub_io.h"
#include "stub_interrupt.h"
#include "millis.h"

void setUp(void)
{
	handleLed_create();
}

void tearDown(void)
{
	handleLed_destroy();
}

void test_unreached_toggle_500ms(void)
{
	handleLed_update(0);
	addMillis(300);
	handleLed_update(0);
	TEST_ASSERT_BITS(1<<PB0, 1<<PB0, PORTB);
}
void test_toggle_reached_500ms_on_zero_work_cicle(void)
{
	handleLed_update(0);
	addMillis(500);
	handleLed_update(0);
	TEST_ASSERT_BITS(1<<PB0, 0<<PB0, PORTB);
}
void test_unnreached_toggle_16ms_on_100_work_cicle(void)
{
	handleLed_update(100);
	addMillis(7);
	handleLed_update(100);
	TEST_ASSERT_BITS(1<<PB0, 1<<PB0, PORTB);
}
void test_reached_toggle_16ms_on_100_work_cicle(void)
{
	handleLed_update(100);
	addMillis(9);
	handleLed_update(100);
	TEST_ASSERT_BITS(1<<PB0, 0<<PB0, PORTB);
}
void test_reched_two_toggles(void)
{
	handleLed_update(0);
	addMillis(500);
	handleLed_update(0);
	addMillis(500);
	handleLed_update(0);
	addMillis(50);
	handleLed_update(0);
	TEST_ASSERT_BITS(1<<PB0, 1<<PB0, PORTB);
}
