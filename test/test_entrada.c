#include "unity.h"
#include "mock_timer.h"
#include "entrada.h"
#include "stub_io.h"

void setUp(void)
{
	DDRB = 0xff;
	PORTB = 0x00;
	newTimer_ExpectAndReturn(NULL);
	openPush();
	PINB = 0;
}

void tearDown(void)
{
	closePush();
}

void test_open_driver_input_pullUp(void)
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

void test_read_edge(void)
{
	PINB = 0;
	setTimer_Expect(NULL, 50, MILLISECONDS);
	TEST_ASSERT_EQUAL(ON, readPush());
}

void test_mantain_state_in_the_first_50_ms(void)
{
	PINB = 0;
	setTimer_Expect(NULL, 50, MILLISECONDS);
	TEST_ASSERT_EQUAL(ON, readPush());

	PINB = 0xff;
	getTimer_ExpectAndReturn(NULL, MILLISECONDS, 20);
	TEST_ASSERT_EQUAL(ON, readPush());

	PINB = 0;
	getTimer_ExpectAndReturn(NULL, MILLISECONDS, 40);
	TEST_ASSERT_EQUAL(ON, readPush());
}

void test_after_50ms_read_again(void)
{
	PINB = 0;
	setTimer_Expect(NULL, 50, MILLISECONDS);
	TEST_ASSERT_EQUAL(ON, readPush());

	PINB = 0xff;
	getTimer_ExpectAndReturn(NULL, MILLISECONDS, 50);
	TEST_ASSERT_EQUAL(OFF, readPush());

}
