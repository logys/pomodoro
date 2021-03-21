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

static void toTogglerLastPause(void);
static void toTogglerLastPlay(void);
static void toTogglerLastPoweroff(void);
static void toTrapLastPause(void);
static void toTrapLastPlay(void);

void setUp(void)
{
	RESET_FAKE(timer_getTime);
	RESET_FAKE(timer_restart);
	selector_init(&button);
}

void tearDown(void)
{
}

void test_first_inToggler_unpushed(void)
{
	button = false;

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(PLAY, action);
}

void test_first_inToggler_pushed(void)
{
	button = true;

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(PAUSE, action);
}

void test_first_trap_pushed(void)
{
	toTrapLastPause();
	button = true;

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(PAUSE, action);
}
void test_fisrt_trap_toggle_pushed_maintained_5seconds(void)
{
	toTrapLastPause();
	timer_getTime_fake.return_val = 5;
	button = true;
	
	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(POWEROFF, action);
}

void test_first_trap_unpush_get_same(void)
{
	toTrapLastPause();
	button = false;
	
	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(PAUSE, action);
}

static void toTrapLastPause(void)
{
	button = true;
	assert(PAUSE == selector_select());
}

void test_toggler_unpushed_last_pause(void)
{
	toTogglerLastPause();
	button = false;

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(PAUSE, action);
}

void test_toggler_pushed_last_pause(void)
{
	toTogglerLastPause();
	button = true;

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(PLAY, action);
}

static void toTogglerLastPause(void)
{
	toTrapLastPause();
	button = false;
	assert(PAUSE == selector_select());
}

void test_trap_pushed_last_play(void)
{
	toTrapLastPlay();
	button = true;

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(PLAY, action);
}

void test_trap_pushed_5_seconds_last_play(void)
{
	toTrapLastPlay();
	button = true;
	timer_getTime_fake.return_val = 5;

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(POWEROFF, action);
}

static void toTrapLastPlay(void)
{
	toTogglerLastPause();
	button = true;
	assert(PLAY == selector_select());
}

void test_trap_unpushed_last_play(void)
{
	toTrapLastPlay();
	button = false;

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(PLAY, action);
}

void test_toggler_unpushed_last_play(void)
{
	toTogglerLastPlay();
	button = false;

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(PLAY, action);
}

void test_toggler_pushed_last_play(void)
{
	toTogglerLastPlay();
	button = true;

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(PAUSE, action);
}

void static toTogglerLastPlay(void)
{
	toTrapLastPlay();
	button = false;
	assert(PLAY == selector_select());
}

void test_toggler_unpushed_last_poweroff(void)
{
	toTogglerLastPoweroff();
	button = false;

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(POWEROFF, action);
}

void test_toggler_pushed_last_poweroff(void)
{
	toTogglerLastPoweroff();
	button = true;

	ACTION action = selector_select();

	TEST_ASSERT_EQUAL(PLAY, action);
}

static void toTogglerLastPoweroff(void)
{
	toTrapLastPlay();
	button = true;
	timer_getTime_fake.return_val = 5;
	assert(POWEROFF == selector_select());
}

void test_reset_timer_unpushed(void)
{
	toTogglerLastPlay();
	button = false;

	selector_select();

	TEST_ASSERT(timer_restart_fake.call_count);
}
