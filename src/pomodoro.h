#ifndef POMODORO_H
#define POMODORO_H
#include<stdint.h>
#include<stdbool.h>
#include<math.h>
#include "timer.h"
#include "event_input.h"
#include "buzzer.h"
#include "handleLed.h"
#include "apagar.h"

#define MAX_SESIONES 10
/** \file pomodoro.h 
	double tiempo_acumulado;
/** Establece las sesiones y su duración
 * \param pomodoro Apuntador a pomodoro
 * \param Sesiones separadas por comas*/
#define setSesiones(...) nuevoSesion( \
		(float []){__VA_ARGS__, NAN})
void nuevoSesion(float const sesiones[]);
/** \brief actualiza la cuenta y estado del pomodoro
 * \param objeto dirección de pomodoro*/
uint8_t actualizar(void);
/** \brief Pausa sesiones 
 * \param objeto dirección de pomodoro*/
void pausa(void);
void initPomodoro(void);
#endif
