#include"selector_spy.h"
#include<stdbool.h>
#include"../../src/timer.h"
#include"../../src/action.h"

ACTION action;

void selector_init(bool const * const button)
{
	action = -1;
}

ACTION selector_select(void)
{
	return action;
}

void selector_set_action_spy(ACTION action_injected)
{
	action = action_injected;
}
