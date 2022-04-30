#include "tickOneSecond.hpp"

void TickOneSecond::callTick()
{
	if(tick_counter_ < 99){
		tick_counter_ += 1;
	}else{
		pomodoro_->add1Second();
		tick_counter_ = 0;
	}
}
