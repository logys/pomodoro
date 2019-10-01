#include "event_input.h"

static int8_t event;
void initEventInput(void)
{
	openPush();
}

int8_t readEvent(void)
{
	static int8_t button = 0;
	button = readPush();
	if(button== 1)
	return NONE;
}
