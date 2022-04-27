#include <gtest/gtest.h>
#include "pomodoro.hpp"
#include "indicator.hpp"

class BuzzerStub : public Indicator{
	public:
		bool called(){return caled_;}
		void doit() override {caled_ = true;}
	private:
		bool caled_ = false;
};

class PomodoroTest : public ::testing::Test {
	protected:
		Pomodoro * pomodoro;
		BuzzerStub * buzzer;

		virtual void SetUp() override
		{
			buzzer = new BuzzerStub();
			pomodoro = new Pomodoro(buzzer, 1);
		}
		virtual void TearDown() override 
		{
			delete pomodoro;
			delete buzzer;
		}
};

TEST_F(PomodoroTest, should_no_count_because_button_no_pressed)
{
	pomodoro->add1Second();
	pomodoro->add1Second();

	ASSERT_EQ(pomodoro->sessionTime(), 0);
}

TEST_F(PomodoroTest, should_count_because_button_was_pressed)
{
	pomodoro->enable();

	constexpr int ticks = 1000;
	for(int i = 0; i <ticks; i++)
		pomodoro->add1Second();

	ASSERT_EQ(pomodoro->sessionTime(), ticks);
}

TEST_F(PomodoroTest, should_notify_end_of_session)
{
	pomodoro->enable();
	pomodoro->setTime(59);

	pomodoro->add1Second();

	ASSERT_TRUE(buzzer->called());
}
