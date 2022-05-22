#include "tickOneSecond.hpp"

void TickOneSecond::callTick()
{
	if(tick_counter_ < 99){
		tick_counter_ += 1;
	}else{
		controller_->addSignal(Signals::TICK_ONE_SEC);
		tick_counter_ = 0;
	}
}
