#include <stdbool.h>
#include <ncurses.h>

void button_init(void)
{
	 nodelay(stdscr, TRUE);
}

bool button_pushed(void)
{
	return getch() == 'z' ? TRUE : FALSE;
}
