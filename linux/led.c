#include "ncurses.h"
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

enum LED_STATE{LED_OFF, LED_ON};

static uint8_t led_state;
void led_init(void)
{
	initscr();
	cbreak();
	led_state = LED_OFF;
}

void led_on(void)
{
	led_state = LED_ON;
	printw("led on\n");
	refresh();
}

void led_off(void)
{
	led_state = LED_OFF;
	printw("led off\n");
	refresh();
}

void led_toggle(void)
{
	led_state ? led_off() : led_on();
}

void led_blink(void)
{
	for(int i = 0; i<10; i++){
		led_toggle();
		usleep(200000);
	}
}

void led_blink_slow(void)
{
	for(int i = 0; i<10; i++){
		led_toggle();
		usleep(500000);
	}
}
