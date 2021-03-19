#include "unity.h"
#include "../src/controller.h"
#include "../src/selector.h"
#include "fff.h"
#include "../src/action.h"
#include <stdint.h>

DEFINE_FFF_GLOBALS;
FAKE_VOID_FUNC(play_do);
FAKE_VOID_FUNC(pause_do);
FAKE_VOID_FUNC(timer_create);
FAKE_VOID_FUNC(timer_restart);
FAKE_VALUE_FUNC(uint32_t, timer_getTime);
FAKE_VOID_FUNC(pomodoro_reinit);
FAKE_VOID_FUNC(pause_init);

bool finished;
short progress;
bool button;

void setUp(void)
{
	RESET_FAKE(play_do);
	RESET_FAKE(pause_do);

	finished = false;
	progress = 0;
	button = false;

	controller_init(&progress, &finished);
	selector_init(&button);
}
void tearDown(void)
{
}

void test_finished_on_progress_fullfiled(void)
{
	finished = false;
	progress = 100;
	button = true;

	controller_do();

	TEST_ASSERT(finished);
}

void test_when_progress_less_one_hundred_no_finished(void)
{
	selector_select();
	finished = false;
	button = false;

	controller_do();

	TEST_ASSERT_FALSE(finished);
	TEST_ASSERT(play_do_fake.call_count);
}

/*
void test_on_action_poweroff_finished_true(void)
{
	finished = false;
	progress = 50;
	selector_select_fake.return_val = POWEROFF;

	controller_do();

	TEST_ASSERT(finished);
}

void test_on_play_progres_acumulates(void)
{
	int progress_init = progress;
	selector_select_fake.return_val = PLAY;
	progress = 10;

	controller_do();

	TEST_ASSERT(progress_init < progress);
}

void test_on_pause_progress_always_eigty_percent(void)
{
	selector_select_fake.return_val = PAUSE;

	controller_do();

	TEST_ASSERT(pause_do_fake.call_count);
}
*/
