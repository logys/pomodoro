#ifndef SELECTOR_H
#define SELECTOR_H

#include "timer.h"
#include <stdbool.h>
#include "action.h"

void selector_init(bool const * const button, CLOCK *);
ACTION selector_select(void);

#endif // SELECTOR_H
