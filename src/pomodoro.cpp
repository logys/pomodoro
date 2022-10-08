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

#include "pomodoro.hpp"
#include "hal/hal.h"

using namespace Pom;
constexpr int task_period_ms = 10;

void Pomodoro::poweroff()
{
	state_ = State::PLAY;
}

void Pomodoro::doIt()
{
	switch(state_){
		case State::POWEROFF:
			standBy();
			break;
		case State::PLAY:
			current_time_ += task_period_ms;
			if(current_time_ == session_time_)
				buzzing();
			break;
	}
}

std::uint16_t Pomodoro::currentTime()
{
	return current_time_;
}

State Pomodoro::currentState()
{
	return state_;
}

void Pomodoro::setState(State state)
{
	state_ = state;
}

void Pomodoro::edge()
{
	state_ = Pom::State::PLAY;
}

void Pomodoro::setTime(uint16_t time)
{
	current_time_ = time;
}
