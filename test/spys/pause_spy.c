#include "pause_spy.h"

bool pause_do_called = false;

bool pause_do_spy(void)
{
	return pause_do_called;
}

short pause_do(void)
{
	pause_do_called = true;
	return 80;
}
