#ifndef PRESENTER_H
#define PRESENTER_H

#include<stdbool.h>

void presenter_init(const short led_pin, const short buzzer_pin, const short button_pin,
	       bool * button, short * progress, bool * finished);
void presenter_do(void);

#endif // PRESENTER_H
