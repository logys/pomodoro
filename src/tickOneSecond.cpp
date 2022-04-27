#include "tickOneSecond.hpp"

TickOneSecond::TickOneSecond(IPomodoro * pomodoro) : pomodoro_{pomodoro}
{
}

void TickOneSecond::callTick()
{
	if(tick_counter_ < 9){
		tick_counter_ += 1;
	}else{
		pomodoro_->add1Second();
		tick_counter_ = 0;
	}
}
