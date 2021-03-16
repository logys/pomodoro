#ifndef PAUSE_H
#define PAUSE_H

#include <stdbool.h>

void pause_init(short * const progress, bool * const finished);
void pause_do(void);

#endif // PAUSE_H
