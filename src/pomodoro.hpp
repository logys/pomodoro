#ifndef POMODORO_HPP
#define POMODORO_HPP

#include <cstdint>
#include "hal.hpp"

class Pomodoro {
	public:
		Pomodoro(Hal * bsp, std::uint8_t time_minutes) :
			bsp_{bsp}, session_time_{(std::uint16_t)(time_minutes*60)}{}
		int sessionTime();
		void enable();
		void add1Second();
		void setTime(std::uint16_t sec);
	private:
		std::uint16_t session_time_ = 0;
		std::uint16_t current_time_ = 0;
		bool enabled_ = false;
		Hal * bsp_;
};
#endif// POMODORO_HPP
