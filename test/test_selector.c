#include "unity.h"
#include <stdbool.h>
#include <assert.h>

#include "spys/timer_spy.h"

#include "../src/selector.h"

int input;
bool button;
CLOCK timer_selector;

static void omitPoweroffOfAtInit(void);
static void lastReturnWasPLAY(void);
static void lastReturnWasPAUSE(void);

void setUp(void)
{
	selector_init(&button);
	timer_reset(&timer_selector);
}

void tearDown(void)
{
}

void test_poweroff_on_create(void)
{
	button = false;

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(POWEROFF, action);
}


void test_play_after_poweroff(void)
{
	button = false;
	omitPoweroffOfAtInit();

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(PLAY, action);
}

static void omitPoweroffOfAtInit(void)
{
	selector_select();
}

void test_play_whitout_pushed_from_play(void)
{
	lastReturnWasPLAY();
	button = false;

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(PLAY, action);
}

static void lastReturnWasPLAY(void)
{
	button = true;
	omitPoweroffOfAtInit();
	ACTION action = selector_select();
	assert(PLAY == action);
}

void test_pause_when_pushed_from_play(void)
{
	lastReturnWasPLAY();
	button = true;

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(PAUSE, action);
}

void test_play_when_pushed_from_pause(void)
{
	lastReturnWasPAUSE();
	button = true;

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(PLAY, action);
}

static void lastReturnWasPAUSE(void)
{
	lastReturnWasPLAY();
	button = true;
	assert(PAUSE == selector_select());
}

void test_poweroff_after_five_seconds_pushing(void)
{
	lastReturnWasPLAY();
	button = true;
	timer_setTime_spy(5, SECONDS);

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(POWEROFF, action);
}

void test_before_5_seconds_no_poweroff(void)
{
	lastReturnWasPLAY();
	button = false;
	timer_setTime_spy(4, SECONDS);

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(PLAY, action);
}

void test_poweroff_after_five_seconds_pushing_on_pause(void)
{
	lastReturnWasPAUSE();
	button = true;
	timer_setTime_spy(5, SECONDS);

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(POWEROFF, action);
}
