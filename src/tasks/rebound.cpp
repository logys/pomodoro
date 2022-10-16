#include "rebound.hpp"
#include "hal/hal.h"

using namespace Reb;

void Rebound::doIt()
{
	bool button = button_read();
	switch(button)
	{
		case true:
			pomodoro_->edge();
			break;
	}
}

Reb::State Rebound::currentState()
{
	return State::IDLE;
}
