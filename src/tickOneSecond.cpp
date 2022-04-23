#include "tickOneSecond.hpp"

TickOneSecond::TickOneSecond(Pomodoro * pomodoro) : pomodoro_{pomodoro}
{
}

void TickOneSecond::doit()
{
	pomodoro_->add1Second();
}
