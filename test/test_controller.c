#include "unity.h"
#include "../src/controller.h"
#include "spys/selector_spy.h"
#include "spys/play_spy.h"
#include "spys/pause_spy.h"


bool finished;
short progress;
bool button;

void setUp(void)
{
	finished = false;
	progress = 0;
	button = false;

	controller_init(5, &progress, &button, &finished);
}
void tearDown(void)
{
}

void test_finished_on_progress_fullfiled(void)
{
	finished = false;
	selector_set_action_spy(PLAY);
	play_set_progress_spy(100);

	controller_do();

	TEST_ASSERT(finished);
}

void test_when_progress_less_one_hundred_no_finished(void)
{
	finished = false;
	play_set_progress_spy(50);
	selector_set_action_spy(PLAY);

	controller_do();

	TEST_ASSERT_FALSE(finished);
}

void test_on_action_poweroff_finished_true(void)
{
	finished = false;
	play_set_progress_spy(50);
	selector_set_action_spy(POWEROFF);

	controller_do();

	TEST_ASSERT(finished);
}

void test_on_play_progres_acumulates(void)
{
	int progress_init = progress;
	selector_set_action_spy(PLAY);
	play_set_progress_spy(10);

	controller_do();

	TEST_ASSERT(progress_init < progress);
}

void test_on_pause_progress_always_eigty_percent(void)
{
	progress = 0;
	selector_set_action_spy(PAUSE);

	controller_do();

	TEST_ASSERT_EQUAL(80, progress);
}
