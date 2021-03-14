#ifndef REBOUNDHANDLER_H
#define REBOUNDHANDLER_H

#include <stdbool.h>

void reboundHandler_init(short const button_pin, bool * const button_state);
void reboundHandler_do(void);


#endif // REBOUNDHANDLER_H
