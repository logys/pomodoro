#ifndef DELAY_H
#define DELAY_H
#include<stdint.h>
/** \file delay.h */

/* Retorna el tiempo en milisegundos desde que el programa inicio*/
uint32_t millis(void);
void initTimer1Millis(void);
void reiniciarMillis(void);
#endif
