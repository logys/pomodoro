#include"stub_interrupt.h"
void addMillis(uint32_t time)
{
	for(uint32_t i = 0; i<time; i++){
		TIM1_COMPA_vect();
	}
}
