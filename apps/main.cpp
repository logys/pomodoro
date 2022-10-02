#include "bsp.hpp"
#include "tickOneSecond.hpp"
#include "pomodoro.hpp"
#include "controller.hpp"
#include "circular_buffer.hpp"

#define VERSION 0.6.0

namespace 
{
	Pomodoro pomodoro(25);
	CircularBuffer signals;
	Controller controller(&pomodoro, &signals);
	TickOneSecond tickOneSecond(&controller);
}

int main()
{
	BSP::bsp_input(&tickOneSecond, &controller);
	controller.addSignal(Signals::POWERDOWN);

	while(1){
		controller.doIt();
	}
	return 0;
}
