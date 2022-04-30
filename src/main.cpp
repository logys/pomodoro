#include "bsp.hpp"
#include "tickOneSecond.hpp"
#include "pomodoro.hpp"

int main()
{
	Bsp * bspiny = nullptr;
	Pomodoro pomodoro(bspiny, 1);
	TickOneSecond tickOneSecond(&pomodoro);
	Bsp bsp(&tickOneSecond);	
	bspiny = &bsp;

	while(1);
	return 0;
}
