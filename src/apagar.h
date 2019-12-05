#ifndef _APAGAR_H
#define _APAGAR_H
#ifdef TEST
#include"stub_io.h"
#else
#include<avr/sleep.h>
#include<avr/io.h>
#include<avr/interrupt.h>
#endif
void apagar(void);

#endif // _APAGAR_H
