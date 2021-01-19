#include "input.h"
static Pomodoro *pomodoro;
void input_init(Button *button, Pomodoro* pom)
{
	pomodoro = pom;
}
void input_update(void)
{
	pomodoro->input = button_read();
}
