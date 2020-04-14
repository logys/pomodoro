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

uint32_t millis(void);
void millis_init(void);
void millis_destroy(void);
#endif
