#include "unity.h"
#include "millis.h"
#include <avr/io.h>

void setUp(void)
{
	TCCR1 = 0x7;
	OCR1A = 0;
	TIMSK = 0;
	millis_init();
}

void tearDown(void)
{
	millis_destroy();
}

void test_init_millis_timer1(void)
{
	int preescaler = 0b011;
	int ticks_for_1ms = 240;
	int bitInterruptTimer1Compare = (1<<OCIE1A);

	millis_init();
	TEST_ASSERT_BITS(0x7, preescaler, TCCR1);
	TEST_ASSERT_EQUAL(ticks_for_1ms, OCR1A);
	TEST_ASSERT_BITS(bitInterruptTimer1Compare, bitInterruptTimer1Compare , TIMSK);
}
void test_millis_destroy_no_more_interrupt(void)
{
	int bitInterruptTimer1Compare = (1<<OCIE1A);
	millis_destroy();
	TEST_ASSERT_BITS(bitInterruptTimer1Compare, 0, TIMSK);
}
static void setMillis(uint32_t time)
{
	for(int i = 0; i < time; i++)
		TIM1_COMPA_vect();
}
void test_getValue(void)
{
	int millis_at_start = 0;
	setMillis(millis_at_start);
	TEST_ASSERT_EQUAL(millis_at_start, millis());

	int millis_after_some_time = 60;
	setMillis(millis_after_some_time);
	TEST_ASSERT_EQUAL(millis_after_some_time, millis());
}
void test_millis_init_only_one_time(void)
{
	int millis_after_some_time = 100;
	setMillis(millis_after_some_time);
	TEST_ASSERT_EQUAL(millis_after_some_time, millis());
	millis_init();
	TEST_ASSERT_EQUAL(millis_after_some_time, millis());
}

void test_millis_whitout_init_return_cero(void)
{
	millis_destroy();
	setMillis(10);
	TEST_ASSERT_EQUAL(0, millis());
}
