#include "hal/led.h"
#include "hal/buzzer.h"

int main(void)
{
	led_init();
	buzzer_init();
	return 0;
}
