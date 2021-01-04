/*
 * Controla el parpadeo de un led, indicando el periodo,
 * entre 0-100, donde 0 equivale a 100ms y 100 equivale
 * a 16ms,
 * debe llamarse constantemente handleLed_update, se
 * asegura por lo menos un ciclo antes de ser reescrito.
 * */

#ifndef _HANDLELED_H
#define _HANDLELED_H
#include "timer.h"
#include "led.h"

void handleLed_create(void);
void handleLed_destroy(void);
void handleLed_update(double work_cicle);
void handleLed_off(void);

#endif // _HANDLELED_H
