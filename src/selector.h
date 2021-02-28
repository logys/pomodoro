#ifndef SELECTOR_H
#define SELECTOR_H

#include "timer.h"
#include <stdbool.h>

typedef enum ACTION{PLAY, PAUSE, POWEROFF}ACTION;

void selector_init(bool *button, CLOCK *);
ACTION selector_select(void);

#endif // SELECTOR_H
