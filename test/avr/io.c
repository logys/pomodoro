#include"stub_io.h"

uint8_t DDRB = 0;
uint8_t PORTB= 0;
uint8_t PINB= 0;
uint8_t SREG= 0;
uint8_t TCCR1= 0;
uint8_t OCR1A= 0;
uint8_t TIMSK= 0;

void push_set(short state)
{
	if(state)
		PINB &= ~(1<<PB3);
	else 
		PINB |= 1<<PB3;
}
