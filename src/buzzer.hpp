#ifndef BUZZER_HPP
#define BUZZER_HPP

#include "indicator.hpp"
#include "powerdown.hpp"

class Buzzer : public Indicator{
	public:
		Buzzer(PowerDown * power_down) : power_down_{power_down}{}
		void doit() override;
	private:
		PowerDown * power_down_;
};
#endif// BUZZER_HPP
