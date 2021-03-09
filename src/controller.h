#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "action.h"
#include<stdbool.h>

void controller_init(const short session_time, short * const progress,
		bool const * const button, bool * finished);
void controller_do(void);

#endif // CONTROLLER_H
