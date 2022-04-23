#ifndef POMODORO_HPP
#define POMODORO_HPP

#include <cstdint>
#include "buzzer.hpp"

class Pomodoro {
	public:
		Pomodoro(Buzzer * buzzer, std::uint8_t time_minutes);
		int sessionTime();
		void enable();
		void add1Second();
		void setTime(std::uint16_t sec);
	private:
		std::uint16_t session_time_;
		std::uint16_t current_time_;
		bool enabled_;
		Buzzer * buzzer_;
};
#endif// POMODORO_HPP
