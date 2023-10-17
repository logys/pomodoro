/*
* Pomooro simple device 
* Copyright (C) 2022 Luis Antonio Sánchez Monterde
* antonio.dgr.ink@gmail.com
* 
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 3 of the License, or (at your option) any later version.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
* 
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA 
*/

#include "pomodoro.h"
#include <stdbool.h>
#include "buzzer.h"
#include "led.h"
#include "button.h"
#include "powermode.h"

#define PAUSE_TIME 60UL*1000*5

typedef enum {PLAY, PAUSE, POWEROFF}State;

static State state;
static long time;
static long pause_time;
static long session_time;
static bool pushed;

void pomodoro_init(int time_minutes)
{
	state = POWEROFF;
	time = 0;
	pause_time = 0;
	session_time = 60*1000UL*time_minutes;
	pushed = false;
}

void pomodoro_doIt(Pomodoro *pomodoro)
{
	(void)pomodoro;
	switch(state){
		case PLAY:
			time += 10;
			if(time == session_time){
				state = POWEROFF;
				buzzer_buzzing();
			}
			else if(pushed == true)
			{
				state = PAUSE;
				led_blink_slow();
			}
			pushed = false;
			break;
		case PAUSE:
			pause_time += 10;
			if(pause_time == PAUSE_TIME){
				state = POWEROFF;
				buzzer_buzzing();
			}
			else if(pushed == true)
			{
				state = PLAY;
				led_blink();
				pause_time = 0;
			}
			pushed = false;
			break;
		case POWEROFF:
			powermode_standBy();
			if(pomodoro->button_pressed)
			{
				state = PLAY;
				time = 0;
				led_blink();

			}
			pomodoro->button_pressed = false;
			break;
		default:
			return;
	}
}

void pomodoro_pushed(void)
{
	pushed = true;
}
