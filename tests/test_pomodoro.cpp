#include <gtest/gtest.h>
#include "button.hpp"
#include "pomodoro.hpp"
#include "tickOneSecond.hpp"

class PomodoroTest : public ::testing::Test {
	protected:
		Pomodoro * pomodoro;
		Button * button;
		TickOneSecond * tickOneSecond;

		virtual void SetUp() override
		{
			pomodoro = new Pomodoro();
			button = new Button(pomodoro);
			tickOneSecond = new TickOneSecond(pomodoro);
		}
		virtual void TearDown() override {
			delete tickOneSecond;
			delete button;
			delete pomodoro;
		}
};

TEST_F(PomodoroTest, should_no_count_because_button_no_pressed)
{
	tickOneSecond->doit();
	tickOneSecond->doit();

	ASSERT_EQ(pomodoro->sessionTime(), 0);
}

TEST_F(PomodoroTest, should_count_because_button_was_pressed)
{
	button->pressed();
	constexpr int ticks = 1000;
	for(int i = 0; i <ticks; i++)
		tickOneSecond->doit();

	ASSERT_EQ(pomodoro->sessionTime(), ticks);
}

TEST_F(PomodoroTest, should_notify_end_of_session)
{
	pomodoro->enable();
	pomodoro->setTime(59);

	tickOneSecond->doit();

	ASSERT_TRUE(buzzer->called());
}
