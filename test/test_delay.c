#include "unity.h"
#include "delay.h"
#include "stub_io.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_init_millis(void)
{
	uint8_t preescaler = 0b11;
	TCCR1 = 0;
	initTimer1Millis();
	TEST_ASSERT_BITS(0x3, preescaler, TCCR1);
}

void test_set_compare_vaule(void)
{
	uint8_t compare_value = 240;
	OCR1A = 0;
	initTimer1Millis();
	TEST_ASSERT_EQUAL(compare_value, OCR1A);

}

void test_interrupt_bit_enable(void)
{
	uint8_t bit_interruptor = 0b01000000;
	TIMSK = 0;
	initTimer1Millis();
	TEST_ASSERT_BITS(0x40, bit_interruptor, TIMSK);
}
