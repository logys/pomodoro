#ifndef MILLIS_H
#define MILLIS_H

#include<stdint.h>

void millis_init(void);
uint32_t millis(void);
void millis_reinit(void);

#endif //MILLIS_H
