#include "pomodoro.hpp"
#include <cstdint>

int Pomodoro::sessionTime()
{
	return current_time_;
}

void Pomodoro::enable()
{
	enabled_ = true;
}

void Pomodoro::add1Second(void)
{
	if(enabled_)
		current_time_ += 1;
	if(current_time_ == session_time_){
		bsp_->buzzing();
		bsp_->standBy();
	}
}

void Pomodoro::setTime(std::uint16_t sec)
{
	current_time_ = sec;
}
