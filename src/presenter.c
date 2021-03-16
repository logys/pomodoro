#include "presenter.h"
#include "ledController.h"
#include "buzzerController.h"
#include "reboundHandler.h"
#include "poweroff.h"

void presenter_init(short const led_pin, short const buzzer_pin, 
		short const button_pin, bool * const button_state,
		short * const progress_injected, bool * const finisehd_injected)
{
	ledController_init(led_pin, finisehd_injected, progress_injected);
	buzzerController_init(buzzer_pin, finisehd_injected);
	reboundHandler_init(button_pin, button_state);
	poweroff_init(finisehd_injected);
}

void presenter_do(void)
{
	ledController_do();
	buzzerController_do();
	reboundHandler_do();
}
