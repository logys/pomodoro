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
/** \file entrada.h 
 * \brief Control de el botón en entrada
/** \brief Inicia el pushbutton */
void openPush(void);
/** \brief Detiene el pushbutton */
void closePush(void);
/** \brief Retorna el estado del botón
 * \return short Estado del botón*/
typedef enum {OFF = 0, ON}PUSH_STATE;
PUSH_STATE readPush(void);
#endif
