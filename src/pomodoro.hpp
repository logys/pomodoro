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

#include "hal.hpp"
#include <cstdint>

class Pomodoro {
	public:
		Pomodoro(Hal * bsp, std::uint8_t time_minutes) : bsp_{bsp}
		{
			session_time_ = time_minutes*60;
		}
		std::uint16_t currentTime();
		void enable();
		void add1Second();
		void setTime(std::uint16_t sec);
		bool reachedTime();
		void finish_session();
	private:
		volatile std::uint16_t current_time_ = 0;
		std::uint16_t session_time_;
		bool enabled_ = false;
		Hal * bsp_;
};
#endif// POMODORO_HPP
