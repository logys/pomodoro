#include <gtest/gtest.h>
#include "pomodoro.hpp"
#include "hal/hal.h"
#include "fff.h"
#include "tasks/rebound.hpp"

DEFINE_FFF_GLOBALS;
FAKE_VOID_FUNC(standBy);
FAKE_VALUE_FUNC(bool, button_read);

class PomodoroTest : public ::testing::Test {
	protected:
		Pom::Pomodoro * pomodoro;
		Reb::Rebound * rebound;

		virtual void SetUp() override
		{
			pomodoro = new Pom::Pomodoro(1);
			rebound = new Reb::Rebound(pomodoro);
		}
		virtual void TearDown() override 
		{
			delete pomodoro;
			delete rebound;
		}
};

TEST_F(PomodoroTest, should_init_in_standBy)
{
	pomodoro->doIt();

	ASSERT_EQ(standBy_fake.call_count,  1);
}

TEST_F(PomodoroTest, should_init_with_cero_seconds)
{
	pomodoro->doIt();

	ASSERT_EQ(pomodoro->currentTime(), 0);
}

TEST_F(PomodoroTest, should_init_in_poweroff_state)
{
	pomodoro->doIt();
	Pom::State get = pomodoro->currentState();
	Pom::State want = Pom::State::POWEROFF;

	ASSERT_EQ(get, want);
}


TEST_F(PomodoroTest, when_button_is_pressed_pomodoro_change_to_play)
{
	button_read_fake.return_val = true;

	rebound->doIt();
	pomodoro->doIt();
	Pom::State get = pomodoro->currentState();
	Pom::State want = Pom::State::PLAY;

	ASSERT_EQ(get, want);
}
