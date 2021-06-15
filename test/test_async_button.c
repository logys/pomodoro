#include "unity.h"

#include "../src/async_button.h"
#include "fff.h"


DEFINE_FFF_GLOBALS;
FAKE_VOID_FUNC(action_set_play);
FAKE_VOID_FUNC(action_set_pause);
FAKE_VOID_FUNC(action_set_poweroff);

static void go_to_pause_state(void);
static void go_to_play_state(void);
static void go_to_poweroff_state(void);

void setUp(void)
{
}

void tearDown(void)
{
}

void test_if_power_of_at_init_play_action(void)
{
	go_to_poweroff_state();

	async_button_determine_action(0);

	TEST_ASSERT(action_set_play_fake.call_count == 1);
}

static void go_to_poweroff_state(void)
{
	async_button_determine_action(2);
	RESET_FAKE(action_set_poweroff);
}

void test_toggle_if_time_is_less_from_2_sec(void)
{
	go_to_play_state();

	async_button_determine_action(0);

	TEST_ASSERT(action_set_pause_fake.call_count == 1);
}

static void go_to_play_state(void)
{
	async_button_determine_action(0);
}

void test_toggle_from_pause(void)
{
	go_to_pause_state();

	async_button_determine_action(0);

	TEST_ASSERT(action_set_play_fake.call_count == 1);
}

static void go_to_pause_state(void)
{
	async_button_determine_action(0);
	async_button_determine_action(0);
	RESET_FAKE(action_set_play);
}

void test_if_2_sec_was_elapsed_poweroff_action(void)
{
	go_to_play_state();

	async_button_determine_action(2);

	TEST_ASSERT(action_set_poweroff_fake.call_count == 1);
}
