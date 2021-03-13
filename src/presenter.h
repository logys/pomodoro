#ifndef PRESENTER_H
#define PRESENTER_H

#include<stdbool.h>

void presenter_init(const short led_pin, const short buzzer_pin, 
		const short button_pin,
	       bool * const button_state, short * const progress, 
	       bool * const finished);
void presenter_do(void);

#endif // PRESENTER_H
