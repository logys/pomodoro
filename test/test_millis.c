#include "unity.h"
#include "../src/millis.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void setUp(void)
{
	millis_init();
}

void tearDown(void)
{
}

void test_select_internal_clock_1Mhz(void)
{
	CLKPR = 0x00;

	millis_init();

	TEST_ASSERT_BITS(0x0F, 0x3, CLKPR);
}

void test_select_clock_whitout_pll(void)
{
	PLLCSR = 0xFF;

	millis_init();

	TEST_ASSERT_BITS(0x04, 0x00, PLLCSR);
}

void test_select_preescaler_4(void)
{
	TCCR1 = 0x0C;

	millis_init();

	TEST_ASSERT_BITS(0x0F, 0x03, TCCR1);
}

void test_compare_register_to_250(void)
{
	OCR1A = 0;

	millis_init();

	TEST_ASSERT_EQUAL(250, OCR1A);
}

void test_enable_global_interrupts(void)
{
	SREG = 0x00;

	millis_init();

	TEST_ASSERT_BITS(0x80, 0x80, SREG);
}

void test_enable_OCA1_interrupts(void)
{
	TIMSK = 0x00;

	millis_init();

	TEST_ASSERT_BITS(0x40, 0x40, TIMSK);
}

void test_time_at_init(void)
{
	TIM1_COMPA_vect();

	uint32_t current_time = millis();
	
	TEST_ASSERT_EQUAL(1, current_time);
}

void test_after_250_interrupts(void)
{
	for(int i = 0; i<250; i++)
		TIM1_COMPA_vect();

	uint32_t current_time = millis();
	
	TEST_ASSERT_EQUAL(251, current_time);
}

void test_reinit_millis(void)
{
	TIM1_COMPA_vect();
	millis_reinit();

	uint32_t current_time = millis();
	
	TEST_ASSERT_EQUAL(0, current_time);
}

void test_unmodified_status_register_on_reinit(void)
{
	SREG = 0xFF;

	millis_reinit();

	TEST_ASSERT_BITS(0XFF, 0xFF, SREG);
}

void test_unmodified_status_register_on_read(void)
{
	SREG = 0x00;

	millis();

	TEST_ASSERT_BITS(0XFF, 0x00, SREG);
}
