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
#include <cstdint>
#include "bsp.hpp"

std::uint16_t Pomodoro::currentTime()
{
	return current_time_;
}

void Pomodoro::enable()
{
	if(!enabled_){
		enabled_ = true;
		bsp_->led_play();
	}
}

void Pomodoro::add1Second(void)
{
	if(enabled_){
		current_time_++;
	}
}

bool Pomodoro::reachedTime()
{
	return currentTime() == session_time_;
}

void Pomodoro::setTime(std::uint16_t sec)
{
	current_time_ = sec;
}

void Pomodoro::finish_session()
{
	bsp_->buzzing();
	enabled_ = false;
	setTime(0);
}
