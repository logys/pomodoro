#ifndef POMODORO_HPP
#define POMODORO_HPP

#include <cstdint>
#include "indicator.hpp"
#include "ipomodoro.hpp"

class Pomodoro : public IPomodoro {
	public:
		Pomodoro(Indicator * buzzer, std::uint8_t time_minutes);
		int sessionTime();
		void enable();
		virtual void add1Second() override;
		void setTime(std::uint16_t sec);
	private:
		std::uint16_t session_time_;
		std::uint16_t current_time_;
		bool enabled_;
		Indicator * buzzer_;
};
#endif// POMODORO_HPP
