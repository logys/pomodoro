#include "unity.h"
#include "../src/controller.h"
#include "../src/action.h"
#include "fff.h"

DEFINE_FFF_GLOBALS;
FAKE_VALUE_FUNC(ACTION, selector_select);
FAKE_VALUE_FUNC(short, play_do);
FAKE_VALUE_FUNC(short, pause_do);
FAKE_VOID_FUNC(pomodoro_reinit);
FAKE_VOID_FUNC(pause_init);
FAKE_VOID_FUNC(poweroff);
FAKE_VOID_FUNC(play_reinit);
FAKE_VOID_FUNC(pause_reinit);


bool finished;
short progress;

void setUp(void)
{
	RESET_FAKE(selector_select);
	RESET_FAKE(play_do);
	RESET_FAKE(pomodoro_reinit);
	finished = false;
	progress = 0;

	controller_init(&progress, &finished);
}
void tearDown(void)
{
}

void test_first_do_reinitr(void)
{
	finished = true;
	progress = 100;

	controller_do();

	TEST_ASSERT_FALSE(finished);
	TEST_ASSERT_EQUAL(0, progress);

}
void test_finished_on_progress_fullfiled(void)
{
	finished = false;
	selector_select_fake.return_val = PLAY;
	play_do_fake.return_val = 100;

	controller_do();

	TEST_ASSERT(finished);
}

void test_when_progress_less_one_hundred_no_finished(void)
{
	finished = false;
	play_do_fake.return_val = 50;
	selector_select_fake.return_val = PLAY;

	controller_do();

	TEST_ASSERT_FALSE(finished);
}

void test_action_poweroff_finished_true(void)
{
	finished = false;
	play_do_fake.return_val = 50;
	selector_select_fake.return_val = POWEROFF;

	controller_do();

	TEST_ASSERT(finished);
}

void test_on_play_progres_acumulates(void)
{
	int progress_init = progress;
	selector_select_fake.return_val = PLAY;
	play_do_fake.return_val = 10;

	controller_do();

	TEST_ASSERT(progress_init < progress);
}

void test_on_pause_progress_always_eigty_percent(void)
{
	pause_do_fake.return_val = 80;
	selector_select_fake.return_val = PAUSE;

	controller_do();

	TEST_ASSERT_EQUAL(80, progress);
}
