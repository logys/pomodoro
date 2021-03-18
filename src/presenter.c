#include "presenter.h"
#include "buzzerController.h"
#include "reboundHandler.h"
#include "poweroff.h"
#include "blinker.h"

void presenter_init(short const buzzer_pin, 
	 	short const button_pin, bool * const button_state,
		bool * const finisehd_injected)
{
	buzzerController_init(buzzer_pin, finisehd_injected);
	reboundHandler_init(button_pin, button_state);
	poweroff_init(finisehd_injected);
}

void presenter_do(void)
{
	blinker_do();
//	buzzerController_do();
	reboundHandler_do();
	poweroff();
}
