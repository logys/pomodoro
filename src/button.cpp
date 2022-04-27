#include "button.hpp"

Button::Button(IPomodoro * pomodoro) : pomodoro_{pomodoro}
{
}

void Button::press()
{
	pomodoro_->enable();
}
