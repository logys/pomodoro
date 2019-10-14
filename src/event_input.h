#ifndef _EVENT_INPUT_H
#define _EVENT_INPUT_H
#include "entrada.h"
#include "timer.h"
#include <stdint.h>

enum {NONE = 0, PLAY_PAUSE, POWEROFF};
void initEventInput(void);
int8_t readEvent(void);

#endif // _EVENT_INPUT_H
