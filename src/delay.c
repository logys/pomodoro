#include "delay.h"
#include "millis.h"

void delay(uint32_t time)
{
	while(time > millis());
}
