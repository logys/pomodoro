#ifndef SELECTOR_H
#define SELECTOR_H

#include "timer.h"

typedef enum ACTION{PLAY, PAUSE, POWEROFF}ACTION;

void selector_init(CLOCK *);
int selector_selectActionFromInput(int input);

#endif // SELECTOR_H
