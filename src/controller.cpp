#include "controller.hpp"

void Controller::addSignal(Signals signal)
{
	queue_signals_->add(signal);
}

void Controller::doIt()
{
	if(thereIsSignals())
		dispatch();
	else
		bsp_->idle();
}

bool Controller::thereIsSignals()
{
	return queue_signals_->Count > 0;
}

void Controller::dispatch()
{
	Signals signal = queue_signals_->get();
	switch (signal) {
		case Signals::PRESSED:
			pomodoro_->enable();
			break;
		case Signals::TICK_ONE_SEC:
			pomodoro_->add1Second();
			if (pomodoro_->reachedTime()){
				pomodoro_->finish_session();
				addSignal(Signals::POWERDOWN);
			}
			break;
		case Signals::POWERDOWN:
			bsp_->standBy();
			break;
	}
}
