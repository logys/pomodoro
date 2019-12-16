#include "unity.h"
#include "handleLed.h"
#include "mock_timer.h"
#include "mock_led.h"
#include <stdbool.h>

void setUp(void)
{
	initTimer_Expect();
	openLed_Expect();
	newTimer_ExpectAndReturn(NULL);
	initHandleLed();
}

void tearDown(void)
{
	closeLed_Ignore();
	destroyTimer_Ignore();
	destroyHandleLed();
}

static void getTimeFromInit(double time)
{
	enableTimer_Expect(NULL);
	getTimer_ExpectAndReturn(NULL, MILLISECONDS, time);
}
static void assertToggleReached(void)
{
	reinitTimer_Expect(NULL);
	toggleLed_Expect();
}
void test_toggle_reached_500ms_on_zero_work_cicle(void)
{
	getTimeFromInit(500);
	assertToggleReached();
	TEST_ASSERT_EQUAL(TOGGLING, updateLed(0));
}

void test_unreached_toggle_500ms(void)
{
	getTimeFromInit(100);
	TEST_ASSERT_EQUAL(TOGGLING, updateLed(0));
}

void test_toggle_8ms_on_100_work_cicle(void)
{
	getTimeFromInit(8);
	assertToggleReached();
	TEST_ASSERT_EQUAL(TOGGLING, updateLed(100));
}

void test_reinitTimer_on_toggling(void)
{
	getTimeFromInit(500);
	assertToggleReached();
	TEST_ASSERT_EQUAL(TOGGLING, updateLed(0));
}

void test_first_toggle_reached_second_no_reached(void)
{
	getTimeFromInit(500);
	assertToggleReached();
	TEST_ASSERT_EQUAL(TOGGLING, updateLed(0));

	getTimer_ExpectAndReturn(NULL, MILLISECONDS, 400);
	TEST_ASSERT_EQUAL(TOGGLING, updateLed(0));
}

void test_boundes_low_work_cycle(void)
{
	getTimeFromInit(500);
	assertToggleReached();
	TEST_ASSERT_EQUAL(TOGGLING, updateLed(-10));
}

void test_boundes_high_work_cycle(void)
{
	getTimeFromInit(8);
	assertToggleReached();
	TEST_ASSERT_EQUAL(TOGGLING, updateLed(200));
}

void test_only_one_write_on_cycle(void)
{
	getTimeFromInit(500);
	assertToggleReached();
	TEST_ASSERT_EQUAL(TOGGLING, updateLed(0));

	getTimer_ExpectAndReturn(NULL, MILLISECONDS, 400);
	TEST_ASSERT_EQUAL(TOGGLING, updateLed(100));
}

void test_enable_write_after_two_toggles(void)
{
	getTimeFromInit(500);
	assertToggleReached();
	TEST_ASSERT_EQUAL(TOGGLING, updateLed(0));

	getTimer_ExpectAndReturn(NULL, MILLISECONDS, 500);
	assertToggleReached();
	TEST_ASSERT_EQUAL(READY, updateLed(0));

	getTimeFromInit(8);
	assertToggleReached();
	TEST_ASSERT_EQUAL(TOGGLING, updateLed(100));
}
