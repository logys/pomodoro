/*
 * =====================================================================================
 *
 *       Filename:  stub_iom328p.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/07/19 19:30:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Luis Antonio Sánchez Monterde (logy), antonio.dgr.ink@gmail.com
 *   Organization:  eleckia
 *
 * =====================================================================================
 */
#ifndef _AVR_IOM328P_H_
#define _AVR_IOM328P_H_ 1

#include<stdint.h>

uint8_t DDRB;
uint8_t PORTB;
uint8_t PINB;
#define PB0 0
#define PB1 1
#define PB2 2
#define PB3 3
#define PB4 4
#define PB5 5
#define PB6 6
#define PB7 7

uint8_t DDRD;
uint8_t PORTD;
#define PD0 0
#define PD1 1
#define PD2 2
#define PD3 3
#define PD4 4
#define PD5 5
#define PD6 6
#define PD7 7

uint8_t TCCR0A;
#define WGM00 0
#define WGM01 1
#define COM0B0 4
#define COM0B1 5
#define COM0A0 6
#define COM0A1 7

uint8_t TCCR0B;
#define CS00 0
#define CS01 1
#define CS02 2
#define WGM02 3

uint8_t OCR0A;
uint8_t OCR0B;
uint8_t TCCR1A;
#define WGM10 0
#define WGM11 1
uint8_t TCCR1B;
#define WGM12 3
#define WGM13 4
uint8_t TCCR2A;
#define WGM20 0
#define WGM21 1
uint8_t TCCR2B;
#define WGM22 3

uint8_t SREG;

uint8_t TCNT1;
uint8_t TCCR1;
#define CS10 0
#define CS11 1
#define CS12 2

uint8_t OCR1A;

uint8_t TIMSK;
#define OCIE1A 6

uint8_t GIMSK;
uint8_t PCMSK;
uint8_t PCIE;

#define PCINT0 0
#define PCINT3 3

#endif // _AVR_IOM328P_H_
