#include "pomodoro.hpp"

Pomodoro::Pomodoro()
{
	enabled_ = false;
	session_time_ = 0;
}
int Pomodoro::sessionTime()
{
	return session_time_;
}

void Pomodoro::enable()
{
	enabled_ = true;
}

void Pomodoro::add1Second(void)
{
	if(enabled_)
		session_time_ += 1;
}

void Pomodoro::setTime(std::uint16_t sec)
{
	session_time_ = sec;
}
