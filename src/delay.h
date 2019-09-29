#ifndef DELAY_H
#define DELAY_H
#include<stdint.h>
/** \file delay.h */

/* Retorna el tiempo en milisegundos desde que el programa inicio*/
uint32_t millis(void);
void initTimer1Millis(void);
void reiniciarMillis(void);
void delay(uint32_t tiempo_ms);
/*Estructura para tiempo*/
struct timer{
	uint32_t tiempo_inicio;
	uint32_t tiempo_deseado;
};

/* Inicia el timer */
void initTimer(struct timer *tim, uint16_t tiempo_segundos);
#define PROGRESS 0
#define SUCCES 1
/* Determina si se ha alcanzado el tiempo */
uint8_t checkTimer(struct timer *tim);
#endif
