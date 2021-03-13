#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H

#include <stdbool.h>

void ledController_init(short const led_pin,
			bool * const finished,
			short const * const progress);
void ledController_do();

#endif // LEDCONTROLLER_H
