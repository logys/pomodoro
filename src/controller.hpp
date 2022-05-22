#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "pomodoro.hpp"

enum class Signals {TICK_ONE_SEC, PRESSED};

class Controller {
	public:
		Controller(Pomodoro * pomodoro) : pomodoro_{pomodoro} {}
		void addSignal(Signals signal);
	private:
		Pomodoro * pomodoro_;
};

#endif// CONTROLLER_HPP
