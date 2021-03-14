//#ifdef TEST

#include "unity.h"

#include "gpioHandler.h"
#include <avr/io.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_convert_pin_to_gpio(void)
{
	short gpio_pb3 = gpio_pinToGpio(2);
	short gpio_pb4 = gpio_pinToGpio(3);
	short gpio_pb0 = gpio_pinToGpio(5);
	short gpio_pb1 = gpio_pinToGpio(6);
	short gpio_pb2 = gpio_pinToGpio(7);

	TEST_ASSERT_EQUAL(PB3, gpio_pb3);
	TEST_ASSERT_EQUAL(PB4, gpio_pb4);
	TEST_ASSERT_EQUAL(PB0, gpio_pb0);
	TEST_ASSERT_EQUAL(PB1, gpio_pb1);
	TEST_ASSERT_EQUAL(PB2, gpio_pb2);
}

//void test_valid_pin
//#endif // TEST
