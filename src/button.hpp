#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "ipomodoro.hpp"

class Button{
	public:
		Button(IPomodoro * pomodoro);
		void press();
	private:
		IPomodoro * pomodoro_;
};
#endif// BUTTON_HPP
