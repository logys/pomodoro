#include "bsp.hpp"
#include "tickOneSecond.hpp"
#include "pomodoro.hpp"
#include "controller.hpp"
#include "circular_buffer.hpp"

#define VERSION 0.5.0

namespace 
{
	BSP::Bsp bsp;
	Pomodoro pomodoro(&bsp, 25);
	CircularBuffer signals;
	Controller controller(&pomodoro, &signals, &bsp);
	TickOneSecond tickOneSecond(&controller);
}

int main()
{
	BSP::bsp_input(&tickOneSecond, &controller);

	while(1){
		controller.doIt();
	}
	return 0;
}
