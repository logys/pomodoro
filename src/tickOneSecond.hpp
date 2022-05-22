#ifndef TICKONESECOND_HPP
#define TICKONESECOND_HPP

#include "controller.hpp"
#include <cstdint>

class TickOneSecond {
	public:
		TickOneSecond(Controller * controller): controller_{controller}{}
		void callTick();
	private:
		Controller * controller_;
		std::int8_t tick_counter_ = 0;
};
#endif// TICKONESECOND_HPP
