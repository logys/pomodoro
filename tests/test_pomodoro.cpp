#include <gtest/gtest.h>
#include "pomodoro.hpp"
#include "tickOneSecond.hpp"

class BspStub : public Hal{
	public:
		bool standByCalled(){return caled_;}
		void standBy() override {caled_ = true;}
		bool buzzingCalled(){return buzzing_;}
		void buzzing() override { buzzing_ = true; }
	private:
		bool caled_ = false;
		bool buzzing_ = false;
};

class PomodoroTest : public ::testing::Test {
	protected:
		Pomodoro * pomodoro;
		TickOneSecond * tickOneSecond;
		BspStub * bsp;

		virtual void SetUp() override
		{
			bsp = new BspStub();
			pomodoro = new Pomodoro(bsp, 1);
			tickOneSecond = new TickOneSecond(pomodoro);
		}
		virtual void TearDown() override 
		{
			delete tickOneSecond;
			delete pomodoro;
			delete bsp;
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

	ASSERT_TRUE(bsp->buzzingCalled());
}

TEST_F(PomodoroTest, should_be_one_second_for_100_calls_of_10ms)
{
	pomodoro->enable();

	for(int i = 0; i<100; i++){
		tickOneSecond->callTick();
	}

	ASSERT_EQ(pomodoro->sessionTime(), 1);
}

TEST_F(PomodoroTest, should_call_standby)
{
	pomodoro->enable();
	pomodoro->setTime(59);

	pomodoro->add1Second();

	ASSERT_TRUE(bsp->standByCalled());
}
