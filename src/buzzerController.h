#ifndef BUZZERCONTROLLER_H
#define BUZZERCONTROLLER_H

#include <stdbool.h>

void buzzerController_init(short const buzzer_pin, bool const * const finished);
void buzzerController_do(void);

#endif // BUZZERCONTROLLER_H
