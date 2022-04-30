#include "bsp.hpp"
#include "tickOneSecond.hpp"
#include "pomodoro.hpp"
#include "buzzer.hpp"

int main()
{
	Buzzer buzzer(nullptr);
	Pomodoro pomodoro(&buzzer, 1);
	TickOneSecond tickOneSecond(&pomodoro);
	Bsp bsp(&tickOneSecond);	

	while(1);
	return 0;
}
