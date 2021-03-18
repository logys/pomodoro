#include "pomodoro.h"
#include <stdbool.h>
#include "controller.h"
#include "presenter.h"
#include "blinker.h"
#include "led.h"
#include "buzzer.h"
#include "button.h"


static bool button_state;
static short progress;
static bool finished;

void pomodoro_init(short led_pin, short buzzer_pin,
	       	short button_pin, int session_minutes)
{
	button_state = false;
	progress = 0;
	finished = true;

	//controller_init(session_minutes, &progress, &button_state, &finished);
	presenter_init(buzzer_pin, button_pin, &button_state, &finished);
	led_open(led_pin);
	buzzer_open(buzzer_pin);
	button_open(button_pin);
	blinker_init(&progress);
}

void pomodoro_update(void)
{
//	controller_do();
	presenter_do();
}

void pomodoro_reinit(void)
{
	progress = 100;
	finished = false;
}
