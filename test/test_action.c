#include "unity.h"

#include "../src/action.h"
#include "fff.h"

DEFINE_FFF_GLOBALS;

FAKE_VOID_FUNC(play_do);
FAKE_VOID_FUNC(pause_do);
FAKE_VOID_FUNC(poweroff_do);

void setUp(void)
{
	RESET_FAKE(play_do);
}

void tearDown(void)
{
}

void test_set_play(void)
{
	action_set_play();

	action_do();

	TEST_ASSERT(play_do_fake.call_count == 1);
}

void test_set_pause(void)
{
	action_set_pause();

	action_do();

	TEST_ASSERT(pause_do_fake.call_count == 1);
}

void test_set_poweroff(void)
{
	action_set_poweroff();

	action_do();

	TEST_ASSERT(poweroff_do_fake.call_count == 1);
}
