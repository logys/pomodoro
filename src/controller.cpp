#include "controller.hpp"
#include "bsp.hpp"

void Controller::addSignal(Signals signal)
{
	signals_->add(signal);
}

void Controller::doIt()
{
	if(signals_->Count > 0)
		dispatch(signals_->get());
	//else
	//	BSP::idle();
}

void Controller::dispatch(Signals signal)
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
