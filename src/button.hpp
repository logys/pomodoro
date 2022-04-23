#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "pomodoro.hpp"

class Button{
	public:
		Button(Pomodoro * pomodoro);
		void pressed();
	private:
		Pomodoro * pomodoro_;
};
#endif// BUTTON_HPP
