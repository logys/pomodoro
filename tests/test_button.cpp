#include <gtest/gtest.h>
#include "button.hpp"
#include "ipomodoro.hpp"

class PomodoroStub : public IPomodoro{
	public:
		virtual void add1Second()override{}
		void enable(){ called_ = true;}
		bool enabled() {return called_;}
	private:
		bool called_ = false;
};

class ButtonTest : public ::testing::Test {
	protected:
		PomodoroStub * pomodoro;
		Button * button;

		virtual void SetUp() override
		{
			pomodoro = new PomodoroStub();
			button = new Button(pomodoro);
		}
		virtual void TearDown() override 
		{
			delete button;
			delete pomodoro;
		}
};

TEST_F(ButtonTest, should_call_enable_pomodoro_on_press)
{
	button->press();

	ASSERT_TRUE(pomodoro->enabled());
}
