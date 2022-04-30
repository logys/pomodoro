#ifndef TICKONESECOND_HPP
#define TICKONESECOND_HPP

#include "pomodoro.hpp"
#include <cstdint>

class TickOneSecond {
	public:
		TickOneSecond(Pomodoro * pomodoro): pomodoro_{pomodoro}{}
		void callTick();
	private:
		Pomodoro * pomodoro_;
		std::int8_t tick_counter_ = 0;
};
#endif// TICKONESECOND_HPP
