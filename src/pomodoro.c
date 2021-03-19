#include "pomodoro.h"
#include <stdbool.h>
#include "controller.h"
#include "blinker.h"
#include "led.h"
#include "buzzer.h"
#include "button.h"
#include "buzzerController.h"
#include "reboundHandler.h"
#include "poweroff.h"
#include "selector.h"
#include "play.h"

static bool button_state;
static short progress;
static bool finished;

void pomodoro_init(short led_pin, short buzzer_pin,
	       	short button_pin, int session_minutes)
{
	button_state = false;
	progress = 0;
	finished = true;

	led_open(led_pin);
	buzzer_open(buzzer_pin);
	button_open(button_pin);

	blinker_init(&progress);
	buzzerController_init(buzzer_pin, &finished);
	reboundHandler_init(button_pin, &button_state);
	poweroff_init(&finished);

	controller_init(&progress, &finished);
	selector_init(&button_state);
	play_init(session_minutes);
}

void pomodoro_update(void)
{
	controller_do();

	blinker_do();
	buzzerController_do();
	reboundHandler_do();
	poweroff();
}

void pomodoro_reinit(void)
{
	progress = 0;
	finished = false;
}
