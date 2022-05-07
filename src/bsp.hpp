#ifndef BSP_HPP
#define BSP_HPP

#include "tickOneSecond.hpp"
#include "hal.hpp"
#include "pomodoro.hpp"

class Bsp : public Hal{
	public:
		Bsp();
		void standBy() override;
		void buzzing() override;
	private:
		void buzzer_off();
		void buzzer_toggle();
};

void bsp_input(TickOneSecond * tick, Pomodoro * pomodoro);
void led_toggle();

#endif// BSP_HPP
