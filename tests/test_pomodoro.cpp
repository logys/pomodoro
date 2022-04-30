#include <gtest/gtest.h>
#include "pomodoro.hpp"
#include "indicator.hpp"
#include "tickOneSecond.hpp"

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
		TickOneSecond * tickOneSecond;

		virtual void SetUp() override
		{
			buzzer = new BuzzerStub();
			pomodoro = new Pomodoro(buzzer, 1);
			tickOneSecond = new TickOneSecond(pomodoro);
		}
		virtual void TearDown() override 
		{
			delete tickOneSecond;
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

TEST_F(PomodoroTest, should_be_one_second_for_100_calls_of_10ms)
{
	pomodoro->enable();

	for(int i = 0; i<100; i++){
		tickOneSecond->callTick();
	}

	ASSERT_EQ(pomodoro->sessionTime(), 1);
}
