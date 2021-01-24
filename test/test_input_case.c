#include "/home/antonio/.gem/ruby/gems/ceedling-0.30.0/vendor/unity/src/unity.c"
#include "../src/input.h"
#include "../src/pomodoro.h"
#include "../test/spys/spy_button.h"
#include "spys/spy_button.h"
#include "spys/millis_spy.h"
#define PIN_BUTTON 2
static Pomodoro pomodoro ={0};
static Button button;
void setUp(void)
{
	button_create(&button, PIN_BUTTON);
	input_init(&button, &pomodoro);
}
void tearDown(void)
{
}/*
void test_button_unpressed(void)
{
	button_set_input_spy(0);
	input_update();
	TEST_ASSERT_EQUAL(INPUT_NOCHANGE, pomodoro.input);
}
void test_button_pressed(void)
{
	button_set_input_spy(1);
	input_update();
	TEST_ASSERT_EQUAL(INPUT_TOGGLE, pomodoro.input);
}*/
