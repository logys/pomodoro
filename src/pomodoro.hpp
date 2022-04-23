#ifndef POMODORO_HPP
#define POMODORO_HPP

#include <cstdint>

class Pomodoro {
	public:
		Pomodoro();
		int sessionTime();
		void enable();
		void add1Second();
		void setTime(std::uint16_t sec);
	private:
		std::uint16_t session_time_;
		bool enabled_;
		
};
#endif// POMODORO_HPP
