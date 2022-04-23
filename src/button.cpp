#include "button.hpp"

Button::Button(Pomodoro * pomodoro) : pomodoro_{pomodoro}
{
}

void Button::pressed()
{
	pomodoro_->enable();
}
