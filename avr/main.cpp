#include "bsp.hpp"
#include "tickOneSecond.hpp"
#include "pomodoro.hpp"
#include "controller.hpp"
#include "circular_buffer.hpp"

#define VERSION 0.6.0

namespace 
{
	Pomodoro pomodoro(25);
}

int main()
{
	while(1){
		pomodoro.doIt();
	}
	return 0;
}
