#include "unity.h"

#include "../src/button.h"
#include "../src//gpioHandler.h"
#include <avr/io.h>
#include <stdbool.h>

short button_pin;
short gpio_pin;

void setUp(void)
{
	button_pin = 2;
	gpio_pin = gpio_pinToGpio(button_pin);
	button_init(button_pin);
}

void tearDown(void)
{
}

void test_button_as_input(void)
{
	DDRB = 0xFF;

	button_init(button_pin);

	TEST_ASSERT_BITS(1<<gpio_pin, 0, DDRB);
}

void test_button_whit_pull_up(void)
{
	PORTB = 0x00;

	button_init(button_pin);

	TEST_ASSERT_BITS(1<<gpio_pin, 1<<gpio_pin, PORTB);
}

void test_button_read_pushed(void)
{
	PINB = 0x00;

	bool pushed = button_read();

	TEST_ASSERT(pushed);
}

void test_button_read_unpushed(void)
{
	PINB = 0xFF;

	bool pushed = button_read();

	TEST_ASSERT_FALSE(pushed);
}
