#ifndef BLINKER_H
#define BLINKER_H

#include<stdbool.h>

void blinker_init(short const * const progress, bool const * const finished);
void blinker_do(void);

#endif // BLINKER_H
