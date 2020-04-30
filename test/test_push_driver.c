#include "unity.h"

#include "push_driver.h"
#include "stub_io.h"

#define PIN PB3

void setUp(void)
{
	DDRB = 0xFF;
	PORTB = 0x00;
	push_init();
}

void tearDown(void)
{
}

void test_open_driver_input_pullUp(void)
{
	TEST_ASSERT_BITS(1<<PIN, 0, DDRB);
	TEST_ASSERT_BITS(1<<PIN, 1<<PIN, PORTB);
}

void test_close_driver(void)
{
	push_close();
	TEST_ASSERT_BITS(1<<PIN, 0, DDRB);
	TEST_ASSERT_BITS(1<<PIN, 0<<PIN, PORTB);
}

void test_push_pressed_return_1_negative_logic(void)
{
	push_set(1);
	TEST_ASSERT_EQUAL(PUSH_ON, push_read());
}

void test_push_no_pressed_return_0_negative_logic(void)
{
	push_set(0);
	TEST_ASSERT_EQUAL(PUSH_OFF, push_read());
}
