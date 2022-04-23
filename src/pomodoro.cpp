#include "pomodoro.hpp"
#include <cstdint>

Pomodoro::Pomodoro(Buzzer * buzzer, std::uint8_t time_minutes) : buzzer_{buzzer}
{
	enabled_ = false;
	current_time_ = 0;
	session_time_ = time_minutes * 60;
}
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
	if(current_time_ == session_time_)
		buzzer_->doit();
}

void Pomodoro::setTime(std::uint16_t sec)
{
	current_time_ = sec;
}
