#include <gtest/gtest.h>
#include "pomodoro.hpp"
#include "controller.hpp"
#include "tickOneSecond.hpp"
#include "circular_buffer.hpp"

class BspStub : public Hal{
	public:
		bool standByCalled(){return caled_;}
		void standBy() override {caled_ = true;}
		bool buzzingCalled(){return buzzing_;}
		void buzzing() override { buzzing_ = true;}
		void led_play() override { led_ = true;}
		bool led_called(){return led_;}
		void idle() override { idle_ = true;}
		bool idle_called(){return idle_;}
	private:
		bool caled_ = false;
		bool buzzing_ = false;
		bool led_ = false;
		bool idle_ = false;
};

class PomodoroTest : public ::testing::Test {
	protected:
		Pomodoro * pomodoro;
		Controller * controller;
		TickOneSecond * tickOneSecond;
		BspStub * bsp;
		CircularBuffer * signals;

		virtual void SetUp() override
		{
			bsp = new BspStub();
			pomodoro = new Pomodoro(bsp, 1);
			signals = new CircularBuffer();
			controller = new Controller(pomodoro, signals, bsp);
			tickOneSecond = new TickOneSecond(controller);
		}
		virtual void TearDown() override 
		{
			delete tickOneSecond;
			delete controller;
			delete signals;
			delete pomodoro;
			delete bsp;
		}
};

TEST_F(PomodoroTest, should_no_count_because_button_no_pressed)
{
	controller->addSignal(Signals::TICK_ONE_SEC);

	controller->doIt();

	ASSERT_EQ(pomodoro->currentTime(), 0);
}

TEST_F(PomodoroTest, should_count_because_button_was_pressed)
{
	controller->addSignal(Signals::PRESSED);
	controller->doIt();

	constexpr int ticks = 10;
	for(int i = 0; i <ticks; i++){
		controller->addSignal(Signals::TICK_ONE_SEC);
		controller->doIt();
	}

	ASSERT_EQ(pomodoro->currentTime(), ticks);
}

TEST_F(PomodoroTest, should_notify_end_of_session)
{
	controller->addSignal(Signals::PRESSED);
	controller->doIt();
	pomodoro->setTime(59);

	controller->addSignal(Signals::TICK_ONE_SEC);
	controller->doIt();

	ASSERT_TRUE(bsp->buzzingCalled());
}

TEST_F(PomodoroTest, should_be_one_second_for_100_calls_of_10ms)
{
	controller->addSignal(Signals::PRESSED);
	controller->doIt();

	for(int i = 0; i<100; i++){
		tickOneSecond->callTick();
		controller->doIt();
	}

	ASSERT_EQ(pomodoro->currentTime(), 1);
}

TEST_F(PomodoroTest, should_call_standby)
{
	pomodoro->setTime(59);

	controller->addSignal(Signals::PRESSED);
	controller->doIt();
	controller->addSignal(Signals::TICK_ONE_SEC);
	controller->doIt();

	ASSERT_TRUE(bsp->standByCalled());
}

TEST_F(PomodoroTest, should_reinit_pomodoro_at_finish)
{
	controller->addSignal(Signals::PRESSED);
	controller->doIt();

	int many_time = 100000;
	for(int i = 0; i<many_time; i++){
		controller->addSignal(Signals::TICK_ONE_SEC);
		controller->doIt();
	}

	ASSERT_EQ(pomodoro->currentTime(), 0);
}

TEST_F(PomodoroTest, should_call_led_at_init)
{
	controller->addSignal(Signals::PRESSED);
	controller->doIt();

	ASSERT_TRUE(bsp->led_called());
}

TEST_F(PomodoroTest, should_call_idle_when_there_is_no_sirgnals)
{
	controller->doIt();

	ASSERT_TRUE(bsp->idle_called());
}
