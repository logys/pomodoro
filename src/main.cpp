#include "bsp.hpp"
#include "tickOneSecond.hpp"
#include "pomodoro.hpp"

#define VERSION 0.2.0

namespace 
{
	BSP::Bsp bsp;
	Pomodoro pomodoro(&bsp, 25);
	TickOneSecond tickOneSecond(&pomodoro);
}

int main()
{
	BSP::bsp_input(&tickOneSecond, &pomodoro);

	while(1){
		asm("nop");
	}
	return 0;
}
