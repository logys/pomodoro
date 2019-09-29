#ifndef POMODORO_H
#define POMODORO_H
#include<stdint.h>
#include<math.h>

#define MAX_SESIONES 11
/** \file pomodoro.h 
 * \brief Simplemente es un pomodoro*/
struct pomodoro{
	float sesiones[MAX_SESIONES];	/**< \brief Lista de sesiones*/
	int8_t	sesion_porcentaje;	/**< \brief Porcentaje restante*/
	int8_t	indice_sesion;	/**< \brief Porcentaje restante*/
	uint32_t tiempo_actual;
	double tiempo_acumulado;
};
/** Establece las sesiones y su duración
 * \param pomodoro Apuntador a pomodoro
 * \param Sesiones separadas por comas*/
#define setSesiones(pomodoro,...) nuevoSesion(pomodoro, \
		(float []){__VA_ARGS__, NAN})
void nuevoSesion(struct pomodoro *objeto, float const sesiones[]);
/** \brief actualiza la cuenta y estado del pomodoro
 * \param objeto dirección de pomodoro*/
uint8_t actualizar(struct pomodoro * const objeto);
/** \brief Reinicia sesiones 
 * \param objeto dirección de pomodoro*/
void reiniciar(struct pomodoro * const objeto);
/** \brief Pausa sesiones 
 * \param objeto dirección de pomodoro*/
void pausa(struct pomodoro * const objeto);
#endif
