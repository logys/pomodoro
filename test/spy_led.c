#include"spy_led.h"
static double wc = 0;
double spy_ledWrited(void)
{
	return wc;
}
void handleLed_update(double work_cicle)
{
	wc = work_cicle;
}
void handleLed_create(void)
{
}
