#include "buzzerController.h"
#include "buzzer.h"
#include "delay.h"

static bool const * finished;

void buzzerController_init(short const buzzer_pin, bool const * const finished_injected)
{
	finished = finished_injected;
	buzzer_open(buzzer_pin);
}

void buzzerController_do(void)
{
	if(*finished){
		for(short i = 0; i<2; i++){
			buzzer_on();
			delay(300);
			buzzer_off();
			delay(200);
		}
	}
}
