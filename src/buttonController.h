#ifndef BUTTONCONTROLLER_H
#define BUTTONCONTROLLER_H

#include <stdbool.h>
void buttonController_init(short const button_pin, bool * const button_state);
void buttonController_do(void);

#endif // BUTTONCONTROLLER_H
