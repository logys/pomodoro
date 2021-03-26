#include "delay.h"
#include "millis.h"

void delay(uint32_t time)
{
	uint32_t current_time = millis();
	while(time >= (millis()-current_time))
		__asm__("NOP");
}
