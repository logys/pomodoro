#include <ncurses.h>
#include <stdint.h>
#include <unistd.h>

enum BUZZER_STATE {BUZZER_OFF, BUZZER_ON};
static uint8_t buzzer_state;

void buzzer_init(void)
{
	buzzer_state = BUZZER_OFF;
}

void buzzer_on(void)
{
	buzzer_state = BUZZER_ON;
	printw("BUZZER on\n");
	refresh();
}

void buzzer_off(void)
{
	buzzer_state = BUZZER_OFF;
	printw("BUZZER OFF\n");
	refresh();
}

void buzzer_toggle(void)
{
	buzzer_state ? buzzer_off() : buzzer_on();
}

void buzzer_buzzing(void)
{
	for(int i = 0; i <10 ; i++){
		buzzer_toggle();
		usleep(5000000);
	}
}
