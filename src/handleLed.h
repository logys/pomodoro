#ifndef _HANDLELED_H
#define _HANDLELED_H
#include "timer.h"
#include "led.h"
#include <stdint.h>
#include <stdbool.h>

void initHandleLed(void);
void destroyHandleLed(void);
typedef enum {READY, TOGGLING} LED_STATE;
LED_STATE updateLed(double work_cicle);
void ledOff(void);

#endif // _HANDLELED_H
