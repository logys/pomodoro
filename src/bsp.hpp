#ifndef BSP_HPP
#define BSP_HPP

#include "tickOneSecond.hpp"
#include "hal.hpp"

class Bsp : public Hal{
	public:
		Bsp(TickOneSecond * tick){}
		void standBy(){}
		void buzzing(){}
};
#endif// BSP_HPP
