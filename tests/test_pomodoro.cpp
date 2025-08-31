#include <gtest/gtest.h>
#include "pomodoro.h"
#include "fff.h"
#include "led.h"
#include "buzzer.h"
#include "powermode.h"
DEFINE_FFF_GLOBALS;

FAKE_VOID_FUNC(powermode_standBy);
FAKE_VOID_FUNC(buzzer_buzzing);
FAKE_VOID_FUNC(led_blink_slow);
FAKE_VOID_FUNC(led_blink);
FAKE_VALUE_FUNC(bool, button_pushed);

class PomodoroTest : public ::testing::Test {
	protected:
		Pomodoro pomodoro;

		virtual void SetUp() override
		{
			uint32_t session_time = 1;
			pomodoro = pomodoro_create(session_time);
			RESET_FAKE(led_blink_slow);
		}
		virtual void TearDown() override
		{
		}
};

TEST_F(PomodoroTest, increase_time)
{
	pomodoro.state = PLAY;
	pomodoro.play_time = 0;

	pomodoro_doIt(&pomodoro);

	int get = pomodoro.play_time;
	int want = 10;
	EXPECT_EQ(want, get);
}

TEST_F(PomodoroTest, button_pushed)
{
	pomodoro.state = PLAY;
	pomodoro.button_pressed = true;

	pomodoro_doIt(&pomodoro);

	int get = pomodoro.state;
	int want = PAUSE;
	ASSERT_EQ(want, get);
}

TEST_F(PomodoroTest, session_time_ms)
{
	uint32_t session_time = 1;

	pomodoro = pomodoro_create(session_time);

	int get = pomodoro.session_time;
	int want = session_time*1000*60;
	EXPECT_EQ(want, get);
}

TEST_F(PomodoroTest, blink_slow_when_pause)
{
	pomodoro.state = PLAY;
	pomodoro.button_pressed = true;

	pomodoro_doIt(&pomodoro);

	int get = led_blink_slow_fake.call_count;
	int want = 1;
	ASSERT_EQ(want, get);
}

