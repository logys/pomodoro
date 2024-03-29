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

#ifndef POMODORO_HPP
#define POMODORO_HPP

#include <stdbool.h>
#include <stdint.h>

typedef enum {PLAY, PAUSE, POWEROFF}State;

typedef struct{
	bool button_pressed;
	State state;
	uint32_t play_time;
	uint32_t pause_time;
	uint32_t session_time;
}Pomodoro;
#ifdef __cplusplus
extern "C" {
#endif

/* State machine input states */
void pomodoro_init(int time);
void pomodoro_doIt(Pomodoro *pomodoro);
Pomodoro pomodoro_create(uint32_t time_minutes);
#ifdef __cplusplus
}
#endif

#endif// POMODORO_HPP
