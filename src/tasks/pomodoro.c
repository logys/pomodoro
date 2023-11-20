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
#include "tick.h"

#define PAUSE_TIME 60UL*1000*5

void pomodoro_doIt(Pomodoro *pomodoro)
{
	bool pressed = pomodoro->button_pressed;
	switch(pomodoro->state){
		case PLAY:
			pomodoro->play_time += TICK_MS;
			if(pomodoro->play_time == pomodoro->session_time){
				pomodoro->state = POWEROFF;
				buzzer_buzzing();
			}
			else if(pressed)
			{
				pomodoro->state = PAUSE;
				led_blink_slow();
			}
			break;
		case PAUSE:
			pomodoro->pause_time += TICK_MS;
			if(pomodoro->pause_time == PAUSE_TIME){
				pomodoro->state = POWEROFF;
				buzzer_buzzing();
			}
			else if(pressed)
			{
				pomodoro->state = PLAY;
				led_blink();
				pomodoro->pause_time = 0;
			}
			break;
		case POWEROFF:
			powermode_standBy();
			if(pressed)
			{
				pomodoro->state = PLAY;
				pomodoro->play_time = 0;
				led_blink();
			}
			break;
	}
	pomodoro->button_pressed = false;
}

Pomodoro pomodoro_create(uint32_t time_minutes)
{
	return (Pomodoro){.session_time = (uint32_t)60*(uint32_t)1000*time_minutes,
			.state = POWEROFF
	};
}
