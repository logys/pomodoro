#include "controller.hpp"

void Controller::addSignal(Signals signal)
{
	switch (signal) {
		case Signals::PRESSED:
			pomodoro_->enable();
			break;
		case Signals::TICK_ONE_SEC:
			pomodoro_->add1Second();
			break;
	}
}
