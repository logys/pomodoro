#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "action.h"
#include<stdbool.h>

void controller_init(short * const progress, bool * finished);
void controller_do(void);

#endif // CONTROLLER_H
