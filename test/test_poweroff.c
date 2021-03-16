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
FAKE_VOID_FUNC(pomodoro_reinit);

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

void test_led_off(void)
{
	finished = true;

	poweroff();

	TEST_ASSERT(led_off_fake.call_count);
}

void test_buzzer_off(void)
{
	finished = true;

	poweroff();

	TEST_ASSERT(buzzer_off_fake.call_count);
}

void test_enable_global_interrupt(void)
{
	finished = true;

	poweroff();

	TEST_ASSERT(sei_fake.call_count);
}

void test_configure_int0_to_low_level(void)
{
	finished = true;
	MCUCR = 0xFF;

	poweroff();

	TEST_ASSERT_BITS(0x03, 0x00, MCUCR);
}

void test_enable_int0(void)
{
	finished = true;
	GIMSK = 0x00;

	poweroff();

	TEST_ASSERT_BITS(0x40, 0x40, GIMSK);
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
	INT0_vect();

	TEST_ASSERT_BITS(0x40, 0x00, GIMSK);
}

void test_reset_pomodoro(void)
{
	finished = true;

	poweroff();
	INT0_vect();

	TEST_ASSERT(pomodoro_reinit_fake.call_count);
}

void test_finished_false(void)
{
	finished = false;

	poweroff();

	TEST_ASSERT_FALSE(sleep_mode_fake.call_count);
}

//#endif // TEST