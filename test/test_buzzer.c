#include "unity.h"
#include "../src/buzzer.h"
#include <avr/io.h>

short pin = 2;

void setUp(void)
{
	buzzer_open(pin);
}

void tearDown(void)
{
}

void test_buzzer_off(void)
{
	PORTB = 0xFF;
	
	buzzer_off();

	TEST_ASSERT_BITS(1<<PB3, 0, PORTB);
}

void test_buzzer_on(void)
{
	PORTB = 0x00;
	
	buzzer_on();

	TEST_ASSERT_BITS(1<<PB3, 1<<PB3, PORTB);
}
