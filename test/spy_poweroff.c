#include "spy_poweroff.h"
bool called_poweroff = false;
bool spy_poweroff_called(void)
{
	return called_poweroff;
}
void poweroff(void)
{
	called_poweroff = true;
}
