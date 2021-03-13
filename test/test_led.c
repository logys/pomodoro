#include "unity.h"
#include "../src/led.h"
#include "avr/io.h"

short led_pin;

void setUp(void)
{
	led_pin = 2;
	led_open(led_pin);
}

void tearDown(void)
{
}

void test_led_as_output(void)
{
	led_pin = 2;

	led_open(led_pin);

	TEST_ASSERT_BITS(1<<PB3, 1<<PB3, DDRB);
}

void test_init_poweroff(void)
{
	DDRB = 0xff;
	PORTB = 0xff;
	led_pin = 3;

	led_open(led_pin);

	TEST_ASSERT_BITS(1<<PB4, 0<<PB4, PORTB);
}

void test_led_on(void)
{
	PORTB = 0x00;

	led_on();

	TEST_ASSERT_BITS(1<<PB3, 1<<PB3, PORTB);
}
void test_led_off(void)
{
	PORTB = 0xFF;

	led_off();

	TEST_ASSERT_BITS(1<<PB3, 0, PORTB);
}
