#include "unity.h"
#include "spys/timer_spy.h"

#include "../src/selector.h"

int input;
CLOCK timer_selector;

void setUp(void)
{
	selector_init(&timer_selector);
	timer_setTime_spy(0, SECONDS);
}

void tearDown(void)
{
}

void test_select_action_cero_input_get_play(void)
{
	input = 0;
	TEST_ASSERT_EQUAL(PLAY, selector_selectActionFromInput(input));
}

void test_select_action_one_input_get_pause(void)
{
	input = 1;
	TEST_ASSERT_EQUAL(PAUSE, selector_selectActionFromInput(input));
}

void test_after_pause_cero_input_get_pause(void)
{
	input = 1;
	selector_selectActionFromInput(input);
	input = 0;
	TEST_ASSERT_EQUAL(PAUSE, selector_selectActionFromInput(input));
}

void test_after_pause_one_input_get_play(void)
{
	input = 1;
	selector_selectActionFromInput(input);
	input = 0;
	selector_selectActionFromInput(input);
	input = 1;
	TEST_ASSERT_EQUAL(PLAY, selector_selectActionFromInput(input));
}

void test_toggle_only_on_edge(void)
{
	input = 1;
	timer_addTime_spy(1, SECONDS);
	selector_selectActionFromInput(input);
	timer_addTime_spy(1, SECONDS);
	TEST_ASSERT_EQUAL(PAUSE, selector_selectActionFromInput(input));
}

void test_select_action_after_five_seconds_get_poweroff(void)
{
	timer_setTime_spy(0, SECONDS);
	input = 1;
	selector_selectActionFromInput(input);
	timer_setTime_spy(5, SECONDS);
	TEST_ASSERT_EQUAL(POWEROFF, selector_selectActionFromInput(input));
}

void test_no_poweroff_before_5_seconds(void)
{
	input = 1;
	timer_setTime_spy(2.5, SECONDS);
	TEST_ASSERT_EQUAL(PAUSE, selector_selectActionFromInput(input));
}

void test_five_seconds_no_reached_reset_time(void)
{
	input = 1;
	timer_addTime_spy(2.5, SECONDS);
	selector_selectActionFromInput(input);
	input = 0;
	selector_selectActionFromInput(input);
	input = 1;
	timer_addTime_spy(4, SECONDS);
	TEST_ASSERT_EQUAL(PLAY, selector_selectActionFromInput(input));
}
