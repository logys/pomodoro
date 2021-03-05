#ifndef PLAY_H
#define PLAY_H

#include "session.h"
#include "timer.h"

void play_init(CLOCK *);
void play_setSessionTime(const int minutes);
double play_do(void);

#endif // PLAY_H
