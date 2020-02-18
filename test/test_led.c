#include "unity.h"
#include "led.h"
#include "stub_io.h"

void setUp(void)
{
	openLed();
}

void tearDown(void)
{
}

void test_led_poweroff_at_init(void)
{
	DDRB = 0xff;
	PORTB = 0xff;
	openLed();
	TEST_ASSERT_BITS(1, 1, DDRB);
	TEST_ASSERT_BITS(1, 0, PORTB);
}

void test_close_led(void)
{
	DDRB = 0xff;
	PORTB = 0xff;
	closeLed();
	TEST_ASSERT_BITS(1, 0, DDRB);
	TEST_ASSERT_BITS(1, 0, PORTB);
}

void test_toggle(void)
{
	PORTB = 0xff;
	toggleLed();
	TEST_ASSERT_BITS(1, 0, PORTB);
	toggleLed();
	TEST_ASSERT_BITS(1, 1, PORTB);
}
void test_sleep_led(void)
{
	sleepLed();
	TEST_ASSERT_BITS(1, 0, PORTB);
}
