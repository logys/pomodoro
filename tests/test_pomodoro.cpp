#include <gtest/gtest.h>
#include "pomodoro.hpp"
#include "hal/hal.h"
#include "fff.h"
#include "tasks/rebound.hpp"

DEFINE_FFF_GLOBALS;
FAKE_VOID_FUNC(standBy);
FAKE_VALUE_FUNC(bool, button_read);
FAKE_VOID_FUNC(buzzer_on);

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

	int get = standBy_fake.call_count;
	int want = 1;
	ASSERT_EQ(get, want);
}

TEST_F(PomodoroTest, should_init_with_cero_seconds)
{
	pomodoro->doIt();

	int get = pomodoro->currentTime();
	int want = 0;
	ASSERT_EQ(get, want);
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

TEST_F(PomodoroTest, when_pomodoro_is_on_play_if_there_is_a_tick_add_10ms)
{
	pomodoro->setState(Pom::State::PLAY);

	for(int i = 0; i<10; i++)
	{
		pomodoro->doIt();
	}

	int get = pomodoro->currentTime();
	int want = 100;
	ASSERT_EQ(get, want);
}


TEST_F(PomodoroTest, when_pomodoro_reach_time_should_call_buzzing_routine)
{
	int get = buzzer_on_fake.call_count;
	int want = 1;
	ASSERT_EQ(get, want);
}
