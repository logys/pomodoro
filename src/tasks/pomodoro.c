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
#include "hal/hal.h"

typedef enum {PLAY, PAUSE, POWEROFF}State;

static State state;
static long time;
static long session_time;

void pomodoro_init(int time_minutes)
{
	state = POWEROFF;
	time = 0;
	session_time = 60*1000UL*time_minutes;
	buzzer_init();
	button_init();
}

void pomodoro_doIt(void)
{
	switch(state){
		case PLAY:
			time += 10;
			if(time == session_time){
				state = POWEROFF;
				buzzing();
			}
			break;
		case PAUSE:
			break;
		case POWEROFF:
			standBy();
			state = PLAY;
			time = 0;
			led_blink();
			break;
		default:
			return;
	}
}

void pomodoro_pushed(void)
{
}
