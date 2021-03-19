#include "unity.h"
#include "../src/controller.h"
#include "fff.h"
#include "../src/action.h"

DEFINE_FFF_GLOBALS;
FAKE_VALUE_FUNC(ACTION, selector_select);
FAKE_VOID_FUNC(play_do);
FAKE_VOID_FUNC(pause_do);
FAKE_VOID_FUNC(pomodoro_reinit);
FAKE_VOID_FUNC(pause_init);


bool finished;
short progress;

void setUp(void)
{
	finished = false;
	progress = 0;

	controller_init(&progress, &finished);
}
void tearDown(void)
{
}

void test_finished_on_progress_fullfiled(void)
{
	finished = false;
	selector_select_fake.return_val = PLAY;
	progress = 100;

	controller_do();

	TEST_ASSERT(finished);
}

void test_when_progress_less_one_hundred_no_finished(void)
{
	finished = false;
	progress = 50;
	selector_select_fake.return_val = PLAY;

	controller_do();

	TEST_ASSERT_FALSE(finished);
}

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
