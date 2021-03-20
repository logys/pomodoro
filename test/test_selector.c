#include "unity.h"
#include <stdbool.h>
#include <assert.h>
#include "../src/selector.h"
#include "fff.h"
#include <stdint.h>

DEFINE_FFF_GLOBALS;
FAKE_VALUE_FUNC(uint32_t, timer_getTime);
FAKE_VOID_FUNC(timer_create);
FAKE_VOID_FUNC(timer_restart);

int input;
bool button;

static void omitFirstCall(void);
static void toTrap(void);
static void lastReturnWasPAUSE(void);
static void toSecondTogglerLastPlay(void);

void setUp(void)
{
	RESET_FAKE(timer_getTime);
	selector_init(&button);
}

void tearDown(void)
{
}

void test_poweroff_on_create(void)
{
	button = true;

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(POWEROFF, action);
}

void test_toggle_first_time_push_play(void)
{
	omitFirstCall();
	button = true;

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(PLAY, action);
}

static void omitFirstCall(void)
{
	selector_select();
}

void test_toggle_first_unpushed_time(void)
{
	omitFirstCall();
	button = false;

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(POWEROFF, action);
}
void test_trap_toggle_pushed_maintained(void)
{
	toTrap();
	button = true;
	
	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(PLAY, action);
}

static void toTrap(void)
{
	omitFirstCall();
	button = true;
	selector_select();
}

void test_trap_unpush_get_same(void)
{
	toTrap();
	button = false;
	
	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(PLAY, action);
}

void test_trap_5_seconds_return_poweroff(void)
{
	toTrap();
	button = true;
	timer_getTime_fake.return_val = 5;

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(POWEROFF, action);
}

void test_second_toggler_unpushed_get_play(void)
{
	toSecondTogglerLastPlay();
	button = false;

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(PLAY, action);
}

void toSecondTogglerLastPlay(void)
{
	toTrap();
	button = false;
	ACTION action = selector_select();
	assert(action == PLAY);
}

void test_second_toggler_unpushed_get_poweroff(void)
{
	toTrap();
	button = true;
	timer_getTime_fake.return_val = 5;
	ACTION action1 = selector_select();
	assert(action1 == POWEROFF);
	button = false;

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(POWEROFF, action);
}

void test_second_toggler_pushed_get_pause(void)
{
	toSecondTogglerLastPlay();
	button = true;

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(PAUSE, action);
}

void test_second_trap_unpushed_last_pause(void)
{
	toSecondTogglerLastPlay();
	button = true;
	assert(PAUSE == selector_select());
	button = false;

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(PAUSE, action);
}

void test_second_trap_pushed_last_pause(void)
{
	toSecondTogglerLastPlay();
	button = true;
	assert(PAUSE == selector_select());
	button = true;

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(PAUSE, action);
}
