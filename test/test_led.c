#include "/home/antonio/.gem/ruby/gems/ceedling-0.30.0/vendor/unity/src/unity.h"
#include "../src/led.h"
#include "avr/io.h"
#define PIN_LED 1
Led led;
void setUp(void)
{
	led_create(&led, PIN_LED);
	DDRB = 0xff;
	PORTB = 0xff;
	led_create(&led, PIN_LED);
	led_open();
}

void tearDown(void)
{
	led_close();
}
void test_led_poweroff_at_init(void)
{
	TEST_ASSERT_BITS(1<<PIN_LED, 1<<PIN_LED, DDRB);
	TEST_ASSERT_BITS(1<<PIN_LED, 0, PORTB);
}
void test_close_led(void)
{
	DDRB = 0xff;
	PORTB = 0xff;
	led_close();
	TEST_ASSERT_BITS(1, 0, DDRB);
	TEST_ASSERT_BITS(1, 0, PORTB);
}
void test_toggle(void)
{
	PORTB = 0xff;
	toggleLed(&led);
	TEST_ASSERT_BITS(1<<PIN_LED, 0, PORTB);
	toggleLed(&led);
	TEST_ASSERT_BITS(1<<PIN_LED, 1<<PIN_LED, PORTB);
}
void test_on(void)
{
	PORTB = 0x00;
	led_on();
	TEST_ASSERT_BITS(1, 1, PORTB);
}
void test_off(void)
{
	PORTB = 255;
	led_off();
	TEST_ASSERT_BITS(1, 0, PORTB);
}
