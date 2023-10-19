#include <gtest/gtest.h>
#include "input.h"
#include "pomodoro.h"
#include "button.h"
#include "fff.h"
DEFINE_FFF_GLOBALS;

FAKE_VOID_FUNC(pomodoro_pushed);
FAKE_VALUE_FUNC(bool, button_pushed);

class ButtonTest : public ::testing::Test {
	protected:
		Input input;
		Pomodoro pomodoro;

		virtual void SetUp() override
		{
			input = input_create();
		}
		virtual void TearDown() override
		{
		}
};

TEST_F(ButtonTest, button_No_pressed)
{
	button_pushed_fake.return_val = false;
	pomodoro.button_pressed = true;

	input_do(&input, &pomodoro);

	bool get = pomodoro.button_pressed;
	bool want = false;
	ASSERT_EQ(want, get);
}

TEST_F(ButtonTest, button_pressed)
{
	button_pushed_fake.return_val = true;
	pomodoro.button_pressed = false;

	input_do(&input, &pomodoro);

	bool get = pomodoro.button_pressed;
	bool want = true;
	ASSERT_EQ(want, get);
}


TEST_F(ButtonTest, record_last_push)
{
	button_pushed_fake.return_val = true;
	input.last_pushed = false;

	input_do(&input, &pomodoro);

	bool get = input.last_pushed;
	bool want = true;
	ASSERT_EQ(want, get);
}

TEST_F(ButtonTest, button_pressed_two_times)
{
	button_pushed_fake.return_val = true;
	input.last_pushed = true;

	input_do(&input, &pomodoro);

	bool get = pomodoro.button_pressed;
	bool want = false;
	ASSERT_EQ(want, get);
}

TEST_F(ButtonTest, after_push_set_rebound_time)
{
	button_pushed_fake.return_val = true;
	input.last_pushed = false;
	input.time_ms = 0;

	input_do(&input, &pomodoro);

	uint32_t get = input.time_ms;
	uint32_t want = 50;
	EXPECT_EQ(want, get);
}

TEST_F(ButtonTest, reduce_time_in_each_interaction)
{
	button_pushed_fake.return_val = true;
	input.time_ms = 50;

	input_do(&input, &pomodoro);

	uint32_t get = input.time_ms;
	uint32_t want = 40;
	EXPECT_EQ(want, get);
}

TEST_F(ButtonTest, rebound_time_already_dont_update)
{
	button_pushed_fake.return_val = true;
	input.time_ms = 50;

	input_do(&input, &pomodoro);

	uint32_t get = input.time_ms;
	uint32_t want = 50;
	EXPECT_NE(want, get);
}

TEST_F(ButtonTest, unpushed_in_rebound_time)
{
	button_pushed_fake.return_val = true;
	input.last_pushed = false;
	input.time_ms = 40;

	input_do(&input, &pomodoro);

	bool get = pomodoro.button_pressed;
	bool want = false;
	ASSERT_EQ(want, get);
}

TEST_F(ButtonTest, pushed_after_rebound_time)
{
	button_pushed_fake.return_val = true;
	input.last_pushed = false;
	input.time_ms = 0;

	input_do(&input, &pomodoro);

	bool get = pomodoro.button_pressed;
	bool want = true;
	ASSERT_EQ(want, get);
}

TEST_F(ButtonTest, no_decrease_time_on_edge)
{
	button_pushed_fake.return_val = false;
	input.last_pushed = false;
	input.time_ms = 0;

	input_do(&input, &pomodoro);

	int get = input.time_ms;
	int want = 0;
	EXPECT_EQ(want, get);
}
