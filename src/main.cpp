#include "bsp.hpp"
#include "tickOneSecond.hpp"
#include "pomodoro.hpp"

#define VERSION 0.1.0

int main()
{
	Bsp bsp;	
	Pomodoro pomodoro(&bsp, 1);
	TickOneSecond tickOneSecond(&pomodoro);
	bsp_input(&tickOneSecond, &pomodoro);

	while(1){
		asm("nop");
	}
	return 0;
}
