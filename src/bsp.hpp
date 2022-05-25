#ifndef BSP_HPP
#define BSP_HPP

#include "tickOneSecond.hpp"
#include "hal.hpp"
#include "pomodoro.hpp"
#include "controller.hpp"
#include "signals.hpp"

namespace BSP {
class Bsp : public Hal{
	public:
		Bsp();
		void standBy() override;
		void buzzing() override;
	private:
		void buzzer_off();
		void buzzer_toggle();
};

void bsp_input(TickOneSecond * tick, Controller * controller);
void led_toggle();
void idle();
}
#endif// BSP_HPP
