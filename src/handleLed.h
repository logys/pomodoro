#ifndef _HANDLELED_H
#define _HANDLELED_H
#include "timer.h"
#include "led.h"
#include <stdint.h>
#include <stdbool.h>

void initHandleLed(void);
void writeToLed(double workCicle);
void updateLed(void);

#endif // _HANDLELED_H
