#include "unity.h"
#include "mock_timer.h"
#include "entrada.h"
#include "stub_io.h"

void setUp(void)
{
	openPush();
}

void tearDown(void)
{
}

void test_open_driver(void)
{
	TEST_ASSERT_BITS(1<<PB3, 0, DDRB);
	TEST_ASSERT_BITS(1<<PB3, 1<<PB3, PORTB);
}

void test_close_driver(void)
{
	closePush();
	TEST_ASSERT_BITS(1<<PB3, 0, DDRB);
	TEST_ASSERT_BITS(1<<PB3, 0<<PB3, PORTB);
}

void test_read(void)
{
	PINB = 0;
	TEST_ASSERT_EQUAL(ON, readPush());
	PINB = 0xff;
	TEST_ASSERT_EQUAL(OFF, readPush());
}
