#include "spy_button.h"
short button = 0;
void button_create(Button *button, short pin)
{
}
void button_set_input_spy(short pusshed)
{
	button = pusshed;
}
short button_read(void)
{
	return button;
}
