#include "unity.h"

#include "../src/button.h"
#include <avr/io.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_createButtonInputPin(void)
{
	DDRB = 0xFF;
	short pin = 2;

	button_create(pin);

	//PB3 correspond to pin 1 in data sheet
	TEST_ASSERT_BITS(1<<PB3, 0<<PB3, DDRB);
}

void test_createButtonPullUp(void)
{
	PORTB = 0x00;
	short pin = 2;

	button_create(pin);

	TEST_ASSERT_BITS(1<<3, 1<<3, PORTB);
}

void test_readPinFromButton_noPushed(void)
{
	PINB = 1<<PB3;
	short pin = 2;
	Button button = button_create(pin);

	TEST_ASSERT_EQUAL(OFF, button_read(&button));
}

void test_readPinFromButton_Pushed(void)
{
	PINB = 0;
	short pin = 2;
	Button button = button_create(pin);

	TEST_ASSERT_EQUAL(ON, button_read(&button));
}
