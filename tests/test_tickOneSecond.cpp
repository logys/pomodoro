#include <gtest/gtest.h>
#include "tickOneSecond.hpp"
#include "ipomodoro.hpp"

//class tickOneSecTest : public ::testing::Test{
//};
//
class PomodoroStub : public IPomodoro{
	public:
		void add1Second(){called_second_ = true;}
		bool calledAddSecond(){return called_second_;}
		void enable() override {}
	private:
		bool called_second_ = false;
};

TEST (tickOneSecTest, should_call_pomodoro_echa_second_for_ten_ticks_of_100ms)
{
	PomodoroStub pomodoro;
	TickOneSecond tickOneSecond(&pomodoro);

	for(int i = 0; i<10; i++){
		tickOneSecond.callTick();
	}

	ASSERT_TRUE(pomodoro.calledAddSecond());
}
