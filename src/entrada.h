/*
 * =====================================================================================
 *
 *       Filename:  entrada.h
 *
 *    Description:  Manejo del estado del botón de entrada
 *
 *        Version:  1.0
 *        Created:  20/03/19 22:38:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Luis Antonio Sánchez Monterde (logy), antonio.dgr.ink@gmail.com
 *   Organization:  eleckia
 *
 * =====================================================================================
 */
#ifndef _ENTRADA_H
#define _ENTRADA_H
#include "timer.h"
void openPush(void);
void closePush(void);
typedef enum {OFF = 0, ON}PUSH_STATE;
PUSH_STATE readPush(void);
#endif
