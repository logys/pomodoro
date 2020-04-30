#include "unity.h"

#include "action.h"
#include "mock_pomodoro_run.h"
#include "mock_pomodoro_pause.h"
#include "mock_pomodoro_poweroff.h"
void setUp(void)
{
	initPowerOff_Expect();
	initRun_Expect();
	initPause_Expect();
	initAction();
}

void tearDown(void)
{
	destroyPowerOff_Ignore();
	destroyRun_Ignore();
	destroyPause_Ignore();
	destroyAction();
}

void test_init_action_as_poweroff(void)
{
	initPowerOff_Expect();
	initRun_Expect();
	initPause_Expect();

	initAction();
	TEST_ASSERT_EQUAL_PTR(action, pomodoro_off);
}

void test_first_toggle_set_action_to_play(void)
{
	setActionTogglePlayPause();
	TEST_ASSERT_EQUAL_PTR(action, pomodoro_run);
}
void test_doble_toggle_set_to_pause(void)
{
	setActionTogglePlayPause();
	setActionTogglePlayPause();
	TEST_ASSERT_EQUAL_PTR(action, pomodoro_pause);
}
void test_triple_toggle_set_to_run(void)
{
	setActionTogglePlayPause();
	setActionTogglePlayPause();
	setActionTogglePlayPause();
	TEST_ASSERT_EQUAL_PTR(action, pomodoro_run);
}
void test_poweroff(void)
{
	setActionPowerOff();
	TEST_ASSERT_EQUAL_PTR(action, pomodoro_off);
}
void test_destroy(void)
{
	destroyPowerOff_Expect();
	destroyRun_Expect();
	destroyPause_Expect();

	destroyAction();
}
