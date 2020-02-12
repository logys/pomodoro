#ifndef DELAY_H
#define DELAY_H
#include<stdint.h>
#ifdef TEST
	#include"stub_io.h"
	#include"stub_interrupt.h"
#else
	#include<avr/io.h>
	#include<avr/interrupt.h>
#endif
/** \file delay.h */

/* Retorna el tiempo en milisegundos desde que el programa inicio*/
uint32_t millis(void);
void initTimer1Millis(void);
void reiniciarMillis(void);
#endif
