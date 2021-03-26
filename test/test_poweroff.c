//#ifdef TEST

#include "unity.h"

#include "../src/poweroff.h"
#include "fff.h"
#include <stdbool.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <avr/io.h>

DEFINE_FFF_GLOBALS;
FAKE_VOID_FUNC(set_sleep_mode, short);
FAKE_VOID_FUNC(sleep_mode);
FAKE_VOID_FUNC(led_off);
FAKE_VOID_FUNC(buzzer_off);
FAKE_VOID_FUNC(sei);

bool finished;

void setUp(void)
{
	finished = true;
	poweroff_init(&finished);
	RESET_FAKE(sleep_mode);
}

void tearDown(void)
{
}

void test_set_sleep_to_powerdown(void)
{
	finished = true;

	poweroff();

	TEST_ASSERT_EQUAL(SLEEP_MODE_PWR_DOWN, set_sleep_mode_fake.arg0_val);
}

void test_enable_global_interrupt(void)
{
	finished = true;

	poweroff();

	TEST_ASSERT(sei_fake.call_count);
}

void test_enable_pcint4(void)
{
	finished = true;
	PCMSK = 0x00;

	poweroff();

	TEST_ASSERT_BITS(1<<PCINT4, 1<<PCINT4, PCMSK);
}

void test_enable_PCINT(void)
{
	finished = true;
	GIMSK = 0x00;

	poweroff();

	TEST_ASSERT_BITS(1<<PCIE, 1<<PCIE, GIMSK);
}

void test_call_sleep(void)
{
	finished = true;

	poweroff();

	TEST_ASSERT(sleep_mode_fake.call_count);
}

void test_disable_int0_interrupt(void)
{
	finished = true;

	poweroff();
	PCINT0_vect();

	TEST_ASSERT_BITS(0x40, 0x00, GIMSK);
}

void test_finished_false(void)
{
	finished = false;

	poweroff();

	TEST_ASSERT_FALSE(sleep_mode_fake.call_count);
}

//#endif // TEST
