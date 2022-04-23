#ifndef TICKONESECOND_HPP
#define TICKONESECOND_HPP

#include "pomodoro.hpp"

class TickOneSecond {
	public:
		TickOneSecond(Pomodoro * pomodoro);
		void doit();
	private:
		Pomodoro * pomodoro_;
};
#endif// TICKONESECOND_HPP
