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
 * controla tres funciones inicio, pausa y apagado*/
/**Controla el evento del botón */
uint8_t botonEvent(void);
/** \brief Inicia el pushbutton */
void openPush(void);
/** \brief Detiene el pushbutton */
void closePush(void);
/** \brief Retorna el estado del botón
 * \return short Estado del botón*/
enum {OFF = 0, ON};
uint8_t readPush(void);
#endif
