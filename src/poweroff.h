#ifndef POWEROFF_H
#define POWEROFF_H

#include <stdbool.h>

void poweroff_init(bool const * const finished);
void poweroff(void);

#endif // POWEROFF_H
