#include"pomodoro.h"
#include<stdbool.h>
#include"controller.h"
#include"presenter.h"


bool button_state;
short progress;
bool finished;

void pomodoro_init(short led_pin, short buzzer_pin,
	       	short button_pin, int session_minutes)
{
	button_state = false;
	progress = 0;
	finished = true;

	presenter_init(led_pin, buzzer_pin, button_pin, &button_state, &progress, &finished);
	controller_init(session_minutes, &progress, &button_state, &finished);
}

void pomodoro_update(void)
{
	controller_do();
	presenter_do();
}
