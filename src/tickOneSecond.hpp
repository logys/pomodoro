#ifndef TICKONESECOND_HPP
#define TICKONESECOND_HPP

#include "ipomodoro.hpp"
#include <cstdint>

class TickOneSecond {
	public:
		TickOneSecond(IPomodoro * pomodoro);
		void callTick();
	private:
		IPomodoro * pomodoro_;
		std::int8_t tick_counter_ = 0;
};
#endif// TICKONESECOND_HPP
